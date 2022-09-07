cmake_minimum_required(VERSION 3.12)

project(integer VERSION 0.1.0 LANGUAGES C CXX)

option(integer_BUILD_TESTING "Build the integer tests" ON)
set(integer_CXX_STANDARD 20 CACHE STRING "C++ standard for integer")

include(GNUInstallDirs)
set(integer_INSTALL_BINDIR ${CMAKE_INSTALL_BINDIR})
set(integer_INSTALL_LIBDIR ${CMAKE_INSTALL_LIBDIR})
set(integer_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_INCLUDEDIR})
set(integer_INSTALL_CONFDIR ${integer_INSTALL_LIBDIR}/cmake/integer-${PROJECT_VERSION})

list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake)
include(integer_deps)

add_subdirectory(integer)

if(integer_BUILD_TESTING)
  include(CTest)
  if(BUILD_TESTING)
    add_subdirectory(integer_testing)
  endif()
endif()

install(EXPORT integer_EXPORTS
  NAMESPACE integer::
  FILE integer-exports.cmake
  DESTINATION ${integer_INSTALL_CONFDIR})

configure_file(integer-config.cmake.in integer-config.cmake)
install(FILES ${PROJECT_BINARY_DIR}/integer-config.cmake
  DESTINATION ${integer_INSTALL_CONFDIR})
