//
// ... Testing header files
//
#include <gtest/gtest.h>

//
// ... integer header files
//
#include <integer/integer.hpp>

namespace integer::testing {

   TEST(nonnegative, default_compile_time_construction) {
      constexpr nonnegative<16> i{};
      static_assert(i == 0);
   }

   TEST(nonnegative, compile_time_construction) {
      constexpr nonnegative<16> i{3};
      static_assert(i == 3);
   }

   TEST(nonnegative, compile_time_arrithmetic) {
      constexpr nonnegative<16> i{4};
      constexpr nonnegative<16> j{3};
      constexpr nonnegative<16> k = i + j;
      static_assert(k == 7);
   }

   TEST(nonnegative, default_construction) {
      nonnegative<16> i{};
      ASSERT_EQ(i, 0);
   }

   TEST(nonnegative, construction) {
      nonnegative<16> i{3};
      ASSERT_EQ(i, 3);
   }

   TEST(nonnegative, construction_nonpermissible_value) {
      ASSERT_THROW([] { nonnegative<16> i{-1}; }(), std::logic_error);
   }

   TEST(nonnegative, compound_assignment_with_permissible_result) {
      nonnegative<16> i{52};
      i += 100;
      ASSERT_EQ(i, 152);
   }

   TEST(nonnegative, compound_assignment_with_nonpermissible_result) {
      nonnegative<16> i{};
      ASSERT_THROW(i -= 5;, std::logic_error);
   }

} // end of namespace integer::testing
