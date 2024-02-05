#include <vector>
#include <eigen3/Eigen/Core>

#ifndef TYPES
#define TYPES

namespace grid_map 
{
  // Index[0] row
  // Index[1] col
  typedef Eigen::Array2i Index;
  typedef std::vector<Index> Indexes;

  // Position[0] x
  // Position[0] y
  typedef Eigen::Vector2d Position;
  typedef Eigen::Vector2d Point;
  typedef std::vector<Point> Points;

  // How do we want to represent a polygon
  // Want to transform polygon
  // Want to get size of polygon
  //


  class Polygon
  {
    public:
      Polygon(const Points & points);

      /**
       * @brief Compute the inscribed circle of the polygon
       * @param polygon The polygon used to compute the inscribed circle
       * @return Polygon A polygon that represents a inscribed circle
       */
      static Polygon computeInCircle(const Polygon & polygon);

      /**
       * @brief Compute the circumscribed circle of the polygon
       * @param polygon The polygon used to compute the circumscribed circle
       * @return Polygon A polygon that represents a circumscribed circle
       */
      static Polygon computeCirCircle(const Polygon & polygon);

      /**
       * @brief Compute the bounding box of a polygon
       * @param polygon The polygon to compute the bounding box
       * @return Polygon A polygon that represnts the bounding box
       */
      static Polygon computeBoundingBox(const Polygon & polygon);

    private:
      Points vertices_;

  };

}

#endif // TYPES

