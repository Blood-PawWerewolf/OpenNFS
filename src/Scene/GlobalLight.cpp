#include "glm/gtx/quaternion.hpp"
#include "GlobalLight.h"

GlobalLight::GlobalLight(const glm::vec3 lookAt, const glm::vec3 position) : BaseLight(0, 0, LightType::GLOBAL_LIGHT, position, glm::vec4(0, 0, 0, 0)) {
    this->ChangeTarget(lookAt);
    this->Update(0.f);
}

void GlobalLight::ChangeTarget(const glm::vec3 lookAt) {
    m_lookAt = lookAt;
}

void GlobalLight::Update(const float timeScaleFactor) {
    position         = position * glm::normalize(glm::quat(glm::vec3(timeScaleFactor * RADIANS_PER_TICK, 0, 0)));
    viewMatrix       = glm::lookAt(position, m_lookAt, glm::vec3(0, 1.0, 0));
    lightSpaceMatrix = m_lightProjection * viewMatrix;
}
