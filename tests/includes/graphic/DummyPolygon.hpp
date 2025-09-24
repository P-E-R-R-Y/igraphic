#pragma once
#include "IPolygon.hpp"

class DummyPolygon : public graphic::IPolygon {
public:
    Color getColor() const override {
        return {.r=0, .g=0, .b=0};
    }
    void setColor(Color position) override {
        // no-op
    }
    bool isReady() const override {
        return false;
    }
    Vector2f getPosition() const override {
        return {.x=0, .y=0};

    }
    void setPosition(Vector2f position) override {
        // no-op
    }
    std::vector<Vector2f> getPoints() const override {
        return {};
    }
};
