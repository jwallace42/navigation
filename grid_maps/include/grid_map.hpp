#ifndef GRIDMAP
#define GRIDMAP

#include "types.hpp"
#include <eigen3/Eigen/Core>

namespace grid_map
{

template<typename T>
class GridMap 
{
  public:

  typedef Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> Matrix;

  /**
   * @Brief Constructor
   * @param rows The length of the gridmap in cells
   * @param cols The width of the gridmap in cells
   * @param value The value to set the gridmap
   */
  GridMap(int rows, int cols, float resolution, T value)
  {
    rows_ = rows;
    cols_ = cols;
    resolution_ = resolution;

    matrix_.resize(rows, cols);
    matrix_.setConstant(value);
  }

  /**
   * @brief Set a value in the grid
   * @param Index The index of the cell to set
   * @param value The new value of the cell
   */
  void setValue(Index i, T value)
  {
    matrix_(i[0], i[1]) = value;
  }

  /**
   * @brief Set a value in grid
   * @param Index The index of the value to get
   */
  T getValue(Index i)
  {
    return matrix_(i[0], i[1]);
  }

  /**
   * @brief Get read and write access to matrix
   */
  Matrix& getMatrix()
  {
    return matrix_;
  }

  /**
   * @brief Get only read access to the matrix
   */
  const Matrix& getMatrix() const {
    return matrix_;
  }

private:
  Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> matrix_;

  // Length in cells
  int rows_;

  // Width in cells
  int cols_;

  // Resolution m/cell
  float resolution_;

  // The current position 
  Position current_pos_;
};

} // grid_map

#endif // GRIDMAP
