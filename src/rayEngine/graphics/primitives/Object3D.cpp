#include "Object3D.h"
#include <iostream>

Object3D::Object3D()
    : position(0.0f), rotation(0.0f), scale(1.0f), parent(nullptr)
{
}

Object3D::~Object3D() {
    for (auto child : children)
        delete child;
}

void Object3D::AddChild(Object3D* child) {
    child->parent = this;
    children.push_back(child);
}

glm::mat4 Object3D::GetLocalMatrix() const {
    glm::mat4 mat = glm::translate(glm::mat4(1.0f), position);
    mat = glm::rotate(mat, glm::radians(rotation.x), glm::vec3(1, 0, 0));
    mat = glm::rotate(mat, glm::radians(rotation.y), glm::vec3(0, 1, 0));
    mat = glm::rotate(mat, glm::radians(rotation.z), glm::vec3(0, 0, 1));
    mat = glm::scale(mat, scale);
    return mat;
}

glm::mat4 Object3D::GetWorldMatrix() const {
    if (parent)
        return parent->GetWorldMatrix() * GetLocalMatrix();
    return GetLocalMatrix();
}

void Object3D::Draw() {
    //std::cout << "Draw Object 3D" << std::endl;
    for (auto child : children)
        child->Draw();
}
