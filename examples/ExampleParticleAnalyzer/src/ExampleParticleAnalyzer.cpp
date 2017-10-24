#include <memory>
#include <string>

#include <cppmicroservices/BundleActivator.h>
#include <cppmicroservices/BundleContext.h>
#include <cppmicroservices/ServiceProperties.h>
#include <opencv2/imgproc.hpp>

#include <mama/IParticleAnalyzer.h>

using namespace cppmicroservices;
using namespace mama;

// Implementation of the IParticleAnalyzer service.
class ParticleAnalyzer : public IParticleAnalyzer
{
public:

    virtual double Analyze(const IParticle& particle, const IRuler& ruler, const IDictionary& options) override
    {
        // Calculate vector area
        double vectorArea = cv::contourArea(particle.GetContours());

        if (options.GetBool(IParticleAnalyzer::VECTOR_BIAS_CORRECTION_ENABLED)) {
            // If vector bias correction is enabled, calculate the vector area
            // again using a dilated mask and then average the two
            double dilatedVectorArea = cv::contourArea(particle.GetContours(MaskType::DILATED));
            vectorArea = (vectorArea + dilatedVectorArea) / 2.0;
        }

        // Convert to micrometers
        return ruler.ConvertArea(vectorArea);
    }
};

// Bundle activator
class Activator : public BundleActivator
{
public:

    virtual void Start(BundleContext context) override
    {
        // Set service properties
        ServiceProperties properties;
        properties[IParticleAnalyzer::NAME] = std::string("Example Attribute"); // Required
        properties[IParticleAnalyzer::UNIT] = std::string("um^2");

        // Register service
        context.RegisterService<IParticleAnalyzer>(std::make_shared<ParticleAnalyzer>(), properties);
    }

    virtual void Stop(BundleContext context) override
    {
        // Service is automatically unregistered
    }
};

CPPMICROSERVICES_EXPORT_BUNDLE_ACTIVATOR(Activator)
