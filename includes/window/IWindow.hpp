/**
 * @file IWindow.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @date 2025-09-24
 *
 * @addtogroup graphic
 * @{
 */

#ifndef IWINDOW_HPP_
    #define IWINDOW_HPP_
    #include "../event/IKeyboard.hpp"
    #include "../event/IMouse.hpp"
    #include "../event/IGamepad.hpp"

namespace graphic {

    /**
     * @brief Window lifecycle + native input. No drawing here : any window,
     *        2D-capable or not, needs to open/close/poll and hand out the
     *        keyboard/mouse/gamepad it pumps internally. See IWindow2 for
     *        2D drawing, IWindow3 for 3D.
     * @interface IWindow
     */
    class IWindow {

        public:

            /**
             * @brief Destroy the IWindow object
             */
            virtual ~IWindow() = default;

            /**
             * @brief notice if the window is open
             *
             * @return bool
             */
            virtual bool isOpen() = 0;

            /**
             * @brief close the window
             */
            virtual void close() = 0;

            /**
             * @brief Set the Frame Limit object
             *
             * @param limit
             */
            virtual void setFrameLimit(int32_t limit) = 0;

            /**
             * @brief Get the Delta object
             *
             * @return __int32_t
             */
            virtual int32_t getDelta() = 0;

            /**
             * @brief poll the native events (also refreshes keyboard/mouse/gamepad state)
             *
             * @return bool
             */
            virtual bool pollEvent() = 0;

            /**
             * @brief notice the window that a close was requested
             */
            virtual void eventClose() = 0;

            /**
             * @brief the window's keyboard, pumped by pollEvent()
             *
             * @return graphic::IKeyboard*
             */
            virtual IKeyboard *createKeyboard() = 0;
            virtual void deleteKeyboard(IKeyboard *keyboard) = 0;

            /**
             * @brief the window's mouse, pumped by pollEvent()
             *
             * @return graphic::IMouse*
             */
            virtual IMouse *createMouse() = 0;
            virtual void deleteMouse(IMouse *mouse) = 0;

            /**
             * @brief the window's gamepad, pumped by pollEvent(). nullptr if this
             *        vendor doesn't support one (e.g. a terminal backend).
             *
             * @return graphic::IGamepad*
             */
            virtual IGamepad *createGamepad() = 0;
            virtual void deleteGamepad(IGamepad *gamepad) = 0;

        private:
            //your variables here
    };

} // namespace graphic

#endif /* !IWINDOW_HPP_ */
