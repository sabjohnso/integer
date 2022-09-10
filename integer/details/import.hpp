#pragma once

//
// ... standard header files
//
#include <concepts>
#include <cstdint>
#include <limits>
#include <stdexcept>

namespace integer::details {
   using std::conditional_t;
   using std::integral;
   using std::logic_error;
   using std::numeric_limits;
   using std::same_as;
   using std::signed_integral;
   using std::type_identity;

   using std::int16_t;
   using std::int32_t;
   using std::int64_t;
   using std::int8_t;

} // end of namespace integer::details
