#include <gtest/gtest.h>
#include "IModule.hpp"
#include "IGraphic2Module.hpp"
#include "IGraphic3Module.hpp"
#include "DummyGraphic2Module.hpp"
#include "DummyGraphic3Module.hpp"

#include <vector>
#include "Type.hpp"

TEST(GraphicModuleTest, Graphic2Object) {
    DummyGraphic2Module mod;

    EXPECT_STREQ(mod.name(), "DummyGraphic2");
    EXPECT_STREQ(mod.type(), "graphic2d");

    graphic::IPolygon *polygon = mod.createPolygon(std::vector<Vector2f>());
    graphic::ISprite *sprite = mod.createSprite("");
    graphic::IText *text = mod.createText("", "");
    graphic::IWindow2 *window = mod.createWindow(1, 1, "window");

    ASSERT_NE(polygon, nullptr);
    ASSERT_NE(sprite, nullptr);
    ASSERT_NE(text, nullptr);
    ASSERT_NE(window, nullptr);

    // a 2D window still hands out keyboard/mouse/gamepad - not gated by drawing capability
    graphic::IKeyboard *keyboard = window->createKeyboard();
    graphic::IMouse *mouse = window->createMouse();
    graphic::IGamepad *gamepad = window->createGamepad();

    ASSERT_NE(keyboard, nullptr);
    ASSERT_NE(mouse, nullptr);
    ASSERT_NE(gamepad, nullptr);

    window->deleteKeyboard(keyboard);
    window->deleteMouse(mouse);
    window->deleteGamepad(gamepad);

    mod.deletePolygon(polygon);
    mod.deleteSprite(sprite);
    mod.deleteText(text);
    mod.deleteWindow(window);
}

TEST(GraphicModuleTest, Graphic3ObjectAlsoDoes2D) {
    DummyGraphic3Module mod;

    EXPECT_STREQ(mod.name(), "DummyGraphic3");
    EXPECT_STREQ(mod.type(), "graphic3d");

    graphic::ICamera *camera = mod.createCamera({0, 0, 0}, {0, 0, 0}, 0);
    graphic::IModel *model = mod.createModel("");
    // still available : IGraphic3Module extends IGraphic2Module
    graphic::ISprite *sprite = mod.createSprite("");
    graphic::IWindow3 *window = mod.createWindow(1, 1, "window");

    ASSERT_NE(camera, nullptr);
    ASSERT_NE(model, nullptr);
    ASSERT_NE(sprite, nullptr);
    ASSERT_NE(window, nullptr);

    // an IWindow3 IS an IWindow2 : draws sprites too, not just models
    window->beginMode3(camera);
    window->drawModel(model);
    window->endMode3();
    window->beginDraw();
    window->drawSprite(sprite);
    window->endDraw();

    mod.deleteCamera(camera);
    mod.deleteModel(model);
    mod.deleteSprite(sprite);
    mod.deleteWindow(window);
}
