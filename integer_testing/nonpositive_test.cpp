//
// ... Testing header files
//
#include <gtest/gtest.h>

//
// ... integer header files
//
#include <integer/integer.hpp>

namespace integer::testing {

   TEST(nonpositive, default_compile_time_construction) {
      constexpr nonpositive<16> i{};
      static_assert(i == 0);
   }

   TEST(nonpositive, compile_time_construction) {
      constexpr nonpositive<16> i{-3};
      static_assert(i == -3);
   }

   TEST(nonpositive, compile_time_arrithmetic) {
      constexpr nonpositive<16> i{-4};
      constexpr nonpositive<16> j{-3};
      constexpr nonpositive<16> k = i + j;
      static_assert(k == -7);
   }

   TEST(nonpositive, default_construction) {
      nonpositive<16> i{};
      ASSERT_EQ(i, 0);
   }

   TEST(nonpositive, construction) {
      nonpositive<16> i{-3};
      ASSERT_EQ(i, -3);
   }

   TEST(nonpositive, construction_nonpermissible_value) {
      ASSERT_THROW([] { nonpositive<16> i{1}; }(), std::logic_error);
   }

   TEST(nonpositive, compound_assignment_with_permissible_result) {
      nonpositive<16> i{-52};
      i -= 100;
      ASSERT_EQ(i, -152);
   }

   TEST(nonpositive, compound_assignment_with_nonpermissible_result) {
      nonpositive<16> i{};
      ASSERT_THROW(i += 5;, std::logic_error);
   }

} // end of namespace integer::testing
