#ifndef OBJECT3D_H
#define OBJECT3D_H

#include <vector>
#include "../src/rayEngine/libs/glm/glm.hpp"
#include "../src/rayEngine/libs/glm/gtc/matrix_transform.hpp"

class Object3D {
public:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    
    Object3D* parent;
    std::vector<Object3D*> children;
    
    Object3D();
    virtual ~Object3D();
    
    void AddChild(Object3D* child);
    
    glm::mat4 GetLocalMatrix() const;
    glm::mat4 GetWorldMatrix() const;
    
    virtual void Draw();
};

#endif // OBJECT3D_H
