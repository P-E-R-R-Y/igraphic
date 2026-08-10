/**
 * @file IWindow3.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @date 2026-08-10
 *
 * @addtogroup graphic
 * @{
 */

#ifndef IWINDOW3_HPP_
    #define IWINDOW3_HPP_
    #include "IWindow2.hpp"
    #include "../graphic/IModel.hpp"

namespace graphic {
    class ICamera;

    /**
     * @brief A window that can also draw 3D. Extends IWindow2, so anything
     *        that only needs 2D can keep using it as an IWindow2 - a 3D
     *        vendor's window still draws sprites/text/polygons the same way.
     * @interface IWindow3
     */
    class IWindow3 : public IWindow2 {

        public:

            virtual ~IWindow3() = default;

            /**
             * @brief allowing to draw 3D on the window
             *
             * @param camera
             */
            virtual void beginMode3(ICamera *camera) = 0;

            /**
             * @brief draw a model
             *
             * @param model
             */
            virtual void drawModel(IModel *model) = 0;

            /**
             * @brief end the 3D drawing
             */
            virtual void endMode3() = 0;
    };

} // namespace graphic

#endif /* !IWINDOW3_HPP_ */
