/**
 * @file IWindow2.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @date 2026-08-10
 *
 * @addtogroup igraphic
 * @{
 */

#ifndef IWINDOW2_HPP_
    #define IWINDOW2_HPP_
    #include "IWindow.hpp"
    #include "../graphic/IPolygon.hpp"
    #include "../graphic/ISprite.hpp"
    #include "../graphic/IText.hpp"

namespace graphic {

    /**
     * @brief A window that can draw 2D. Adds only the 2D drawing surface on
     *        top of IWindow's lifecycle/input.
     * @interface IWindow2
     */
    class IWindow2 : public IWindow {

        public:

            virtual ~IWindow2() = default;

            /**
             * @brief allowing to draw 2D on the window
             */
            virtual void beginDraw() = 0;

            /**
             * @brief draw a polygon
             *
             * @param polygon
             */
            virtual void drawPoly(IPolygon *polygon) = 0;

            /**
             * @brief draw a sprite
             *
             * @param sprite
             */
            virtual void drawSprite(ISprite *sprite) = 0;

            /**
             * @brief draw a text
             */
            virtual void drawText(IText *text) = 0;

            /**
             * @brief end the 2D drawing
             */
            virtual void endDraw() = 0;
    };

} // namespace graphic

/** @} */

#endif /* !IWINDOW2_HPP_ */
