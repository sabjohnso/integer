#pragma once

#include <integer/details/import.hpp>
#include <integer/details/validate_bounds.hpp>
#include <integer/details/wrapper.hpp>

namespace integer::details {

   template<integral auto Bits>
   struct negative_bounds {
      using value_type = integral_by_bit_count<Bits>;
      static constexpr value_type inclusive_minimum = std::numeric_limits<value_type>::min();
      static constexpr value_type inclusive_maximum = -1;
   };

   template<integral auto Bits>
   using validate_negative_with_exceptions = validate_bounds_with_exceptions<Bits, negative_bounds>;

   template<integral auto Bits>
   using validate_negative_with_assertions = validate_bounds_with_assertions<Bits, negative_bounds>;

   template<integral auto Bits>
   using negative = wrapper<Bits, validate_negative_with_exceptions>;

   template<integral auto Bits>
   using negative_with_assertions = wrapper<Bits, validate_negative_with_assertions>;

} // end of namespace integer::details
