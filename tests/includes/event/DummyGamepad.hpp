#pragma once
#include "IGamepad.hpp"

class DummyGamepad : public graphic::IGamepad {
public:
    DummyGamepad() {}
    ~DummyGamepad() {}

    bool isAvailable() const override { return true; }
    bool isButtonPressed(Button button) const override { return false; }
    bool isButtonDown(Button button) const override { return false; }
    bool isButtonReleased(Button button) const override { return false; }
    bool isButtonUp(Button button) const override { return true; }
    float getAxisMovement(Axis axis) const override { return 0.f; }
};
