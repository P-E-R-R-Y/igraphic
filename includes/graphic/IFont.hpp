/**
 * @file IFont.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @date 2026-08-10
 *
 * @addtogroup igraphic
 * @{
 */

#ifndef IFONT_HPP_
    #define IFONT_HPP_

namespace graphic {

    /**
     * @brief Loaded font data, independent of any IText that references
     *        it. Deleting every IText built with a font does not delete
     *        the font - only deleteFont() does.
     * @interface IFont
     */
    class IFont {

        public:

            virtual ~IFont() = default;

            /**
             * @brief notice if the font is ready
             *
             * @return bool
             */
            virtual bool isReady() const = 0;
    };

} // namespace graphic

/** @} */

#endif /* !IFONT_HPP_ */
