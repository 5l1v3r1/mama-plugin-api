#-------------------------------------------------------------------------------
# MamaPluginAPI
#
# Defines interfaces implemented by Mama and its plugins. Mama plugins must link
# to this library.
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.0)

project(
    MamaPluginAPI
    VERSION 1.0.0
)

#-------------------------------------------------------------------------------
# Define options
#-------------------------------------------------------------------------------

option(BUILD_EXAMPLES "Build example plugins" OFF)

#-------------------------------------------------------------------------------
# Find dependencies
#-------------------------------------------------------------------------------

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(CppMicroServices 3.0 REQUIRED)
find_package(OpenCV 3.1 REQUIRED COMPONENTS core)

#-------------------------------------------------------------------------------
# Build library
#-------------------------------------------------------------------------------

add_library(
    MamaPluginAPI SHARED
    include/mama/IDictionary.h
    include/mama/IParticle.h
    include/mama/IParticleAnalyzer.h
    include/mama/IRuler.h
    src/IDictionary.cpp
    src/IParticle.cpp
    src/IParticleAnalyzer.cpp
    src/IRuler.cpp
)

target_compile_features(
    MamaPluginAPI
    PUBLIC
        cxx_strong_enums
)

target_include_directories(
    MamaPluginAPI
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
)

target_link_libraries(
    MamaPluginAPI
    PUBLIC
        opencv_core
)

set_target_properties(
    MamaPluginAPI
    PROPERTIES
        CXX_VISIBILITY_PRESET hidden
        DEBUG_POSTFIX d
        VISIBILITY_INLINES_HIDDEN ON
)

#-------------------------------------------------------------------------------
# Install library
#-------------------------------------------------------------------------------

install(
    TARGETS MamaPluginAPI
    EXPORT MamaPluginAPITargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION bin
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(
    DIRECTORY include/
    DESTINATION include
)

install(
    EXPORT MamaPluginAPITargets
    DESTINATION lib/cmake/MamaPluginAPI
)

#-------------------------------------------------------------------------------
# Generate export header
#-------------------------------------------------------------------------------

include(GenerateExportHeader)

generate_export_header(
    MamaPluginAPI
    EXPORT_FILE_NAME include/mama/MamaPluginAPI_export.h
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/include/mama/MamaPluginAPI_export.h
    DESTINATION include/mama
)

#-------------------------------------------------------------------------------
# Generate package configuration files
#-------------------------------------------------------------------------------

include(CMakePackageConfigHelpers)

configure_package_config_file(
    cmake/MamaPluginAPIConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/MamaPluginAPIConfig.cmake
    INSTALL_DESTINATION lib/cmake/MamaPluginAPI
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/MamaPluginAPIConfigVersion.cmake
    COMPATIBILITY SameMajorVersion
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/MamaPluginAPIConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/MamaPluginAPIConfigVersion.cmake
    DESTINATION lib/cmake/MamaPluginAPI
)

#-------------------------------------------------------------------------------
# Build examples
#-------------------------------------------------------------------------------

if(BUILD_EXAMPLES)
    add_subdirectory(examples/ExampleParticleAnalyzer)
endif()
