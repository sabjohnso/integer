#pragma once

//
// ... integer header files
//
#include <integer/details/base_types.hpp>
#include <integer/details/concepts.hpp>
#include <integer/details/import.hpp>

namespace integer::details {

   template<integral auto Bits, template<integral auto> class validation>
   struct wrapper {
      using value_type = integral_by_bit_count<Bits>;
      using validator = validation<Bits>;

      constexpr wrapper() { static_assert(validator::is_valid(value_type{})); }

      template<signed_integral U>
      constexpr wrapper(U input) : value_{validator::check(input)} {}

      constexpr operator value_type() const { return value_; }

      wrapper&
      operator+=(signed_integral auto input) {
         *this = value_ + input;
         return *this;
      }

      wrapper&
      operator-=(signed_integral auto input) {
         *this = value_ - input;
         return *this;
      }

      wrapper&
      operator*=(signed_integral auto input) {
         *this = value_ * input;
         return *this;
      }

      wrapper&
      operator/=(signed_integral auto input) {
         *this = value_ * input;
         return *this;
      }

      wrapper&
      operator%=(signed_integral auto input) {
         *this = value_ * input;
         return *this;
      }

      wrapper&
      operator<<=(signed_integral auto input) {
         *this = value_ << input;
         return *this;
      }

      wrapper&
      operator>>=(signed_integral auto input) {
         *this = value_ >> input;
         return *this;
      }

   private:
      value_type value_{};
   };

} // end of namespace integer::details
