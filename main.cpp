#include <iostream>

#include "vec3.hpp"

int main()
{
  auto nx = 200;
  auto ny = 100;
  std::cout << "P3\n"
            << nx << " " << ny << "\n255" << std::endl;

  for (auto j = ny - 1; j >= 0; j--)
  {
    for (int i = 0; i < nx; i++)
    {
      vec3 col(float(i) / float(nx), float(j) / float(ny), 0.2);
      auto ir = int(255.99 * col.e0);
      auto ig = int(255.99 * col.e1);
      auto ib = int(255.99 * col.e2);
      std::cout << ir << " " << ig << " " << ib << std::endl;
    }
  }
}