#pragma once

//
// ... integer header files
//
#include <integer/details/import.hpp>

namespace integer::details {

   static constexpr auto bits_per_byte = 8;

   template<auto N>
   struct select_integer_by_byte_count {
      template<typename... Ts>
      struct recur {
         static_assert(
           sizeof...(Ts) > 0,
           "No signed integer type was found with the specified size!");
      };

      template<typename T, typename... Ts>
      struct recur<T, Ts...> : conditional_t<sizeof(T) == N, type_identity<T>, recur<Ts...>> {};

      using type = typename recur<int8_t, int16_t, int32_t, int64_t>::type;
   };

   template<auto Bytes>
   using integral_by_byte_count = typename select_integer_by_byte_count<Bytes>::type;

   template<auto Bits>
   using integral_by_bit_count = integral_by_byte_count<(Bits - 1) / bits_per_byte + 1>;

} // end of namespace integer::details
