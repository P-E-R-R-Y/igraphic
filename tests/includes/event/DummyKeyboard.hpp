#pragma once
#include "IKeyboard.hpp"

class DummyKeyboard : public graphic::IKeyboard {
public:
 /**
         * @brief Destroy the IKeyboard object
         */
        DummyKeyboard(graphic::IEvent *event) {}
        ~DummyKeyboard() {}
        std::vector<graphic::IKeyboard::Keys> whichKey() const override {return std::vector<graphic::IKeyboard::Keys>();}
        bool isKeyPressed(Keys key) const override {return false;}
        bool isKeyReleased(Keys key) const override {return false;}
        bool isKeyDown(Keys key) const override {return false;}
        bool isKeyUp(Keys key) const override {return false;}
        void update() override {}
};
