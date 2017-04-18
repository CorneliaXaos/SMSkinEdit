#include <string>
#include <vector>

#if defined(__APPLE__)
    #include <OpenGL/gl3.h> // defines OpenGL 3.0+ functions
#else
    #if defined(WIN32)
        #define GLEW_STATIC 1
    #endif
    #include <GL/glew.h>
#endif
#include <FL/gl.h>
#include "cyGL.h"
#include "gui/GLCommon.h"
#include "lodepng.h"

#include "gl/textures.h"

// This shouldn't be copied like this...
// I.e. : TODO : CENTRALIZE
static const char* FILES[] = {
    "skin_main_diff.png",
    "skin_main_em.png",
    "skin_helmet_diff.png",
    "skin_helmet_em.png"
};
static const int FILE_COUNT = 4;
static const int BODY_DIM = 256;
static const int HELM_DIM = 128;

static const char* BODY_TEMPLATE =
        "SMSkinEdit_Data/Textures/template/playertex_template.png";
static const char* HELM_TEMPLATE =
        "SMSkinEdit_Data/Textures/template/playerhelm_template.png";

namespace smskinedit {
    namespace gl {

        namespace textures {

            cy::GLRenderTexture<GL_TEXTURE_2D> bodyDiffuse {};
            cy::GLRenderTexture<GL_TEXTURE_2D> bodyEmissive {};
            cy::GLRenderTexture<GL_TEXTURE_2D> helmDiffuse {};
            cy::GLRenderTexture<GL_TEXTURE_2D> helmEmissive {};
            cy::GLRenderTexture<GL_TEXTURE_2D> bodyTemplate {};
            cy::GLRenderTexture<GL_TEXTURE_2D> helmTemplate {};

            bool texturesReady() {
                return !bodyDiffuse.IsNull() &&
                    !bodyEmissive.IsNull() &&
                    !helmDiffuse.IsNull() &&
                    !helmEmissive.IsNull();
            }

            struct ImageData {
                std::vector<unsigned char> image {};
                unsigned int width = 0U, height = 0U;
            };
            static void loadOnceTextures();
            bool loadTextures(std::string path) {
                loadOnceTextures();

                // Load the image data!
                ImageData data[FILE_COUNT];
                for (int i = 0; i < FILE_COUNT; i++) {
                    std::string filePath = path + "/" + FILES[i];
                    unsigned int error = lodepng::decode(data[i].image,
                            data[i].width, data[i].height, filePath.data());
                    if (error) {
                        return false; // we couldn't load the images!
                    }
                }

                // Verify the ImageData dims are correct
                if (
                    data[0].width != data[0].height &&
                    data[0].width != BODY_DIM &&
                    data[1].width != data[1].height &&
                    data[1].width != BODY_DIM &&
                    data[2].width != data[2].height &&
                    data[2].width != HELM_DIM &&
                    data[3].width != data[3].height &&
                    data[3].width != HELM_DIM
                ) {
                    return false; // bad image data!
                }

                // Bind the context!
                if (!smskinedit::gui::activateContext()) {
                    return false; // we can't get an opengl context!! D:
                }

                // Reset RenderBuffers as we can proceed
                bool success = true;
                success = success &&
                        bodyDiffuse.Initialize(false, 4, BODY_DIM, BODY_DIM);
                success = success &&
                        bodyEmissive.Initialize(false, 4, BODY_DIM, BODY_DIM);
                success = success &&
                        helmDiffuse.Initialize(false, 4, HELM_DIM, HELM_DIM);
                success = success &&
                        helmEmissive.Initialize(false, 4, HELM_DIM, HELM_DIM);
                if (!success) {
                    bodyDiffuse.Delete();
                    bodyEmissive.Delete();
                    helmDiffuse.Delete();
                    helmEmissive.Delete();
                    return false;
                }

                //// Finally, load image data into the RenderBuffers
                // Body Diffuse
                bodyDiffuse.SetTextureWrappingMode(GL_CLAMP, GL_CLAMP);
                bodyDiffuse.SetTextureFilteringMode(GL_LINEAR,
                        GL_LINEAR_MIPMAP_LINEAR);
                bodyDiffuse.BindTexture();
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, BODY_DIM, BODY_DIM, 0,
                        GL_RGBA, GL_UNSIGNED_BYTE, data[0].image.data());
                bodyDiffuse.BuildTextureMipmaps();

