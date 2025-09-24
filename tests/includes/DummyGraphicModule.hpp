#pragma once

#include "../includes/IGraphicModule.hpp"
#include "audio/DummyMusic.hpp"
#include "audio/DummySound.hpp"

#include "audio/DummySound.hpp"
#include "audio/DummyMusic.hpp"

#include "event/DummyEvent.hpp"
#include "event/DummyKeyboard.hpp"
#include "event/DummyMouse.hpp"

#include "graphic/DummyModel.hpp"
#include "graphic/DummyPolygon.hpp"
#include "graphic/DummySprite.hpp"
#include "graphic/DummyText.hpp"

#include "window/DummyWindow.hpp"
#include "window/DummyCamera.hpp"

class DummyGraphicModule : public IGraphicModule {
public:
    DummyGraphicModule() {}
    ~DummyGraphicModule() {}

    const std::string getType() const override { return "graphic"; }
    const std::string getName() const override { return "DummyGraphic"; }
    void update() override {}

    // Implement methods trivially to return PGenTest objects

    graphic::ICamera* createCamera() override { return new DummyCamera(); }
    void deleteCamera(graphic::ICamera* c) override { delete c; }

    graphic::IWindow* createWindow(int32_t, int32_t, std::string) override { return new DummyWindow(); }
    void deleteWindow(graphic::IWindow* w) override { delete w; }

    graphic::IModel* createModel() override { return new DummyModel(); }
    void deleteModel(graphic::IModel* m) override { delete m; }

    graphic::IPolygon* createPolygon(std::vector<Vector2f>) override { return new DummyPolygon(); }
    void deletePolygon(graphic::IPolygon* p) override { delete p; }

    graphic::ISprite* createSprite(std::string) override { return new DummySprite(); }
    void deleteSprite(graphic::ISprite* s) override { delete s; }

    graphic::IText* createText(std::string, std::string) override { return new DummyText(); }
    void deleteText(graphic::IText* t) override { delete t; }

    graphic::IEvent* createEvent() override { return new DummyEvent(); }
    void deleteEvent(graphic::IEvent* e) override { delete e; }

    graphic::IKeyboard* createKeyboard(graphic::IEvent*event) override { return new DummyKeyboard(event); }
    void deleteKeyboard(graphic::IKeyboard* k) override { delete k; }

    graphic::IMouse* createMouse(graphic::IEvent*event) override { return new DummyMouse(event); }
    void deleteMouse(graphic::IMouse* m) override { delete m; }

    graphic::IMusic* createMusic(std::string) override { return new DummyMusic(); }
    void deleteMusic(graphic::IMusic* m) override { delete m; }

    graphic::ISound* createSound(std::string) override { return new DummySound(); }
    void deleteSound(graphic::ISound* s) override { delete s; }
};