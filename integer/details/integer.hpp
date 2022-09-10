#pragma once

#include <integer/details/concepts.hpp>
#include <integer/details/import.hpp>
#include <integer/details/validate_bounds.hpp>
#include <integer/details/wrapper.hpp>

namespace integer::details {

   template<integral auto Bits>
   struct integer_bounds {
      using value_type = integral_by_bit_count<Bits>;
      static constexpr value_type inclusive_minimum = numeric_limits<value_type>::min();
      static constexpr value_type inclusive_maximum = numeric_limits<value_type>::max();
   };

   template<integral auto Bits>
   using validate_size_with_exceptions = validate_bounds_with_exceptions<Bits, integer_bounds>;

   template<integral auto Bits>
   using validate_size_with_assertions = validate_bounds_with_assertions<Bits, integer_bounds>;

   template<integral auto Bits>
   using integer = wrapper<Bits, validate_size_with_exceptions>;

   template<integral auto Bits>
   using integer_with_assertions = wrapper<Bits, validate_size_with_assertions>;

} // namespace integer::details
