#ifndef HITABLE_HPP
#define HITABLE_HPP

#include "vec3.hpp"
#include "ray.hpp"

struct hit_record
{
  float t;
  vec3 p;
  vec3 normal;
};

class hitable
{
public:
  virtual bool hit(
      const ray &r,
      float t_min,
      float t_max,
      hit_record &rec) const = 0;
};

#endif