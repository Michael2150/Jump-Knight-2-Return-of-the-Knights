//
// Created by micha on 30/11/2023.
//

#ifndef CA3_SCENE_H
#define CA3_SCENE_H

#include "../ecm/Entity.h"
#include "Box2D/Dynamics/b2World.h"
#include "../engine/PhysicsEngine.h"

//class Entity; // Forward declaration

class Scene : public Entity {
private:
    vector<shared_ptr<Entity>> entities;
    bool b_started = false;
    shared_ptr<b2World> world;

public:
    explicit Scene();

    // Must be overridden by derived classes
    // This is where all entities should be created
    virtual void Initialize() = 0;

    void Start() override;

    void Update(float deltaTime) override;

    void Render(sf::RenderWindow *window) override;

    b2World* getWorld() {
        if (world == nullptr) {
            world = PhysicsEngine::CreateWorld();
        }
        return world.get();
    }

    bool HasStarted() const { return b_started; }

    template <class T, typename... Args>
    shared_ptr<T> CreateEntity(Args&&... args) {
        static_assert(std::is_base_of<Entity, T>::value, "T must be of type Entity or derived from Entity");

        shared_ptr<T> entity = make_shared<T>(std::forward<Args>(args)...);
        entities.push_back(entity);
        return entity;
    }

    void RemoveEntity(Entity* entity) {
        entities.erase(std::remove_if(entities.begin(), entities.end(), [entity](shared_ptr<Entity> e) { return e.get() == entity; }), entities.end());
    }
};


#endif //CA3_SCENE_H
