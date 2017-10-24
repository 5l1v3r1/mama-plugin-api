#ifndef MAMA_IPARTICLE_H
#define MAMA_IPARTICLE_H

#include <utility>
#include <vector>

#include <opencv2/core.hpp>

#include <mama/MamaPluginAPI_export.h>

namespace mama {

/**
 * \brief Specifies the type of mask to use.
 */
enum class MaskType
{
    ORIGINAL,   ///< Uses the original mask.
    DILATED     ///< Uses the dilated mask.
};

/**
 * \brief Provides information about a particle to be analyzed.
 */
class MAMAPLUGINAPI_EXPORT IParticle
{
public:

    virtual ~IParticle();

    /**
     * \brief Returns the image chip.
     *
     * \return Single-channel \c float matrix containing the image chip.
     */
    virtual const cv::Mat& GetImage() const = 0;

    /**
     * \brief Returns the mask.
     *
     * \return Single-channel \c std::uint8_t matrix containing the mask.
     */
    virtual const cv::Mat& GetMask() const = 0;

    /**
     * \brief Returns the dilated mask.
     *
     * \return Single-channel \c std::uint8_t matrix containing the mask dilated
     * by a 3x3 ellipse. If an error occurred during the calculation, returns an
     * empty matrix.
     */
    virtual const cv::Mat& GetDilatedMask() const = 0;

    /**
     * \brief Returns the eroded mask.
     *
     * \return Single-channel \c std::uint8_t matrix containing the mask eroded
     * by a 3x3 ellipse. If an error occurred during the calculation, returns an
     * empty matrix.
     */
    virtual const cv::Mat& GetErodedMask() const = 0;

    /**
     * \brief Returns the boundary points.
     *
     * \return Boundary points, calculated as the difference between the dilated
     * mask and the eroded mask. If an error occurred during the calculation,
     * returns an empty vector.
     */
    virtual const std::vector<cv::Point>& GetBoundaryPoints() const = 0;

    /**
     * \brief Returns the best-fit ellipse.
     *
     * \return Best-fit ellipse, calculated as if by
     * <tt>cv::fitEllipse(GetBoundaryPoints())</tt>. If an error occurred
     * during the calculation, returns an empty ellipse.
     */
    virtual const cv::RotatedRect& GetEllipse() const = 0;

    /**
     * \brief Returns the contours of the specified mask.
     *
     * \param maskType Mask to use.
     * \return Contours of the specified mask, calculated as if by
     * \c cv::findContours. If an error occurred during the calculation, returns
     * an empty vector.
     */
    virtual const std::vector<cv::Point>& GetContours(MaskType maskType = MaskType::ORIGINAL) const = 0;

    /**
     * \brief Returns the convex hull of the specified mask.
     *
     * \param maskType Mask to use.
     * \return Convex hull of the specified mask, calculated as if by
     * \c cv::convexHull. If an error occurred during the calculation, returns
     * an empty vector.
     */
    virtual const std::vector<cv::Point>& GetConvexHull(MaskType maskType = MaskType::ORIGINAL) const = 0;

    virtual const std::pair<double, double>& GetDiameters() const = 0;

    virtual const std::vector<double>& GetHue() const = 0;
};

} // namespace mama

#endif
