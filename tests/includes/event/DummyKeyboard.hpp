#pragma once
#include "IKeyboard.hpp"

class DummyKeyboard : public graphic::IKeyboard {
public:
        DummyKeyboard() {}
        ~DummyKeyboard() {}
        std::vector<graphic::IKeyboard::Keys> whichKeyDown() const override {return {};}
        bool isKeyPressed(Keys key) const override {return false;}
        bool isKeyReleased(Keys key) const override {return false;}
        bool isKeyDown(Keys key) const override {return false;}
        bool isKeyUp(Keys key) const override {return false;}
};
