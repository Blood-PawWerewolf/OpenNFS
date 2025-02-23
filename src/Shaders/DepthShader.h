#pragma once

#include "BaseShader.h"
#include "../Util/Utils.h"

namespace OpenNFS {
    class DepthShader : public BaseShader {
    public:
        DepthShader();

        void loadLightSpaceMatrix(const glm::mat4 &lightSpaceMatrix);

        void loadTransformMatrix(const glm::mat4 &transformationMatrix);

        void bindTextureArray(GLuint textureArrayID) const;

    protected:
        void bindAttributes() override;

        void getAllUniformLocations() override;

        void customCleanup() override;

        GLint lightSpaceMatrixLocation;
        GLint transformationMatrixLocation;
        GLint textureArrayLocation;
    };
}
