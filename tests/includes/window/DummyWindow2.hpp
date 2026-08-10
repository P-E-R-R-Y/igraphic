#pragma once
#include "IWindow2.hpp"
#include "../event/DummyKeyboard.hpp"
#include "../event/DummyMouse.hpp"
#include "../event/DummyGamepad.hpp"

class DummyWindow2 : public graphic::IWindow2 {
public:
    DummyWindow2() {}
    ~DummyWindow2() {}

    bool isOpen() override {
        return {};
    }
    void close() override {
        // no-op
    }
    void setFrameLimit(int32_t limit) override {
        // no-op
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
    graphic::IKeyboard *createKeyboard() override {
        return new DummyKeyboard();
    }
    void deleteKeyboard(graphic::IKeyboard *keyboard) override {
        delete keyboard;
    }
    graphic::IMouse *createMouse() override {
        return new DummyMouse();
    }
    void deleteMouse(graphic::IMouse *mouse) override {
        delete mouse;
    }
    graphic::IGamepad *createGamepad() override {
        return new DummyGamepad();
    }
    void deleteGamepad(graphic::IGamepad *gamepad) override {
        delete gamepad;
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
};
