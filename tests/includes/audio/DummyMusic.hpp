#pragma once
#include "IMusic.hpp"

class DummyMusic : public graphic::IMusic {
public:
    DummyMusic() {}
    ~DummyMusic() {}

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
    void update() override {
        // no-op
    }
    void setVolume(float volume) override {
        // no-op
    }
    float getVolume() const override {
        return 0;
    }
    void setLoop(bool loop) override {
        // no-op
    }
    bool getLoop() const override {
        return false;
    }
    void setTime(float position) override {
        // no-op
    }
    float getTime() const override {
        return 0;
    }
    float getLength() const override {
        return 0;
    }
};
