//
// Created by Amrik Sadhra on 16/10/2018.
//

#pragma once

#include "BaseShader.h"
#include "../Util/Utils.h"
#include "../Scene/Light.h"

class DepthShader : public BaseShader {
public:
    DepthShader();
    void loadLightSpaceMatrix(const glm::mat4 &lightSpaceMatrix);
    void loadTransformMatrix(const glm::mat4 &transformationMatrix);

protected:
    void bindAttributes() override;
    void getAllUniformLocations() override;
    void customCleanup() override;

    GLint lightSpaceMatrixLocation;
    GLint transformationMatrixLocation;

    typedef BaseShader super;
};

