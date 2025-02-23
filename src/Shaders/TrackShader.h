#pragma once

#include "BaseShader.h"
#include <glm/detail/type_mat4x4.hpp>
#include <map>
#include <Entities/BaseLight.h>

#include "../Scene/Spotlight.h"
#include "../../shaders/ShaderPreamble.h"

namespace OpenNFS {
    class TrackShader : public BaseShader {
    public:
        TrackShader();
        void bindTextureArray(GLuint textureArrayID) const;
        void loadProjectionViewMatrices(const glm::mat4 &projection,
                                        const glm::mat4 &view); // These don't change between Shader binds, better to set state once for a track render pass
        void loadTransformMatrix(const glm::mat4 &transformation);
        void loadLightSpaceMatrix(const glm::mat4 &lightSpaceMatrix);
        void loadSpecular(float damper, float reflectivity);
        void loadLights(const std::vector<const LibOpenNFS::BaseLight*> &lights);
        void loadSpotlight(const Spotlight &spotlight);
        void loadShadowMapTexture(GLuint shadowMapTextureID);
        void loadAmbientFactor(float ambientFactor);
        void setClassic(bool useClassic);

    protected:
        void bindAttributes() override;
        void getAllUniformLocations() override;
        void customCleanup() override;
        GLint transformationMatrixLocation;
        GLint projectionMatrixLocation;
        GLint viewMatrixLocation;
        GLint lightSpaceMatrixLocation;
        GLint lightPositionLocation[MAX_TRACK_CONTRIB_LIGHTS];
        GLint lightColourLocation[MAX_TRACK_CONTRIB_LIGHTS];
        GLint attenuationLocation[MAX_TRACK_CONTRIB_LIGHTS];
        GLint spotlightPositionLocation;
        GLint spotlightColourLocation;
        GLint spotlightDirectionLocation;
        GLint spotlightCutOffLocation;
        GLint shineDamperLocation;
        GLint reflectivityLocation;
        GLint useClassicLocation;
        GLint shadowMapTextureLocation;
        GLint ambientFactorLocation;
        GLint trackTextureArrayLocation;
    };
} // namespace OpenNFS
