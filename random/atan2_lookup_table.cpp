#include <cmath>
#include <vector>
#include <iostream>
#include <math.h>

typedef std::vector<float> LookupTable;

/**
 * @brief Create a atan2 lookup table
 * @param dim_size The size of the dimension
 * @return LookupTable A 1d lookup table
 */
LookupTable computeLookupTable(int dim_size)
{
  // Col major lookup table
  LookupTable lookup_table;
  int index = 0;
  for(int x = -dim_size; x <= dim_size; x++) {
    for(int y = -dim_size; y <= dim_size; y++) {
      if( x == 0 && y == 0) {
        lookup_table.push_back(-1.0f);
      } else {
        lookup_table.push_back(atan2(y,x));
      }
      // std::cout << index << " " << x << " " << y << " " << atan2(y,x) << std::endl;
      index++;
    }
  }
  std::cout << index << std::endl;
  return lookup_table;
}

int main()
{
  int dim_size = 10;
  auto table = computeLookupTable(dim_size);

  for(int x = -dim_size; x <= dim_size; x++) {
    for(int y = -dim_size; y <= dim_size; y++) {
      int index = (x + dim_size) * (2 * dim_size + 1) + (y + dim_size);
      if (x == 0 && y == 0) {
        continue;
      }
      if (std::abs(atan2(y,x) - table[index]) > 1e-3) {
        std::cout << "Fail" << std::endl;
      }
    }
  }
}

// LookupTable computeLookupTable(int x_dim, int y_dim)
// {
//   // Col major lookup table
//   LookupTable lookup_table;
//   int index = 0;
//   for(int x = -x_dim; x <= x_dim; x++) {
//     for(int y = -y_dim; y <= y_dim; y++) {
//       if( x == 0 && y == 0) {
//         lookup_table.push_back(-1.0f);
//       } else {
//         lookup_table.push_back(atan2(y,x));
//       }
//       std::cout << index << " " << x << " " << y << " " << atan2(y,x) << std::endl;
//       index++;
//     }
//   }
//   std::cout << index << std::endl;
//   return lookup_table;
// }
//
// int main()
// {
//   int x_diff = -3;
//   int y_diff = 3;
//   int size = 10;
//
//   int x_dim = 10;
//   int y_dim = 10;
//
//   auto table = computeLookupTable(x_dim, y_dim);
//   std::cout << "Table: " << table.size() << std::endl;
//
//   int index = (x_diff + x_dim) * (2 * y_dim + 1) + (y_diff + y_dim);
//   std::cout << "index: " << index << std::endl;
//     
//   std::cout << table[index] * (180 / 3.1415) << std::endl;
//   std::cout << atan2(y_diff,x_diff) * (180 / 3.1415) << std::endl;
// }
//
//
//
//
//
//
//
//
//
//
//
//
//
