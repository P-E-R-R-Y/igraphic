/**
 * @file IKeyboard.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @date 2025-09-24
 *
 * @addtogroup igraphic
 * @{
 */

#ifndef IKEYBOARD_HPP
#define IKEYBOARD_HPP

#include <vector>

namespace graphic {

    /**
     * @brief Keyboard interface
     * @interface IKeyboard
     *
     * Four methods, two behaviours.
     *
     * isKeyPressed / isKeyReleased are true for ONE FRAME only, the one
     * where the key changes state. Holding a key does not re-trigger
     * isKeyPressed, even when the OS sends key repeat.
     *
     * isKeyDown / isKeyUp are true EVERY FRAME for as long as the key is
     * held (or released).
     *
     * For a key pressed on frame 3 and released on frame 6 :
     *
     *     key             ______/‾‾‾‾‾‾‾‾‾‾‾\______
     *     frame            1   2   3   4   5   6   7
     *
     *     isKeyDown        0   0   1   1   1   0   0
     *     isKeyUp          1   1   0   0   0   1   1
     *     isKeyPressed     0   0   1   0   0   0   0
     *     isKeyReleased    0   0   0   0   0   1   0
     *
     * Hence the run / jump pair : isKeyDown(KEY_W) keeps moving while W is
     * held, isKeyPressed(KEY_SPACE) jumps once. Jumping on isKeyDown jumps
     * sixty times a second.
     *
     * All four are readable ANYWHERE in the frame, on every vendor : the
     * window drains its queue once in pollEvent() and folds it into state,
     * so nothing has to be read at a particular moment.
     *
     * @code
     * while (window->isOpen()) {
     *     if (window->pollEvent()) {             // the frame's event pump
     *         window->eventClose();
     *         if (kb->isKeyPressed(KEY_SPACE))   // a front
     *             jump();
     *     }
     *
     *     if (kb->isKeyDown(KEY_W))              // a state, outside
     *         walk();
     *
     *     window->beginDraw();
     *     // ...
     *     window->endDraw();                     // end of frame
     * }
     * @endcode
     *
     * The condition is an optimisation, not a rule : with no event the
     * fronts are false anyway. It only holds for the fronts - isKeyDown,
     * isKeyUp and whichKeyDown() are true across frames where nothing
     * happened, so putting them inside would silently drop them on a vendor
     * that has a queue and keep them on one that has not.
     *
     * The boundary between two frames is endDraw(). A press + release
     * inside the same frame is lost, on every vendor.
     *
     * Modifiers are keys like any other : Shift+E is isKeyDown(KEY_LEFT_SHIFT)
     * and isKeyPressed(KEY_E), composed by the caller.
     */
    class IKeyboard {
      public:
    //    typedef enum Layout {
    //      LAYOUT_QWERTY = 0,
    //      LAYOUT_AZERTY = 1,
    //    } Layout;

        /// Scan codes
        enum Keys {
          KEY_UNKNOWN = -1,

          /// Line 0
          KEY_ESCAPE,
          KEY_F1,
          KEY_F2,
          KEY_F3,
          KEY_F4,
          KEY_F5,
          KEY_F6,
          KEY_F7,
          KEY_F8,
          KEY_F9,
          KEY_F10,
          KEY_F11,
          KEY_F12,

          /// Line 1
          KEY_1,
          KEY_2,
          KEY_3,
          KEY_4,
          KEY_5,
          KEY_6,
          KEY_7,
          KEY_8,
          KEY_9,
          KEY_0,
          KEY_MINUS,
          KEY_EQUAL,
          KEY_BACKSPACE,

          /// Line 2
          KEY_TAB,
          KEY_Q,
          KEY_W,
          KEY_E,
          KEY_R,
          KEY_T,
          KEY_Y,
          KEY_U,
          KEY_I,
          KEY_O,
          KEY_P,
          KEY_LEFT_BRACKET,
          KEY_RIGHT_BRACKET,

          /// Line 3
          KEY_CAPS_LOCK,
          KEY_LEFT_CONTROL,
          KEY_A,
          KEY_S,
          KEY_D,
          KEY_F,
          KEY_G,
          KEY_H,
          KEY_J,
          KEY_K,
          KEY_L,
          KEY_SEMICOLON,
          KEY_APOSTROPHE,
          KEY_BACKTICK,
          KEY_ENTER,

          /// Line 4
          KEY_LEFT_SHIFT,
          KEY_BACKSLASH,
          KEY_Z,
          KEY_X,
          KEY_C,
          KEY_V,
          KEY_B,
          KEY_N,
          KEY_M,
          KEY_COMMA,
          KEY_PERIOD,
          KEY_SLASH,
          KEY_RIGHT_SHIFT,
          /// Line 5
          KEY_LEFT_ALT,
          KEY_LEFT_SUPER,
          KEY_SPACE,
          KEY_RIGHT_ALT,
          KEY_RIGHT_SUPER,
          KEY_RIGHT_CONTROL,

          /// KEYPAD
          KEY_PAD_0,
          KEY_PAD_1,
          KEY_PAD_2,
          KEY_PAD_3,
          KEY_PAD_4,
          KEY_PAD_5,
          KEY_PAD_6,
          KEY_PAD_7,
          KEY_PAD_8,
          KEY_PAD_9,
          KEY_PAD_MINUS,
          KEY_PAD_PLUS,
          KEY_PAD_DOT,
          KEY_PAD_ENTER,

          /// ARROWS
          KEY_UP,
          KEY_DOWN,
          KEY_LEFT,
          KEY_RIGHT,
          //end
          KEY_COUNT
        };

        /**
         * @brief Destroy the IKeyboard object
         */
        virtual ~IKeyboard() {}

        /**
         * @brief Every key HELD right now - like isKeyDown, without having
         *        to name the key.
         *
         * A held key stays in the list every frame. For a debug overlay, a
         * state readout, chord detection.
         *
         * Walks the whole keyboard : avoid in a hot loop, isKeyDown is a
         * direct lookup.
         *
         * @return std::vector<Keys>
         */
        virtual std::vector<Keys> whichKeyDown() const = 0;


        /**
         * @brief Check if the key is pressed
         *
         * @param key
         * @return bool
         */
        virtual bool isKeyPressed(Keys key) const = 0;

        /**
         * @brief Check if the key is released
         *
         * @param key
         * @return bool
         */
        virtual bool isKeyReleased(Keys key) const = 0;

        /**
         * @brief Check if the key is down
         *
         * @param key
         * @return bool
         */
        virtual bool isKeyDown(Keys key) const = 0;

        /**
         * @brief Check if the key is up
         *
         * @param key
         * @return bool
         */
        virtual bool isKeyUp(Keys key) const = 0;

      private:
    };

}

/** @} */

#endif /* !IKEYBOARD_HPP */