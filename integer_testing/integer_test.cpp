//
// ... standard header files
//
#include <cstdint>
#include <limits>
#include <stdexcept>

//
// ... Testing header files
//
#include <gtest/gtest.h>

//
// ... integer header files
//
#include <integer/integer.hpp>

namespace integer::testing {

   TEST(integer, default_compile_time_construction) {
      constexpr integer<16> i{};
      static_assert(i == 0);
   };

   TEST(integer, default_construction) {
      integer<16> i{};
      ASSERT_EQ(i, 0);
   };

   TEST(integer, construction_from_permissible_value) {
      integer<16> i{52};
      ASSERT_EQ(i, 52);
   }

   TEST(integer, construction_from_nonpermissible_value) {
      ASSERT_THROW(
        [] { integer<16> i{std::numeric_limits<std::int32_t>::max()}; }(),
        std::logic_error);
   }

   TEST(integer, assignment_from_permissible_value) {
      integer<16> i{};
      i = 73;
      ASSERT_EQ(i, 73);
   }

   TEST(integer, assignment_from_nonpermissible_value) {
      integer<16> i{};
      ASSERT_THROW([ & ] { i = std::numeric_limits<std::int32_t>::max(); }(), std::logic_error);
   }

   TEST(integer, compound_assignment_with_permissible_result) {
      integer<16> i{52};
      i += 100;
      ASSERT_EQ(i, 152);
   }

   TEST(integer, compound_assignment_with_nonpermissible_result) {
      integer<16> i{std::numeric_limits<std::int16_t>::max()};
      ASSERT_THROW([ & ] { i += 5; }(), std::logic_error);
   }

} // end of namespace integer::testing
