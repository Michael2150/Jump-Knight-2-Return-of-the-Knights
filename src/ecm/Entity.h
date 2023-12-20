//
// Created by micha on 26/11/2023.
//

#ifndef CA3_ENTITY_H
#define CA3_ENTITY_H

#include "vector"
#include <memory>
#include <string>
#include "SFML/System/Vector2.hpp"

#include "Entity.h"
#include "Component.h"
#include "Transform.h"
#include "SFML/Graphics/RenderWindow.hpp"

class Component; // Forward declaration

using namespace std;

class Entity {
private:
    vector<shared_ptr<Component>> components;
    bool active = true;

protected:
    shared_ptr<Transform_Component> transform;

public:
    explicit Entity() {
        components = vector<shared_ptr<Component>>();
        transform = CreateComponent<Transform_Component>();
    };

    virtual void Start();
    virtual void Update(float deltaTime);
    virtual void Render(sf::RenderWindow* window);

    void setActive(bool isActive) { active = isActive; }

    template <class T, typename... Args>
    shared_ptr<T> CreateComponent(Args&&... args) {
        static_assert(std::is_base_of<Component, T>::value, "T must be of type Component or derived from Component");

        shared_ptr<T> component = make_shared<T>(std::forward<Args>(args)...);
        component->setParent(this);
        components.push_back(component);
        return component;
    }
    std::vector<shared_ptr<Component>> getComponents() { return components; }

    template <class T>
    shared_ptr<T> getComponent() {
        static_assert(std::is_base_of<Component, T>::value, "T must be of type Component or derived from Component");

        for (auto component : components) {
            if (dynamic_pointer_cast<T>(component)) {
                return dynamic_pointer_cast<T>(component);
            }
        }
        return nullptr;
    }

    shared_ptr<Transform_Component> getTransform() { return transform; }
};


#endif //CA3_ENTITY_H
