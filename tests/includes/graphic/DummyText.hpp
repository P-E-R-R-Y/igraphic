#pragma once
#include "IText.hpp"

class DummyText : public graphic::IText {
public:
    DummyText() {}
    ~DummyText() {}

    bool isReady() const override {
        return {};
    }
    void setText(const std::string text) override {
        // no-op
    }
    std::string getText() const override {
        return {};
    }
    void setFont(std::string path) override {
        // no-op
    }
    void setFontSize(unsigned int size) override {
        // no-op
    }
    unsigned int getFontSize() const override {
        return {};
    }
    void setTextColor(Color color) override {
        // no-op
    }
    Color getTextColor() const override {
        return {};
    }
    void setPosition(Vector2f position) override {
        // no-op
    }
    Vector2f getPosition() const override {
        return {};
    }
    void setRotation(float angle) override {
        // no-op
    }
    float getRotation() const override {
        return {};
    }
};
