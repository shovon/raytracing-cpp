#ifndef HITABLE_LIST_HPP
#define HITABLE_LIST_HPP

#include <vector>

#include "hitable.hpp"

class hitable_list : public hitable
{
public:
  hitable_list() {}
  hitable_list(std::vector<hitable *> list) : list{list} {};
  virtual bool hit(const ray &r, float t_min, float t_max, hit_record &rec) const;
  std::vector<hitable *> list;
};

#endif