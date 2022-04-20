#include <iostream>

#include "vec3.hpp"

std::ostream &operator<<(std::ostream &os, const vec3 &v)
{
  os << v.e0 << ", " << v.e1 << ", " << v.e2;
  return os;
}

vec3 vec3::unit_vector()
{
  return (*this) / this->length();
}

vec3 &vec3::operator+=(const vec3 &v)
{
  e0 += v.e0;
  e1 += v.e1;
  e2 += v.e2;
  return *this;
}

vec3 &vec3::operator-=(const vec3 &v)
{
  e0 -= v.e0;
  e1 -= v.e1;
  e2 -= v.e2;
  return *this;
}

vec3 &vec3::operator*=(const vec3 &v)
{
  e0 *= v.e0;
  e1 *= v.e1;
  e2 *= v.e2;
  return *this;
}

vec3 &vec3::operator*=(const float t)
{
  e0 *= t;
  e1 *= t;
  e2 *= t;
  return *this;
}

vec3 &vec3::operator/=(const vec3 &v)
{
  e0 /= v.e0;
  e1 /= v.e1;
  e2 /= v.e2;
  return *this;
}

vec3 &vec3::operator/=(const float t)
{
  e0 /= t;
  e1 /= t;
  e2 /= t;
  return *this;
}

vec3 operator+(const vec3 &v1, const vec3 &v2)
{
  return vec3(v1.e0 + v2.e0, v1.e1 + v2.e1, v1.e2 + v2.e2);
}

vec3 operator-(const vec3 &v1, const vec3 &v2)
{
  return vec3(v1.e0 - v2.e0, v1.e1 - v2.e1, v1.e2 - v2.e2);
}

vec3 operator*(const vec3 &v1, const vec3 &v2)
{
  return vec3(v1.e0 * v2.e0, v1.e1 * v2.e1, v1.e2 * v2.e2);
}

vec3 operator*(const vec3 &v, float t)
{
  return vec3(v.e0 * t, v.e1 * t, v.e2 * t);
}

vec3 operator*(float t, const vec3 &v)
{
  return v * t;
}

vec3 operator/(const vec3 &v, float t)
{
  return v * (1 / t);
}