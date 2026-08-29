/**
 * @file IGamepad.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @date 2026-08-10
 *
 * @addtogroup igraphic
 * @{
 */

#ifndef IGAMEPAD_HPP_
    #define IGAMEPAD_HPP_

namespace graphic {

    /**
     * @brief Gamepad interface. Not every window can hand one out (a
     *        terminal backend has no controller) - IWindow::createGamepad()
     *        returns nullptr in that case, this type itself stays complete.
     * @interface IGamepad
     *
     * Same rules as IKeyboard : isButtonPressed / isButtonReleased are true
     * for one frame, isButtonDown / isButtonUp for as long as it lasts, and
     * all four are read anywhere in the frame, as is getAxisMovement().
     */
    class IGamepad {

        public:

            enum Button {
                BUTTON_UNKNOWN = -1,
                BUTTON_A,
                BUTTON_B,
                BUTTON_X,
                BUTTON_Y,
                BUTTON_LEFT_BUMPER,
                BUTTON_RIGHT_BUMPER,
                BUTTON_BACK,
                BUTTON_START,
                BUTTON_LEFT_THUMB,
                BUTTON_RIGHT_THUMB,
                BUTTON_DPAD_UP,
                BUTTON_DPAD_RIGHT,
                BUTTON_DPAD_DOWN,
                BUTTON_DPAD_LEFT,
                BUTTON_LENGTH
            };

            enum Axis {
                AXIS_LEFT_X,
                AXIS_LEFT_Y,
                AXIS_RIGHT_X,
                AXIS_RIGHT_Y,
                AXIS_LEFT_TRIGGER,
                AXIS_RIGHT_TRIGGER,
                AXIS_LENGTH
            };

            /**
             * @brief Destroy the IGamepad object
             */
            virtual ~IGamepad() = default;

            /**
             * @brief notice if a gamepad is actually plugged in
             *
             * @return bool
             */
            virtual bool isAvailable() const = 0;

            /**
             * @brief notice if the button is pressed
             *
             * @param button
             * @return bool
             */
            virtual bool isButtonPressed(Button button) const = 0;

            /**
             * @brief notice if the button is down
             *
             * @param button
             * @return bool
             */
            virtual bool isButtonDown(Button button) const = 0;

            /**
             * @brief notice if the button is released
             *
             * @param button
             * @return bool
             */
            virtual bool isButtonReleased(Button button) const = 0;

            /**
             * @brief notice if the button is up
             *
             * @param button
             * @return bool
             */
            virtual bool isButtonUp(Button button) const = 0;

            /**
             * @brief the movement of an axis, in [-1, 1]
             *
             * @param axis
             * @return float
             */
            virtual float getAxisMovement(Axis axis) const = 0;
    };

} // namespace graphic

/** @} */

#endif /* !IGAMEPAD_HPP_ */
