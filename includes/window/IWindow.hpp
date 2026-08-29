/**
 * @file IWindow.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @date 2025-09-24
 *
 * @addtogroup igraphic
 * @{
 */

#ifndef IWINDOW_HPP_
    #define IWINDOW_HPP_
    #include "Type.hpp"

namespace graphic {

    /**
     * @brief Window lifecycle. No drawing here : every window, 2D-capable
     *        or not, has to open, close and pump its events. See IWindow2
     *        for 2D drawing, IWindow3 for 3D.
     *
     * Native input (keyboard/mouse/pad) is created from the module, handing
     * it the window : createKeyboard(window). The window is what pumps the
     * events they depend on.
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
             * @brief Where the window sits on the desktop, in pixels,
             *        origin top-left of the primary screen.
             *
             * @return Vector2f
             */
            virtual Vector2f getPosition() = 0;

            /**
             * @brief Move the window on the desktop.
             *
             * @param position
             */
            virtual void setPosition(Vector2f position) = 0;

            /**
             * @brief The drawable area, in pixels - NOT the desktop size.
             *        A hit-test built on IMouse::getPosition() compares
             *        against this one.
             *
             * @return Vector2f
             */
            virtual Vector2f getSize() = 0;

            /**
             * @brief Resize the drawable area.
             *
             * @param size
             */
            virtual void setSize(Vector2f size) = 0;

            /**
             * @brief Set the Frame Limit object
             *
             * @param limit
             */
            virtual void setFrameLimit(int32_t limit) = 0;

            /**
             * @brief Show or hide the system cursor over THIS window.
             *
             * For any game that draws its own pointer - a crosshair, a
             * selection ring - where the native arrow sitting on top of it
             * is just a second, wrong cursor.
             *
             * Scoped to the window, not to the desktop : leaving it puts the
             * arrow back, and closing the window can never strand the user
             * without a pointer. Vendors whose cursor is process-wide
             * (raylib) restore it on close for the same reason.
             *
             * Hiding does NOT capture the mouse : IMouse::getPosition() keeps
             * answering, and the pointer still leaves the window normally.
             *
             * @param visible
             */
            virtual void setMouseVisibility(bool visible) = 0;

            /**
             * @brief Get the Delta object
             *
             * @return __int32_t
             */
            virtual int32_t getDelta() = 0;

            /**
             * @brief Drains the whole native queue for this frame and
             *        refreshes device state. This is the frame's event pump.
             *
             * ONE call per frame. ALWAYS written as a condition :
             *
             * @code
             * if (window->pollEvent()) {
             *     window->eventClose();
             *     if (kb->isKeyPressed(KEY_SPACE)) jump();   // fronts here
             * }
             * @endcode
             *
             * Calling it again in the same frame finds the native queue
             * empty, adds nothing, and answers the same thing : two readers
             * sharing a window cannot steal each other's events. An arcade
             * drawing a menu and a game running inside it both read the
             * keyboard, and neither has to know about the other.
             *
             * What was drained is dropped by endDraw(), the frame boundary.
             *
             * ONLY THE FRONTS go inside the condition - isKeyPressed and
             * isKeyReleased, which are false anyway when nothing happened.
             * isKeyDown, isKeyUp and whichKeyDown() are states : they stay
             * true across frames with no event at all, so they are read
             * outside. See IKeyboard for the detail.
             *
             * @return true if anything happened this frame. A vendor with
             *         no queue (raylib) cannot know and answers true always,
             *         which is harmless as long as the rule above is held.
             */
            virtual bool pollEvent() = 0;

            /**
             * @brief notice the window that a close was requested
             */
            virtual void eventClose() = 0;

        private:
            //your variables here
    };

} // namespace graphic

/** @} */

#endif /* !IWINDOW_HPP_ */
