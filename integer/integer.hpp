#pragma once

//
// ... integer header files
//
#include <integer/details/concepts.hpp>
#include <integer/details/integer.hpp>
#include <integer/details/negative.hpp>
#include <integer/details/nonnegative.hpp>
#include <integer/details/nonpositive.hpp>
#include <integer/details/positive.hpp>
#include <integer/details/wrapper.hpp>

namespace integer {

   using details::validate_nonnegative_with_exceptions;
   using details::validate_size_with_assertions;
   using details::validate_size_with_exceptions;

   using details::wrapper;

   using details::integer;
   using details::integer_with_assertions;

   using details::nonnegative;
   using details::nonnegative_with_assertions;

   using details::positive;
   using details::positive_with_assertions;

   using details::nonpositive;
   using details::nonpositive_with_assertions;

   using details::negative;
   using details::negative_with_assertions;

} // end of namespace integer
