/**
 * @file IText.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @date 2025-02-01
 * 
 * @addtogroup graphic
 */


#ifndef ITEXT_HPP_
    #define ITEXT_HPP_

    #include "Type.hpp"
    #include <string>

namespace graphic {

    /**
     * @brief Text interface
     * 
     * @interface IText
     */
    class IText {

        public:

            /**
             * @brief Destroy the IText object
             * 
             */
            virtual ~IText() = default;

            virtual bool isReady() const = 0;

            /**
             * @brief Set the Text value
             * 
             * @param text 
             */
            virtual void setText(const std::string text) = 0;

            /**
             * @brief Get the Text value
             * 
             * @return std::string 
             */
            virtual std::string getText() const = 0;

            /**
             * @brief Set the Font value
             * 
             * @param font 
             */
            virtual void setFont(std::string path) = 0;

            /**
             * @brief Set the Font Size text
             * 
             * @param size 
             */
            virtual void setFontSize(unsigned int size) = 0;

            /**
             * @brief Get the Font Size text
             * 
             * @return unsigned int 
             */
            virtual unsigned int getFontSize() const = 0;

            /**
             * @brief Set the Text Color text
             * 
             * @param color 
             */
            virtual void setTextColor(Color color) = 0;

            /**
             * @brief Get the Text Color text
             * 
             * @return Color 
             */
            virtual Color getTextColor() const = 0;

            /**
             * @brief Set the Position text
             * 
             * @param position 
             */
            virtual void setPosition(Vector2f position) = 0;

            /**
             * @brief Get the Position text
             * 
             * @return Vector2f 
             */
            virtual Vector2f getPosition() const = 0;

            /**
             * @brief Set the Rotation object
             * 
             * @param angle 
             */
            virtual void setRotation(float angle) = 0;

            /**
             * @brief Get the Rotation object
             * 
             * @return float 
             */
            virtual float getRotation() const = 0;

    };

}

#endif /* !ITEXT_HPP_ */