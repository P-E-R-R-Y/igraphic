#pragma once

#include "../includes/IGraphic2Module.hpp"

#include "graphic/DummyPolygon.hpp"
#include "graphic/DummySprite.hpp"
#include "graphic/DummyText.hpp"

#include "window/DummyWindow2.hpp"

class DummyGraphic2Module : public IGraphic2Module {
public:
    DummyGraphic2Module() {}
    ~DummyGraphic2Module() {}

    const char *type() const override { return "graphic2d"; }
    const char *name() const override { return "DummyGraphic2"; }

    graphic::IWindow2 *createWindow(int32_t, int32_t, std::string) override { return new DummyWindow2(); }
    void deleteWindow(graphic::IWindow2 *w) override { delete w; }

    graphic::IPolygon *createPolygon(std::vector<Vector2f>) override { return new DummyPolygon(); }
    void deletePolygon(graphic::IPolygon *p) override { delete p; }

    graphic::ISprite *createSprite(std::string) override { return new DummySprite(); }
    void deleteSprite(graphic::ISprite *s) override { delete s; }

    graphic::IText *createText(std::string, std::string) override { return new DummyText(); }
    void deleteText(graphic::IText *t) override { delete t; }
};
