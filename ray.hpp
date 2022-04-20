#ifndef RAY_HPP
#define RAY_HPP

#include "vec3.hpp"

struct ray
{
  ray() {}
  ray(const vec3 &a, const vec3 &b) : a{a}, b{b} {}
  vec3 origin() const { return a; }
  vec3 direction() const { return b; }

  vec3 a;
  vec3 b;
}

#endif