#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
#include <algorithm>
#include <iomanip>


// Shitty distance field implementation

struct Node 
{
  // Index of the node
  int row;
  int col;

  // Index of the obstacle node
  int src_row;
  int src_col;

  bool visited;
  float distance;
};


void print(const std::vector<std::vector<Node>> & nodes)
{
  for(const auto & row : nodes) {
    for(const auto & node : row) {
      if (node.distance > 100) {
        std::cout << "inf" << " ";
      }else {
        std::cout << std::left << std::setw(7) << std::setfill(' ') << node.distance << " ";
      }
    }
    std::cout << std::endl;
  }
}

int main()
{
  std::vector<std::vector<Node>> nodes;
  int action_space[4][2] = 
  {{ 1, 0},
  { 0, 1},
  {-1, 0},
  { 0, -1}};

  // Size the vector
  int rows = 20;
  int cols = 20;
  nodes.resize(rows);
  for (int row = 0; row < rows; row++) {
    nodes[row].resize(cols);
  }

  // Initialize nodes
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      nodes[row][col] = {row, col, -1, -1, false, std::numeric_limits<float>::max()};
    }
  }

  // Set the 6 by 6 node to be a lethal node
  nodes[6][6].src_row = 6;
  nodes[6][6].src_col = 6;
  nodes[6][6].distance = 0.0;


  nodes[14][14].src_row = 14;
  nodes[14][14].src_col = 14;
  nodes[14][14].distance = 0.0;

  // Place it into the queue to start
  // The queue is sorted by distance
  std::vector<Node*> queue;
  queue.push_back(&nodes[6][6]);
  queue.push_back(&nodes[14][14]);


  while(!queue.empty()) {
    // Pop off the lowest distance value in the queue
    Node * cur = queue.back();
    queue.pop_back();

    if ( cur->visited) {
      continue;
    }

    // Vist the cell
    cur->visited = true;

    // Add neighbors to the queue
    for(int i = 0; i < 4; i++) {
      // Just one neigbor for now
      int new_row = cur->row + action_space[i][0];
      int new_col = cur->col + action_space[i][1];

      // Bounds check
      if (new_row >= rows || new_row < 0) {
        continue;
      }

      if (new_col >= cols || new_col < 0 ) {
        continue;
      }

      // Don't queue something that has already been visited
      if (nodes[new_row][new_col].visited) {
        continue;
      }

      // Calculate the new distance
      float drow = (new_row - cur->src_row) * (new_row - cur->src_row);
      float dcol = (new_col - cur->src_col) * (new_col - cur->src_col);

      float distance = cur->distance + 1;

      if (distance < nodes[new_row][new_col].distance) {
        // Set the src node and distance
        nodes[new_row][new_col].src_row = cur->src_row;
        nodes[new_row][new_col].src_col = cur->src_col;
        nodes[new_row][new_col].distance = distance;
      }

      // Add to queue and sort
      queue.push_back(&nodes[new_row][new_col]);
    }

    std::sort(queue.begin(), queue.end(), [](Node * a, Node * b) { return a->distance > b->distance; });

  }
  print(nodes);
}
