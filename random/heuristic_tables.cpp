#include <vector>
#include <iostream>

typedef std::vector<float> LookupTable;

LookupTable computeDistanceTable(int rows, int cols)
{
  LookupTable distance_lookup_table;
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      distance_lookup_table.push_back( i*i + j*j);
    }
  }
  return distance_lookup_table;
}


// Distance field based on row col and theta
// LookupTable computeDistanceTable(int rows, int cols, int dim_3)
// {
//   LookupTable distance_lookup_table;
//   for(int i = 0; i < rows; i++) {
//     for(int j = 0; j < cols; j++) {
//       for(int k = 0; k < dim_3; k++) {
//         distance_lookup_table.push_back( i*i + j*j);
//       }
//     }
//   }
//   return distance_lookup_table;
// }

LookupTable computeDistance(int x_size, int y_size, int bin_size)
{
  // Row major
  LookupTable distance_table;
  for(int x = -x_size; x <= x_size; x++) {
    for(int y = 0; y <= y_size; y++) {
      for (int bin = 0; bin < bin_size; bin++) {
        distance_table.push_back(x*x + y*y + bin*bin);
      }
    }
  }
  return distance_table;
}

int binDiff(int i, int f, int bin_size) {
  int diff = std::abs(f - i);
  if ( diff > bin_size / 2) {
    return bin_size % diff;
  }
  return diff;
};


int main()
{

  int x_size = 10;
  int y_size = 15;
  int bin_size = 20;

  // Distance table size 
  // (2 * x_size + 1) * (y_size +1) * (bin_size + 1)
  auto lookup_table = computeDistance(x_size, y_size, bin_size);

  // General form
  // index = (x + x_size) * (y_size + 1) * bin_size + y * bin_size + bin
  // std::cout << lookup_table[(5 + x_size)  * (y_size + 1) * bin_size + 5 * bin_size + 5] << std::endl;

  // x, y, bin
  int cur[3] = {0, 0, 5};
  int goal[3] = {5, -5, 0};

  // Bound between -x_size and x_size
  int x_rel = goal[0] - cur[0];

  // Bound between 0 and x_size
  int y_rel = goal[1] - cur[1];

  // Bound between 0 and bin_size
  int bin_rel = binDiff(goal[2], cur[2], bin_size);

  // Is the relative coords in the lookup table
  if ( std::abs(x_rel) <= x_size && std::abs(y_rel) <= y_size ) {

    // Check if y is negative, if so flip theta
    if( y_rel < 0) {
      if (bin_rel == bin_size / 2 && bin_rel != 0) {
        std::cout << "Don't flip: " << bin_size << std::endl;
      } else {
        // flipping
        std::cout << "Flipping: " << bin_rel << std::endl;
        bin_rel = bin_size - bin_rel;
        std::cout << "Bin Size: " << bin_size << std::endl;
        std::cout << "Flipping: " << bin_rel << std::endl;
      }
    }
      
    y_rel = std::abs(y_rel);

    std::cout << lookup_table[ ((x_rel + x_size) * (y_size + 1) * bin_size) + (y_rel * bin_size) + bin_rel] << std::endl;
  }


  // int bin = 7;
  // bin_size = 8;
  // if (bin == 0 || bin == bin_size / 2) {
  //   std::cout << "Not flipping" << std::endl;
  // } else {
  //   bin = bin_size - bin;
  // }
  // std::cout << bin << std::endl;
}


