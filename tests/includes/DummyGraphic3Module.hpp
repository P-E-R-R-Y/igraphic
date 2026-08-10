#pragma once

#include "../includes/IGraphic3Module.hpp"

#include "graphic/DummyAnimationSet.hpp"
#include "graphic/DummyFont.hpp"
#include "graphic/DummyMesh.hpp"
#include "graphic/DummyModel.hpp"
#include "graphic/DummyPolygon.hpp"
#include "graphic/DummySprite.hpp"
#include "graphic/DummyText.hpp"
#include "graphic/DummyTexture.hpp"

#include "window/DummyCamera.hpp"
#include "window/DummyWindow3.hpp"

class DummyGraphic3Module : public IGraphic3Module {
public:
    DummyGraphic3Module() {}
    ~DummyGraphic3Module() {}

    const char *type() const override { return "graphic3d"; }
    const char *name() const override { return "DummyGraphic3"; }

    graphic::IWindow3 *createWindow(int32_t, int32_t, std::string) override { return new DummyWindow3(); }
    void deleteWindow(graphic::IWindow2 *w) override { delete w; }

    graphic::ICamera *createCamera(Vector3f, Vector3f, float) override { return new DummyCamera(); }
    void deleteCamera(graphic::ICamera *c) override { delete c; }

    graphic::IMesh *createMesh(std::string) override { return new DummyMesh(); }
    void deleteMesh(graphic::IMesh *m) override { delete m; }

    graphic::IAnimationSet *createAnimationSet(std::string) override { return new DummyAnimationSet(); }
    void deleteAnimationSet(graphic::IAnimationSet *a) override { delete a; }

    graphic::IModel *createModel(graphic::IMesh *mesh) override { return new DummyModel(mesh); }
    void deleteModel(graphic::IModel *m) override { delete m; }

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
