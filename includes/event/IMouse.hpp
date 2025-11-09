/**
 * @file IMouse.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @date 2025-09-24
 * 
 * @addtogroup graphic
 * @{
 */

#ifndef IMOUSE_HPP_
#define IMOUSE_HPP_
  
#include "Type.hpp"

namespace graphic {

    /**
     * @brief Mouse interface
     * @interface IMouse
     */
    class IMouse {

        public:
          
            /**
             * @brief Destroy the IMouse interface
             */
            virtual ~IMouse() = default;

            enum Buttons {
                  BUTTON_LEFT,
                  BUTTON_RIGHT,
                  BUTTON_MIDDLE,

                  EXTRA_BUTTON_1,
                  EXTRA_BUTTON_2,
            };
            
            /**
             * @brief notice if a button is pressed
             * 
             * @param key 
             * @return true 
             * @return false 
             */
            virtual bool isButtonPressed(Buttons key) const = 0;

            /**
             * @brief notice if a button is down
             * 
             * @param key 
             * @return true 
             * @return false 
             */
            virtual bool isButtonDown(Buttons key) const = 0;

            /**
             * @brief notice if a button is released
             * 
             * @param key 
             * @return true 
             * @return false 
             */
            virtual bool isButtonReleased(Buttons key) const = 0;

            /**
             * @brief notice if a button is up
             * 
             * @param key 
             * @return true 
             * @return false 
             */
            virtual bool isButtonUp(Buttons key) const = 0;
            
            /**
             * @brief get the position of the mouse
             * 
             * @return Vector2f 
             */
            virtual Vector2f getPosition() const = 0;
            
            /**
             * @brief set the position of the mouse
             * 
             * @param position 
             */
            virtual void setPosition(Vector2f position) = 0;
            
            /**
             * @brief get the mouse wheel move
             * 
             * @return float 
             */
            virtual float GetMouseWheelMove() const = 0;
    };

} // namespace graphic3

#endif /* !IMOUSE_HPP_ */