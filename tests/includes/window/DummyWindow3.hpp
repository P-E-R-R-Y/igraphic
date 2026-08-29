#pragma once
#include "IWindow3.hpp"

class DummyWindow3 : public graphic::IWindow3 {
public:
    DummyWindow3() {}
    ~DummyWindow3() {}

    bool isOpen() override {
        return {};
    }
    void close() override {
        // no-op
    }
    Vector2f getPosition() override {
        return {};
    }
    void setPosition(Vector2f position) override {
        // no-op
    }
    Vector2f getSize() override {
        return {};
    }
    void setSize(Vector2f size) override {
        // no-op
    }
    void setFrameLimit(int32_t limit) override {
        // no-op
    }
    void setMouseVisibility(bool visible) override {
        _cursor = visible;
    }
    int32_t getDelta() override {
        return {};
    }
    bool pollEvent() override {
        return {};
    }
    void eventClose() override {
        // no-op
    }
    void beginDraw() override {
        // no-op
    }
    void drawPoly(graphic::IPolygon *polygon) override {
        // no-op
    }
    void drawSprite(graphic::ISprite *sprite) override {
        // no-op
    }
    void drawText(graphic::IText *text) override {
        // no-op
    }
    void endDraw() override {
        // no-op
    }
    void beginMode3(graphic::ICamera *camera) override {
        // no-op
    }
    void drawModel(graphic::IModel *model) override {
        // no-op
    }
    void drawText3D(graphic::IText *text, Vector3f position) override {
        // no-op
    }
    void endMode3() override {
        // no-op
    }

    /// Le seul etat qu'il retient : de quoi verifier l'appel.
    bool _cursor = true;
};
