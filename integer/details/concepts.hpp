#pragma once

//
// ... integer header files
//
#include <integer/details/import.hpp>

namespace integer::details {

   template<typename U, typename V>
   concept bigger_than = signed_integral<U> && signed_integral<V> && sizeof(U) > sizeof(V);

   template<typename U, typename V>
   concept not_bigger_than = signed_integral<U> && signed_integral<V> && not bigger_than<U, V>;

   template<typename T>
   concept validity = true;

} // namespace integer::details
