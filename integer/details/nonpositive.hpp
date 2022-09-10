#pragma once

#include <integer/details/import.hpp>
#include <integer/details/validate_bounds.hpp>
#include <integer/details/wrapper.hpp>

namespace integer::details {

   template<integral auto Bits>
   struct nonpositive_bounds {
      using value_type = integral_by_bit_count<Bits>;
      static constexpr value_type inclusive_minimum = std::numeric_limits<value_type>::min();
      static constexpr value_type inclusive_maximum = 0;
   };

   template<integral auto Bits>
   using validate_nonpositive_with_exceptions =
     validate_bounds_with_exceptions<Bits, nonpositive_bounds>;

   template<integral auto Bits>
   using validate_nonpositive_with_assertions =
     validate_bounds_with_assertions<Bits, nonpositive_bounds>;

   template<integral auto Bits>
   using nonpositive = wrapper<Bits, validate_nonpositive_with_exceptions>;

   template<integral auto Bits>
   using nonpositive_with_assertions = wrapper<Bits, validate_nonpositive_with_assertions>;

} // end of namespace integer::details
