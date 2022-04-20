#include <iostream>

#include "vec3.hpp"

float rand_min_max(float min, float max)
{
  return min + drand48() * (max - min);
}

vec3 random_vec3_min_max(float min, float max)
{
  vec3 v = {
      rand_min_max(min, max),
      rand_min_max(min, max),
      rand_min_max(min, max)};
  return v;
}

vec3 random_in_unit_sphere()
{
  vec3 p;
  while (true)
  {
    p = random_vec3_min_max(-1, 1);
    if (p.dot(p) >= 1)
    {
      continue;
    }
    break;
  }
  return p;
}

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