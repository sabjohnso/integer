#pragma once

//
// ... integer header files
//
#include <integer/details/base_types.hpp>
#include <integer/details/concepts.hpp>
#include <integer/details/import.hpp>

namespace integer::details {

   template<integral auto Bits>
   struct validate_size_with_exceptions {
      using value_type = integral_by_bit_count<Bits>;
      template<bigger_than<value_type> U>
      static constexpr bool
      is_valid(U input) {
         return input <= U(numeric_limits<value_type>::max());
      }

      static constexpr bool
      is_valid(not_bigger_than<value_type> auto) {
         return true;
      }

      static constexpr value_type
      check(signed_integral auto input) {
         return is_valid(input) ? value_type(input)
                                : throw logic_error(
                                    "Attempt to set an integer value with an input "
                                    "that is too big");
      }
   };

   template<integral auto Bits>
   struct validate_size_with_assertions {
      using value_type = integral_by_bit_count<Bits>;
      template<bigger_than<value_type> U>
      static constexpr bool
      is_valid(U input) {
         return input <= U(numeric_limits<value_type>::max());
      }

      static constexpr bool
      is_valid(not_bigger_than<value_type> auto) {
         return true;
      }

      static constexpr value_type
      check(signed_integral auto input) {
         assert(is_valid(input));
         return value_type(input);
      }
   };

} // end of namespace integer::details
