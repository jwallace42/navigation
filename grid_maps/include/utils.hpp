#ifndef UTILS
#define UTILS

#include <iomanip>
#include <iostream>
#include "types.hpp"

namespace grid_map
{
  /**
   * @brief Convert a grid map index to a position
   * @param index The index to convert
   * @param resolution The resolution of the grid
   * @return Position The resulting position
   */
  inline Position indexToPosition(const Index & index, float resolution)
  {
    return {index[0] * resolution, index[1] *resolution};
  }

  /**
   * @brief Convert a position to a index
   * @param position The position to convert
   * @param float The resolution of the grid
   * @return Index The resulting index
   */
  inline Index positionToIndex(const Position & position, float resolution)
  {
    return {position[0] / resolution, position[1] / resolution};
  }

}

#endif
