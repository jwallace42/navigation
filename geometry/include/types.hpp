#include <vector>

namespace geometry
{
  struct Point 
  {
    Point(float x, float y);

    float x{0};
    float y{0};
  };

  typedef std::vector<Point> Points;

  struct Pose
  {
    Pose(Point point, float yaw = 0);
    Pose(float x, float y, float yaw);

    float x;
    float y;
    float yaw;
  };
  typedef std::vector<Pose> Poses;

} // geometry

    
