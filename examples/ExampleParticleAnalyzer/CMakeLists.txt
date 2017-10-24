#-------------------------------------------------------------------------------
# ExampleParticleAnalyzer
#
# Example Mama plugin that adds a new particle analysis algorithm.
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.0)

project(
    ExampleParticleAnalyzer
    VERSION 1.0.0
)

#-------------------------------------------------------------------------------
# Build bundle
#-------------------------------------------------------------------------------

set(_extra_srcs)
usFunctionGetResourceSource(TARGET ExampleParticleAnalyzer OUT _extra_srcs)
usFunctionGenerateBundleInit(TARGET ExampleParticleAnalyzer OUT _extra_srcs)

add_library(
    ExampleParticleAnalyzer MODULE
    src/ExampleParticleAnalyzer.cpp
    ${_extra_srcs}
)

target_compile_definitions(
    ExampleParticleAnalyzer
    PRIVATE
        US_BUNDLE_NAME=${PROJECT_NAME}
)

target_compile_features(
    ExampleParticleAnalyzer
    PRIVATE
        cxx_override
)

target_link_libraries(
    ExampleParticleAnalyzer
    PRIVATE
        CppMicroServices
        MamaPluginAPI
        opencv_imgproc
)

set_target_properties(
    ExampleParticleAnalyzer
    PROPERTIES
        CXX_VISIBILITY_PRESET hidden
        PREFIX ""
        US_BUNDLE_NAME ${PROJECT_NAME}
        VISIBILITY_INLINES_HIDDEN ON
)

usFunctionEmbedResources(
    TARGET ExampleParticleAnalyzer
    WORKING_DIRECTORY resources
    FILES manifest.json
)

#-------------------------------------------------------------------------------
# Install bundle
#-------------------------------------------------------------------------------

install(
    TARGETS ExampleParticleAnalyzer
    LIBRARY DESTINATION bin
)
