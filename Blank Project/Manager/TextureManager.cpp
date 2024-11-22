#include "TextureManager.h"

#include <SOIL/SOIL.h>

GLuint TextureManager::skyBox = 0;

GLuint TextureManager::GetSkyBoxTexture()
{
    if (!skyBox) skyBox = SOIL_load_OGL_cubemap(
        SKYBOXDIR"Left.png", SKYBOXDIR"Right.png", SKYBOXDIR"Up.png",
        SKYBOXDIR"Down.png", SKYBOXDIR"Front.png", SKYBOXDIR"Back.png",
        SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, 0);
    return skyBox;
}
