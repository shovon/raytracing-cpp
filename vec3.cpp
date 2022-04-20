#include "vec3.hpp"

inline vec3 vec3::unit_vector()
{
  return (*this) / this->length();
}