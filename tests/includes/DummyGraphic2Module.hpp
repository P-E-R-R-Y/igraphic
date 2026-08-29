#pragma once

#include "../includes/IGraphic2Module.hpp"

#include "event/DummyGamepad.hpp"
#include "event/DummyKeyboard.hpp"
#include "event/DummyMouse.hpp"

#include "graphic/DummyFont.hpp"
#include "graphic/DummyPolygon.hpp"
#include "graphic/DummySprite.hpp"
#include "graphic/DummyText.hpp"
#include "graphic/DummyTexture.hpp"

#include "window/DummyWindow2.hpp"

class DummyGraphic2Module : public IGraphic2Module {
public:
    DummyGraphic2Module() {}
    ~DummyGraphic2Module() {}

    const char *type() const override { return "graphic2d"; }
    const char *name() const override { return "DummyGraphic2"; }

    graphic::IWindow2 *createWindow(int32_t, int32_t, std::string) override { return new DummyWindow2(); }
    graphic::IWindow2 *window() override { return nullptr; }

    void deleteWindow(graphic::IWindow2 *w) override { delete w; }

    graphic::IKeyboard *createKeyboard(graphic::IWindow *) override { return new DummyKeyboard(); }
    void deleteKeyboard(graphic::IKeyboard *k) override { delete k; }

    graphic::IMouse *createMouse(graphic::IWindow *) override { return new DummyMouse(); }
    void deleteMouse(graphic::IMouse *m) override { delete m; }

    graphic::IGamepad *createGamepad(graphic::IWindow *) override { return new DummyGamepad(); }
    void deleteGamepad(graphic::IGamepad *g) override { delete g; }

    graphic::ITexture *createTexture(std::string) override { return new DummyTexture(); }
    void deleteTexture(graphic::ITexture *t) override { delete t; }

    graphic::IFont *createFont(std::string) override { return new DummyFont(); }
    void deleteFont(graphic::IFont *f) override { delete f; }

    graphic::IPolygon *createPolygon(std::vector<Vector2f>) override { return new DummyPolygon(); }
    void deletePolygon(graphic::IPolygon *p) override { delete p; }

    graphic::ISprite *createSprite(graphic::ITexture *) override { return new DummySprite(); }
    void deleteSprite(graphic::ISprite *s) override { delete s; }

    graphic::IText *createText(std::string, graphic::IFont *) override { return new DummyText(); }
    void deleteText(graphic::IText *t) override { delete t; }
};
