//
// Created by micha on 26/11/2023.
//

#ifndef CA3_COMPONENT_H
#define CA3_COMPONENT_H


class Component {
public:
    virtual void Start();
    virtual void Update(float deltaTime);
    virtual void Render();
};


#endif //CA3_COMPONENT_H
