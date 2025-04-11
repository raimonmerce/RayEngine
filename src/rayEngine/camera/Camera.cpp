#include "Camera.h"

namespace Engine {

    Camera::Camera()
        : m_Position(0.0f, 0.0f, 3.0f), m_Target(0.0f, 0.0f, 0.0f) {
        UpdateMatrices();
    }

    Camera::Camera(const glm::vec3& position, const glm::vec3& target, float fov, float aspect, float nearPlane, float farPlane)
        : m_Position(position), m_Target(target) {
        SetPerspective(fov, aspect, nearPlane, farPlane);
        UpdateViewMatrix();
    }

    void Camera::SetPerspective(float fov, float aspect, float nearPlane, float farPlane) {
        m_ProjectionMatrix = glm::perspective(glm::radians(fov), aspect, nearPlane, farPlane);
    }

    void Camera::SetPosition(const glm::vec3& position) {
        m_Position = position;
        UpdateViewMatrix();
    }

    void Camera::SetTarget(const glm::vec3& target) {
        m_Target = target;
        UpdateViewMatrix();
    }

    void Camera::Move(const glm::vec3& offset) {
        m_Position += offset;
        m_Target += offset;
        UpdateViewMatrix();
    }

    void Camera::UpdateViewMatrix() {
        m_ViewMatrix = glm::lookAt(m_Position, m_Target, glm::vec3(0.0f, 1.0f, 0.0f));
    }

    void Camera::UpdateMatrices() {
        UpdateViewMatrix();
        // Projection might be static unless FOV/aspect changes
    }

    const glm::mat4& Camera::GetViewMatrix() const {
        return m_ViewMatrix;
    }

    const glm::mat4& Camera::GetProjectionMatrix() const {
        return m_ProjectionMatrix;
    }

}
