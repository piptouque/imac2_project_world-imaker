#include "glimac/TrackballCamera.hpp"

namespace glimac {
    TrackballCamera::TrackballCamera(const float fDistance, const float fAngleX, const float fAngleY) :
            m_fDistance(fDistance), m_fAngleX(fAngleX), m_fAngleY(fAngleY) {};

    void TrackballCamera::moveFront(const float delta) {
        m_fDistance += delta;
    }

    void TrackballCamera::rotateLeft(const float degrees) {
        m_fAngleX += degrees;
    }

    void TrackballCamera::rotateUp(const float degrees) {
        m_fAngleY += degrees;
    }

    glm::mat4 TrackballCamera::getViewMatrix(void) const {
        glm::mat4 viewMatrix = glm::translate(
                glm::mat4(1.f),
                glm::vec3(0.f, 0.f, -m_fDistance)
        );

        viewMatrix *= glm::rotate(
                glm::mat4(1.f),
                glm::radians(-m_fAngleX),
                glm::vec3(1.f, 0.f, 0.f)
        );

        viewMatrix *= glm::rotate(
                glm::mat4(1.f),
                glm::radians(-m_fAngleY),
                glm::vec3(0.f, 1.f, 0.f)
        );

        return viewMatrix;
    }

}