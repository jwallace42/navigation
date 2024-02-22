#include <algorithm>
#include <cmath>
#include "grid_map.hpp"

namespace grid_map
{
    // template<typename T>
    // GridMap::GridMap<typename T>(int length, int width, float resolution, T value)
    // {}
    // template<typename T>
    // GridMap::GridMap(int length, int width, float resolution, T value)
    // {
    //     length_ = length;
    //     width_ = width;
    //     resolution_ = resolution;
    //     data_.resize(length * width, value);
    // }

    // Iterates though the whole grid and copies the cells that are needed
    // How slow is this?....
//     bool GridMap::moveTo(const Position & position)
//     {
//         Index delta_x = std::round((position.x - pos_.x) / resolution_);
//         Index delta_y = std::round((position.y - pos_.y) / resolution_);
//
//         if (std::abs(delta_x) < 1 && std::abs(delta_y) < 1 ) {
//             return false;
//         }
//
//         if (delta_x >= length_ || delta_y >= width_) {
//             std::fill(data_.begin(), data_.end(), 0.0f);
//         }
//
//         GridData buffer = data_;
//
//         for(Index row = 0; row < width_; ++row) {
//          for(Index col = 0; col < length_; ++col) {
//              Index new_row = row - delta_y;
//              Index new_col = col - delta_x;
//
//              if (new_row >= width_ || new_row < 0) {
//                  setValue(row, col, 0.0f);
//                  continue;
//              }
//
//              if (new_col >= length_ || new_col < 0) {
//                  setValue(row, col, 0.0f);
//                  continue;
//              }
//
//              const auto buffer_value = buffer[new_row * length_ + new_col];
//              setValue(row, col, buffer_value);
//          }
//         }
//         setPositionTo(position);
//         return true;
//     }
} // grid_map
