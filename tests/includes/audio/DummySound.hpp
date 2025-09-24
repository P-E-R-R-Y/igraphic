#pragma once
#include "ISound.hpp"

class DummySound : public graphic::ISound {
public:
    DummySound() {}
    ~DummySound() {}

    bool isReady() const override {
        return false;
    }
    void play() override {
        // no-op
    }
    void pause() override {
        // no-op
    }
    void stop() override {
        // no-op
    }
    void setVolume(float volume) override {
        // no-op
    }
    float getVolume() const override {
        return 0;
    }
};
