/**
 * @file IModel.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @date 2025-01-29
 * 
 * @addtogroup graphic
 * @{
 */




#ifndef IMODEL_HPP_
    #define IMODEL_HPP_
    #include "type.hpp"
    #include "../window/IWindow.hpp"

namespace graphic {

    /**
     * @brief Model interface
     * @interface IModel 
     */
    class IModel {

        public:
            //constructor
            virtual ~IModel() = default;
            //p
            virtual Vector3f getPosition() const = 0;
            virtual void setPosition(Vector3f position) = 0;

        private:
            //your variables here
    };

} // namespace graphic3

#endif /* !IMODEL_HPP_ */