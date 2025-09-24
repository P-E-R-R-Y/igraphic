/**
 * @file IGraphicModule.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @version 0.1
 * @date 11-06-2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef IGRAPHIC_MODULE_HPP
#define IGRAPHIC_MODULE_HPP

#include "window/ICamera.hpp"
#include "window/IWindow.hpp"

#include "graphic/IModel.hpp"
#include "graphic/IPolygon.hpp"
#include "graphic/ISprite.hpp"
#include "graphic/IText.hpp"

#include "event/IEvent.hpp"
#include "event/IKeyboard.hpp"
#include "event/IMouse.hpp"

#include "audio/IMusic.hpp"
#include "audio/ISound.hpp"

#include "IModule.hpp"

class IGraphicModule : public IModule {

public:
    virtual ~IGraphicModule() = default;

    // window
    virtual graphic::IWindow *createWindow(int32_t screenWidth, int32_t screenHeight, std::string title) = 0;
    virtual void deleteWindow(graphic::IWindow *) = 0;

    /* 3D */

    // camera
    virtual graphic::ICamera *createCamera() = 0;
    virtual void deleteCamera(graphic::ICamera *) = 0;
    
    // model
    virtual graphic::IModel *createModel() = 0;
    virtual void deleteModel(graphic::IModel *model) = 0;

    /* 2D */

    // polygon
    virtual graphic::IPolygon *createPolygon(std::vector<Vector2f> points) = 0;
    virtual void deletePolygon(graphic::IPolygon *polygon) = 0;
    // sprite
    virtual graphic::ISprite *createSprite(std::string sprite) = 0;
    virtual void deleteSprite(graphic::ISprite *sprite) = 0;
    // text
    virtual graphic::IText *createText(std::string text, std::string font) = 0;
    virtual void deleteText(graphic::IText *text) = 0;

    /* Event */

    // event
    virtual graphic::IEvent *createEvent() = 0;
    virtual void deleteEvent(graphic::IEvent *event) = 0;
    // keyboard
    virtual graphic::IKeyboard *createKeyboard(graphic::IEvent *event) = 0;
    virtual void deleteKeyboard(graphic::IKeyboard *keyboard) = 0;
    // mouse
    virtual graphic::IMouse *createMouse(graphic::IEvent *event) = 0;
    virtual void deleteMouse(graphic::IMouse *mouse) = 0;

    /* Audio */ 

    // music
    virtual graphic::IMusic *createMusic(std::string path) = 0;
    virtual void deleteMusic(graphic::IMusic *music) = 0;
    // sound
    virtual graphic::ISound *createSound(std::string path) = 0;
    virtual void deleteSound(graphic::ISound *sound) = 0;
};

#endif /* !IGRAPHIC_MODULE_HPP */