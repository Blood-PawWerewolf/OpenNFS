#pragma once

#include "../Camera/BaseCamera.h"
#include "../Scene/GlobalLight.h"
#include "../Scene/Track.h"
#include "../Shaders/SkydomeShader.h"
#include "../Util/ImageLoader.h"
#include "Models/GLCarModel.h"

namespace OpenNFS {
    class SkyRenderer {
    public:
        explicit SkyRenderer();
        ~SkyRenderer();
        void Render(const BaseCamera &camera, const GlobalLight* light, float elapsedTime);

    private:
        // Load cloud, sun, moon and tint textures
        void _LoadAssets();
        SkydomeShader m_skydomeShader;
        // Sphere model for skydome
        LibOpenNFS::CarGeometry m_skydomeGeom;
        GLCarModel m_skydomeModel;
        GLuint clouds1TextureID = 0, clouds2TextureID = 0, sunTextureID = 0, moonTextureID = 0, tintTextureID = 0, tint2TextureID = 0;
    };
} // namespace OpenNFS
