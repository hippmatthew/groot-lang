set(GROOT_ENGINE_VERSION_MINOR 0)
set(GROOT_ENGINE_VERSION_PATCH 0)

project(GrootLang::Engine
  VERSION "${GROOT_ENGINE_VERSION_MINOR}.${GROOT_ENGINE_VERSION_PATCH}"
  LANGUAGES CXX
)

find_package(Vulkan REQUIRED)

set(GROOT_ENGINE_INCLUDES
  ${CMAKE_CURRENT_SOURCE_DIR}/include/engine.hpp
)

set(GROOT_ENGINE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/engine.cpp
)

add_library(groot.engine STATIC ${GROOT_ENGINE_INCLUDES} ${GROOT_ENGINE_SOURCES})

target_compile_definitions(groot.engine PRIVATE
  "GLFW_INCLUDE_NONE"
  "VULKAN_HPP_NO_CONSTRUCTORS"
)

target_include_directories(groot.engine PRIVATE
  ${CMAKE_SOURCE_DIR}
  /usr/local/include
  ${GROOT_GLFW_INCLUDE_DIR}
  ${GROOT_GLM_INCLUDE_DIR}
)

target_link_libraries(groot.engine PRIVATE
  Vulkan::Vulkan
  ${GROOT_GLFW_LIB}
)