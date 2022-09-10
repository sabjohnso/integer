#pragma once

//
// ... integer header files
//
#include <integer/details/concepts.hpp>
#include <integer/details/import.hpp>
#include <integer/details/validate_bounds.hpp>

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
   using validte_nonnegative_assertions = validate_bounds_with_assertions<Bits, nonnegative_bounds>;

} // namespace integer::details
