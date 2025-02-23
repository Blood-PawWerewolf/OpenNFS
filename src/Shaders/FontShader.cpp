#include "FontShader.h"

namespace OpenNFS {
    const std::string vertexSrc = "../shaders/FontVertexShader.vert";
    const std::string fragSrc = "../shaders/FontFragmentShader.frag";

    FontShader::FontShader() : BaseShader(vertexSrc, fragSrc) {
        FontShader::bindAttributes();
        FontShader::getAllUniformLocations();
    }

    void FontShader::bindAttributes() {
        bindAttribute(0, "vertexPosition_modelspace");
    }

    void FontShader::getAllUniformLocations() {
        // Get handles for uniforms
        projectionMatrixLocation = getUniformLocation("projectionMatrix");
        layerLocation = getUniformLocation("layer");
        colourLocation = getUniformLocation("textColour");
        textGlyphSamplerLocation = getUniformLocation("textGlyphSampler");
    }

    void FontShader::loadProjectionMatrix(const glm::mat4 &projection) {
        loadMat4(projectionMatrixLocation, &projection[0][0]);
    }

    void FontShader::loadLayer(const GLint layer) {
        loadFloat(layerLocation, layer == 0 ? -0.999f : (float) (layer - 100) / 100);
    }

    void FontShader::loadColour(const glm::vec3 colour) {
        loadVec3(colourLocation, colour);
    }

    void FontShader::loadGlyphTexture(const GLuint textureID) {
        loadSampler2D(textGlyphSamplerLocation, 0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureID);
    }

    void FontShader::customCleanup() {
    }
}
