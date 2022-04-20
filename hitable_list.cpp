#include "hitable_list.hpp"
#include "hitable.hpp"

bool hitable_list::hit(const ray &r, float t_min, float t_max, hit_record &rec) const
{
  hit_record temp_rec;
  bool hit_anything = false;
  float closest_so_far = t_max;
  for (auto &item : list)
  {
    if (item->hit(r, t_min, closest_so_far, temp_rec))
    {
      hit_anything = true;
      closest_so_far = temp_rec.t;
      rec = temp_rec;
    }
  }
  return hit_anything;
}