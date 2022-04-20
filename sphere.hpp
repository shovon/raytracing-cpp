#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "hitable.hpp"

class sphere : public hitable
{
public:
  sphere() {}
  sphere(vec3 cen, float r, material *mat_ptr) : center{cen},
                                                 radius{r},
                                                 mat_ptr{mat_ptr} {}
  virtual bool hit(const ray &r, float tmin, float tmax, hit_record &rec) const;

  vec3 center;
  float radius;
  material *mat_ptr;
};

#endif