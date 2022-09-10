#pragma once

#include <integer/details/import.hpp>
#include <integer/details/validate_bounds.hpp>
#include <integer/details/wrapper.hpp>

namespace integer::details {

   template<integral auto Bits>
   struct positive_bounds {
      using value_type = integral_by_bit_count<Bits>;
      static constexpr value_type inclusive_minimum = 1;
      static constexpr value_type inclusive_maximum = numeric_limits<value_type>::max();
   };

   template<integral auto Bits>
   using validate_positive_with_exceptions = validate_bounds_with_exceptions<Bits, positive_bounds>;

   template<integral auto Bits>
   using validate_positive_with_assertions = validate_bounds_with_assertions<Bits, positive_bounds>;

   template<integral auto Bits>
   using positive = wrapper<Bits, validate_positive_with_exceptions>;

   template<integral auto Bits>
   using positive_with_assertions = wrapper<Bits, validate_positive_with_assertions>;

} // namespace integer::details
