#include <mama/IParticleAnalyzer.h>

#include <string>

namespace mama {

const std::string IParticleAnalyzer::NAME("mama.particleAnalyzer.name");
const std::string IParticleAnalyzer::UNIT("mama.particleAnalyzer.unit");

const std::string IParticleAnalyzer::VECTOR_BIAS_CORRECTION_ENABLED("mama.particleAnalyzer.vectorBiasCorrectionEnabled");

IParticleAnalyzer::~IParticleAnalyzer()
{
}

} // namespace mama
