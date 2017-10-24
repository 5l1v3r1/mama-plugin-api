#ifndef MAMA_IPARTICLEANALYZER_H
#define MAMA_IPARTICLEANALYZER_H

#include <string>

#include <mama/IDictionary.h>
#include <mama/IParticle.h>
#include <mama/IRuler.h>
#include <mama/MamaPluginAPI_export.h>

namespace mama {

/**
 * \brief Particle analysis algorithm that calculates a single, scalar-valued
 * attribute.
 */
class MAMAPLUGINAPI_EXPORT IParticleAnalyzer
{
public:

    /**
     * \brief Service property specifying the calculated attribute's name.
     *
     * This property is required. This property's value is a \c std::string.
     */
    static const std::string NAME;

    /**
     * \brief Service property specifying the calculated attribute's unit.
     *
     * This property's value is a \c std::string.
     */
    static const std::string UNIT;

    /**
     * \brief Option specifying whether vector bias correction is enabled.
     *
     * When \c false, use the original mask (this is the typical way commercial
     * tools implement attributes but it introduces a bias into vector
     * estimates, e.g. perimeter, convex attributes etc.). When \c true, correct
     * for vectorization bias using an average of mask and dilated mask.
     *
     * This option's value is a \c bool.
     */
    static const std::string VECTOR_BIAS_CORRECTION_ENABLED;

    virtual ~IParticleAnalyzer();

    /**
     * \brief Analyzes the specified particle.
     *
     * \param particle Particle to analyze.
     * \param ruler Converts measurements in pixels to micrometers.
     * \param options Particle analysis options.
     * \return Calculated attribute value.
     */
    virtual double Analyze(const IParticle& particle, const IRuler& ruler, const IDictionary& options) = 0;
};

} // namespace mama

#endif
