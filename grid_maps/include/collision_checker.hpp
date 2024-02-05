#ifndef COLLISION_CHECKER
#define COLLISION_CHECKER

#include <optional>
#include "grid_map.hpp"

namespace grid_map {

template<typename T>
class CollisionChecker
{
  public:
  /**
   * @brief Constructor
   * @param grid_map A refernce to the grid map used for collision checking
   * @param footprint A footprint centered around 0 0
   */
  CollisionChecker(const GridMap<T> &grid_map, const Polygon &footprint);

  /**
   * @brief Collision check
   * @param footprint The footprint to check
   * @return Indexes The indexes that are in collision
   */
  std::optional<Indexes> inCollision();


  private:
  Polygon footprint;

};

}  // grid_map

#endif  // COLLISION_CHECKER
