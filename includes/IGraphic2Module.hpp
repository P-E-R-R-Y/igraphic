/**
 * @file IGraphic2Module.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @version 0.1
 * @date 2026-08-10
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef IGRAPHIC2_MODULE_HPP
#define IGRAPHIC2_MODULE_HPP

#include "window/IWindow2.hpp"

#include "graphic/IFont.hpp"
#include "graphic/IPolygon.hpp"
#include "graphic/ISprite.hpp"
#include "graphic/IText.hpp"
#include "graphic/ITexture.hpp"

#include "IModule.hpp"

class IGraphic2Module : public IModule {

public:
    static constexpr const char *entry = "getGraphic2Module";

    virtual ~IGraphic2Module() = default;

    // window
    virtual graphic::IWindow2 *createWindow(int32_t screenWidth, int32_t screenHeight, std::string title) = 0;
    virtual void deleteWindow(graphic::IWindow2 *) = 0;

    // texture
    virtual graphic::ITexture *createTexture(std::string path) = 0;
    virtual void deleteTexture(graphic::ITexture *texture) = 0;
    // font
    virtual graphic::IFont *createFont(std::string path) = 0;
    virtual void deleteFont(graphic::IFont *font) = 0;

    // polygon
    virtual graphic::IPolygon *createPolygon(std::vector<Vector2f> points) = 0;
    virtual void deletePolygon(graphic::IPolygon *polygon) = 0;
    // sprite
    virtual graphic::ISprite *createSprite(graphic::ITexture *texture) = 0;
    virtual void deleteSprite(graphic::ISprite *sprite) = 0;
    // text
    virtual graphic::IText *createText(std::string text, graphic::IFont *font) = 0;
    virtual void deleteText(graphic::IText *text) = 0;
};

#endif /* !IGRAPHIC2_MODULE_HPP */
