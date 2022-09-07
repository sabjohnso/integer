find_package(GTest)

macro(integer_add_test test_name exe_name)
  add_executable(${exe_name} ${ARGN})
  target_link_libraries(${exe_name} PRIVATE
    integer::header
    GTest::gtest_main)
  set_target_properties(${exe_name}
    PROPERTIES
    CXX_STANDARD ${integer_CXX_STANDARD})
  add_test(${test_name} ${exe_name})
endmacro()
