#pragma once
#include "IWindow.hpp"

class DummyWindow : public graphic::IWindow {
public:
    DummyWindow() {}
    ~DummyWindow() {}

    bool isOpen() override {
        return {};
    }

    void setFrameLimit(__int32_t limit) override {
        // no-op
    }
    __int32_t getDelta() override {
        return {};
    }
    void linkEvent(graphic::IEvent *event) override {
        // no-op
    }
    void beginDraw() override {
        // no-op
    }
    void drawPoly(graphic::IPolygon *polygon) override {
        // no-op
    }
    void drawSprite(graphic::ISprite *model) override {
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
    void endMode3() override {
        // no-op
    }
    bool pollEvent() override {
        return {};
    }
    void eventClose() override {
        // no-op
    }
    bool beginAudio() override {
        return {};
    }
    void endAudio() override {
        // no-op
    }
};
