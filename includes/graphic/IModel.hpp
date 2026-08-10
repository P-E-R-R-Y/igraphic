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
    #include "Type.hpp"
    #include "../window/IWindow.hpp"
    #include "IAnimationSet.hpp"
    #include "ITexture.hpp"

namespace graphic {

    /**
     * @brief Model interface
     * @interface IModel
     */
    class IModel {

        public:
            //constructor
            virtual ~IModel() = default;

            // a loaded ITexture, not a path - swapping a model's texture
            // never implies a reload from disk
            virtual void setTexture(ITexture *texture) = 0;

            // a loaded IAnimationSet, not a path - swapping a model's
            // animations never implies a reload from disk
            virtual void setAnimations(IAnimationSet *animations) = 0;
            virtual int getAnimationsSize() const = 0;
            virtual void setAnimation(int pos) = 0;
            virtual int getAnimation() const = 0;
            virtual void updateAnimation() = 0;
            //p
            virtual Vector3f getPosition() const = 0;
            virtual void setPosition(Vector3f position) = 0;
            
            virtual Vector3f getRotation() const = 0;
            virtual void setRotation(Vector3f rotation) = 0;

            virtual Vector3f getSize() const = 0;
            virtual void setSize(Vector3f size) = 0;

        private:
            //your variables here
    };

} // namespace graphic3

#endif /* !IMODEL_HPP_ */