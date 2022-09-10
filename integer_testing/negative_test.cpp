//
// ... testing header files
//
#include <gtest/gtest.h>

//
// ... integer header files
//
#include <integer/integer.hpp>

namespace integer::testing {
   TEST(negative, default_compile_time_construction) {
      constexpr negative<16> i{};
      static_assert(i == -1);
   }

   TEST(negative, compile_time_construction) {
      constexpr negative<16> i{-3};
      static_assert(i == -3);
   }

   TEST(negative, default_construction) {
      negative<16> i{};
      ASSERT_EQ(i, -1);
   }

   TEST(negative, construction) {
      negative<16> i{-3};
      ASSERT_EQ(i, -3);
   }

   TEST(nonnegative, construction_nonpermissible_value) {
      ASSERT_THROW([] { negative<16> i{0}; }(), std::logic_error);
   }

   TEST(nonnegative, compound_assignment_with_permissible_result) {
      negative<16> i{-52};
      i -= 100;
      ASSERT_EQ(i, -152);
   }

   TEST(nonnegative, compound_assignment_with_nonpermissible_result) {
      negative<16> i{};
      ASSERT_THROW(i -= i;, std::logic_error);
   }
} // end of namespace integer::testing