                // Body Emissive
                bodyEmissive.SetTextureWrappingMode(GL_CLAMP, GL_CLAMP);
                bodyEmissive.SetTextureFilteringMode(GL_LINEAR,
                        GL_LINEAR_MIPMAP_LINEAR);
                bodyEmissive.BindTexture();
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, BODY_DIM, BODY_DIM, 0,
                        GL_RGBA, GL_UNSIGNED_BYTE, data[1].image.data());
                bodyEmissive.BuildTextureMipmaps();

                // Helm Diffuse
                helmDiffuse.SetTextureWrappingMode(GL_CLAMP, GL_CLAMP);
                helmDiffuse.SetTextureFilteringMode(GL_LINEAR,
                        GL_LINEAR_MIPMAP_LINEAR);
                helmDiffuse.BindTexture();
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, HELM_DIM, HELM_DIM, 0,
                        GL_RGBA, GL_UNSIGNED_BYTE, data[2].image.data());
                helmDiffuse.BuildTextureMipmaps();

                // Helm Emissive
                helmEmissive.SetTextureWrappingMode(GL_CLAMP, GL_CLAMP);
                helmEmissive.SetTextureFilteringMode(GL_LINEAR,
                        GL_LINEAR_MIPMAP_LINEAR);
                helmEmissive.BindTexture();
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, HELM_DIM, HELM_DIM, 0,
                        GL_RGBA, GL_UNSIGNED_BYTE, data[3].image.data());
                helmEmissive.BuildTextureMipmaps();

                // Finally, if possible, enable anisotropy
                #ifdef GL_EXT_texture_filter_anisotropic
                    bodyDiffuse.SetTextureMaxAnisotropy();
                    bodyEmissive.SetTextureMaxAnisotropy();
                    helmDiffuse.SetTextureMaxAnisotropy();
                    helmEmissive.SetTextureMaxAnisotropy();
                #endif

                return true;
            }
            bool saveTextures(std::string path) {
                throw std::string{"NOT IMPLEMENTED YET"} + path;
            }

            // Helpers
            static void loadOnceTextures() {
                if (bodyTemplate.IsNull() || helmTemplate.IsNull()) {
                    ImageData data[2];

                    // Load ImageData: Body Template
                    {
                        std::string path {BODY_TEMPLATE};
                        unsigned int error = lodepng::decode(data[0].image,
                                data[0].width, data[0].height, path.data());
                        if (error || data[0].width != data[0].height ||
                                data[0].width != BODY_DIM) {
                            throw std::string{"Bad Body Template Image!!"};
                        }
                    }

                    // Load ImageData: Helm Template
                    {
                        std::string path {HELM_TEMPLATE};
                        unsigned int error = lodepng::decode(data[1].image,
                                data[1].width, data[1].height, path.data());
                        if (error || data[1].width != data[1].height ||
                                data[1].width != HELM_DIM) {
                            throw std::string{"Bad Helm Template Image!!"};
                        }
                    }

                    bool success = true;
                    success = success && bodyTemplate.Initialize(true, 4,
                            BODY_DIM, BODY_DIM);
                    success = success && helmTemplate.Initialize(true, 4,
                            HELM_DIM, HELM_DIM);

                    if (!success) {
                        throw std::string{"Error initializing templates"};
                    }

                    //// Finally, load image data into the RenderBuffers
                    // Body Diffuse
                    bodyTemplate.SetTextureWrappingMode(GL_CLAMP, GL_CLAMP);
                    bodyTemplate.SetTextureFilteringMode(GL_LINEAR,
                            GL_LINEAR_MIPMAP_LINEAR);
                    bodyTemplate.BindTexture();
                    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, BODY_DIM, BODY_DIM,
                            0, GL_RGBA, GL_UNSIGNED_BYTE, data[0].image.data());
                    bodyTemplate.BuildTextureMipmaps();

                    // Helm Diffuse
                    helmTemplate.SetTextureWrappingMode(GL_CLAMP, GL_CLAMP);
                    helmTemplate.SetTextureFilteringMode(GL_LINEAR,
                            GL_LINEAR_MIPMAP_LINEAR);
                    helmTemplate.BindTexture();
                    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, HELM_DIM, HELM_DIM,
                            0, GL_RGBA, GL_UNSIGNED_BYTE, data[1].image.data());
                    helmTemplate.BuildTextureMipmaps();

                    // Finally, if possible, enable anisotropy
                    #ifdef GL_EXT_texture_filter_anisotropic
                        bodyTemplate.SetTextureMaxAnisotropy();
                        helmTemplate.SetTextureMaxAnisotropy();
                    #endif
                }
            }
        }

    }
}
