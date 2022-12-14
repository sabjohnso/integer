#pragma once

//
// ... integer header files
//
#include <integer/details/import.hpp>
#include <integer/details/validate_bounds.hpp>
#include <integer/details/wrapper.hpp>

namespace integer::details {

   template<integral auto Bits>
   struct nonnegative_bounds {
      using value_type = integral_by_bit_count<Bits>;
      static constexpr value_type inclusive_minimum = 0;
      static constexpr value_type inclusive_maximum = std::numeric_limits<value_type>::max();
   };

   template<integral auto Bits>
   using validate_nonnegative_with_exceptions =
     validate_bounds_with_exceptions<Bits, nonnegative_bounds>;

   template<integral auto Bits>
   using validate_nonnegative_with_assertions =
     validate_bounds_with_assertions<Bits, nonnegative_bounds>;

   template<integral auto Bits>
   using nonnegative = wrapper<Bits, validate_nonnegative_with_exceptions>;

   template<integral auto Bits>
   using nonnegative_with_assertions = wrapper<Bits, validate_nonnegative_with_assertions>;

} // namespace integer::details
