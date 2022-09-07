configure_file(config.hpp.in config.hpp)

add_library(integer_header INTERFACE)
set_target_properties(integer_header PROPERTIES EXPORT_NAME header)
target_include_directories(integer_header
  INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<INSTALL_INTERFACE:${integer_INSTALL_INCLUDEDIR}>)

add_library(integer::header ALIAS integer_header)
  
install(TARGETS integer_header
  EXPORT integer_EXPORTS
  RUNTIME DESTINATION ${integer_INSTALL_BINDIR}
  LIBRARY DESTINATION ${integer_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${integer_INSTALL_LIBDIR})

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  DESTINATION ${integer_INSTALL_INCLUDEDIR}/integer)
