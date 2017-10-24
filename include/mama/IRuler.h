#ifndef MAMA_IRULER_H
#define MAMA_IRULER_H

#include <mama/MamaPluginAPI_export.h>

namespace mama {

/**
 * \brief Converts measurements in pixels to micrometers.
 */
class MAMAPLUGINAPI_EXPORT IRuler
{
public:

    virtual ~IRuler();

    /**
     * \brief Converts a length in pixels to micrometers.
     *
     * \param pixels Length in pixels.
     * \return Length converted to micrometers.
     */
    virtual double ConvertLength(double pixels) const = 0;

    /**
     * \brief Converts an area in square pixels to square micrometers.
     *
     * \param pixels Area in square pixels.
     * \return Area converted to square micrometers.
     */
    virtual double ConvertArea(double pixels) const = 0;
};

} // namespace mama

#endif
