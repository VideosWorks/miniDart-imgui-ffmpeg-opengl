/*
 * File sdl_utils.cpp, belongs to miniDart project
 * Copyright Eric Bachard  / lundi 3 octobre 2016, 14:35:03 (UTC+0200)
 * This document is under GPL v2 license
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include "sdl_utils.hpp"

void sdl_application_abort(const char * msg)
{
    std::cout << SDL_GetError() << std::endl;
    SDL_Quit();
    exit (-1);
}

void getInfo(void)
{
    SDL_version compiled;
    SDL_version linked;
    SDL_VERSION(&compiled);
    SDL_GetVersion(&linked);

    fprintf(stdout, "We compiled against SDL version %d.%d.%d ...\n",compiled.major, compiled.minor, compiled.patch);
    fprintf(stdout, "And we are linking against SDL version %d.%d.%d.\n", linked.major, linked.minor, linked.patch);

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " 
              << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;


}

void getTextureInfo( SDL_Texture * texture)
{
    int loop_value = 100;
    unsigned int * aTextureInfo_format = 0;
    int * aTextureInfo_access = 0;
    int * aTextureInfo_w = 0;
    int * aTextureInfo_h = 0;
    int anErr = 0;
    int count = 0;

    if ( count % loop_value == 0 )
    {
        anErr = SDL_QueryTexture(texture, aTextureInfo_format, aTextureInfo_access, aTextureInfo_w, aTextureInfo_h);
//        anErr = SDL_QueryTexture(texture, NULL, NULL, aTextureInfo_w, aTextureInfo_h);

        if (anErr < 0)
        {
            std::cout << "Problem reading aTextureInfo (anErr =" << SDL_GetError()  << ")"<< std::endl;
        }
        else
        {
            std::cout << "aTextureInfo_format = " <<  &aTextureInfo_format  << std::endl;
            std::cout << "aTextureInfo_access = " <<  &aTextureInfo_access  << std::endl;
            std::cout << "aTextureInfo_w = " <<  &aTextureInfo_w  << std::endl;
            std::cout << "aTextureInfo_w = " <<  &aTextureInfo_h  << std::endl;
        }
        count++;
        if ( (count == loop_value) || ((count > loop_value)))
            count =0;
    }
}
