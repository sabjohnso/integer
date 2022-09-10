#pragma once

//
// ... integer header files
//
#include <integer/details/base_types.hpp>
#include <integer/details/concepts.hpp>
#include <integer/details/import.hpp>

namespace integer::details {

   template<integral auto Bits, template<integral auto> class Bounds>
   struct validate_bounds_with_exceptions : Bounds<Bits> {
      using value_type = integral_by_bit_count<Bits>;
      using bounds = Bounds<Bits>;

      template<signed_integral U>
      static constexpr bool
      is_valid(U input) {
         return input <= U(bounds::inclusive_maximum) && input >= U(bounds::inclusive_minimum);
      }

      static constexpr value_type
      check(signed_integral auto input) {
         return is_valid(input) ? value_type(input)
                                : throw logic_error(
                                    "Attempt to set an integer value with an input "
                                    "that is too big");
      }
   };

   template<integral auto Bits, template<integral auto> class Bounds>
   struct validate_bounds_with_assertions : Bounds<Bits> {
      using value_type = integral_by_bit_count<Bits>;
      using bounds = Bounds<Bits>;

      template<signed_integral U>
      static constexpr bool
      is_valid(U input) {
         return input <= U(bounds::inclusive_maximum) && input >= U(bounds::inclusive_minimum);
      }

      static constexpr value_type
      check(signed_integral auto input) {
         assert(is_valid(input));
         return value_type(input);
      }
   };
} // end of namespace integer::details
