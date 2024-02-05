#include <iostream>
#include <eigen3/Eigen/Core>
#include "grid_map.hpp"
#include "utils.hpp"

using namespace grid_map;

int main() {

    GridMap<double> grid_map(7, 4, 1.0f, 1.0f);
    Index index(1,1);
    grid_map.setValue(index, 10);
    auto matrix = grid_map.getMatrix();
    std::cout << grid_map.getMatrix() << std::endl;



    // grid_map.setPositionTo({0.0f, 0.0f});
    // display(grid_map);
    // grid_map.moveTo({1.0f, 1.0f});
    // display(grid_map);
    // grid_map.moveTo({3.0f, 3.0f});
    // display(grid_map);
    //
    return 0;
}

