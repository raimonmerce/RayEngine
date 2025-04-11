#ifndef CAMERA_H
#define CAMERA_H

#include "../src/rayEngine/libs/glm/glm.hpp"
#include "../src/rayEngine/libs/glm/gtc/matrix_transform.hpp"

namespace Engine {
    class Camera {
    public:
        Camera();
        Camera(const glm::vec3& position, const glm::vec3& target, float fov, float aspect, float nearPlane, float farPlane);

        void SetPerspective(float fov, float aspect, float nearPlane, float farPlane);
        void SetPosition(const glm::vec3& position);
        void SetTarget(const glm::vec3& target);
        void Move(const glm::vec3& offset);
        void UpdateViewMatrix();

        const glm::mat4& GetViewMatrix() const;
        const glm::mat4& GetProjectionMatrix() const;

    private:
        glm::vec3 m_Position;
        glm::vec3 m_Target;

        glm::mat4 m_ViewMatrix;
        glm::mat4 m_ProjectionMatrix;

        void UpdateMatrices();
    };
}

#endif