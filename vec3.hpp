#ifndef VEC3_HPP
#define VEC3_HPP

#include <iostream>
#include <cmath>

struct vec3
{
  vec3() {}
  vec3(float e0, float e1, float e2) : e0{e0}, e1{e1}, e2{e2} {}

  float x() { return e0; }
  float y() { return e1; }
  float z() { return e2; }

  friend std::ostream &operator<<(std::ostream &os, const vec3 &v);
  vec3 &operator+=(const vec3 &v);
  vec3 &operator-=(const vec3 &v);
  vec3 &operator*=(const vec3 &v);
  vec3 &operator*=(const float t);
  vec3 &operator/=(const vec3 &v);
  vec3 &operator/=(const float t);
  const vec3 &operator+() const { return *this; }
  const vec3 operator-() const { return vec3(-e0, -e2, -e2); }
  float dot(const vec3 &v) const
  {
    return v.e0 * e0 + v.e1 * e1 + v.e2 * e2;
  }
  vec3 cross(const vec3 &v)
  {
    return vec3(
        e1 * v.e2 - e2 * v.e1,
        -(e0 * v.e2 - e2 * v.e1),
        e0 * v.e1 - e1 * v.e0);
  }
  float length()
  {
    return sqrt(dot(*this));
  }
  vec3 unit_vector();

  float e0;
  float e1;
  float e2;
};

vec3 operator+(const vec3 &v1, const vec3 &v2);
vec3 operator-(const vec3 &v1, const vec3 &v2);
vec3 operator*(const vec3 &v1, const vec3 &v2);
vec3 operator*(const vec3 &v, float t);
vec3 operator*(float t, const vec3 &v);
vec3 operator/(const vec3 &v, float t);

vec3 random_in_unit_sphere();

#endif