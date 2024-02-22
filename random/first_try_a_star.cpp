#include <cassert>
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <math.h>
#include <map>



/**
 * @brief Flatten the 2d index to 1 d 
 * @param i The row
 * @param j The col
 * @param n The size of a row
 * @return int The 1d index
 */
int flattenIndex(int i, int j, int n)
{
  return i * n + j;
}

/**
 * @brief Expand the 1d index to 2d
 * @param index The 1d index
 * @param n The size of a row
 * @param i The row of the 2d index
 * @param j The col of the 2d index
 */
void expandIndex(int index, int n, int &i, int &j)
{
  i = index / n;
  j = index - (n * i); 
}

struct Node 
{
  // The 1d index
  int index;

  // If true node is in the closed set
  bool visited;

  // The current cost of the node
  float accumulated_cost;
};

typedef std::map<int, Node> Graph;





// Graph map<int, Node>
// Node: 
// x, y, cost, index
//
// obstacle map
// obs, closed, empty, start, goal
//
//
//
//



// Obstacle configuration
//
// Graph 
// [index, node]
//
// Node 
// index (unique index for the node, need mapping from index to x,y and vis versa)
// accumulated cost (cost from the start to the current pose)
// heuristic cost (estimate of the cost to the goal)
// visited (If true this node is part of the closed set)
// queued (does double queuing matter?)
//
// Priority Queue: Open set, fringe, frontier
// [*node1, *node2, ....., *nodeN]
//
// Action Space 
// [action1, action2, ......,actionN]
//

// enum class State 
// {
//   kObs,
//   kClosed,
//   kEmpty,
//   kStart,
//   kGoal
// };
//
// struct Info 
// {
//   // Current
//   int x{-1};
//   int y{-1};
//
//   // Neighbor x,y
//   int x_n{-1};
//   int y_n{-1};
//
//   float current_cost{std::numeric_limits<float>::max()};
//   float heuristic_cost{std::numeric_limits<float>::max()};
//   State state{State::kEmpty};
// };
//
// bool compareInfo(const Info *lhs, const Info *rhs)
// {
//   return lhs->current_cost + lhs->heuristic_cost > rhs->current_cost + rhs->heuristic_cost;
// }
//
// typedef std::vector<std::vector<Info>> Graph;
// typedef std::vector<Info*> Queue;
//
// // [x,y]
// int action_space[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//
// void backtrace(Info * goal, const Graph & graph)
// {
//   const Info * current = goal;
//   std::cout << current->x << " " << current->y << std::endl;
//   while(current->x_n != -1 && current->y_n != -1) {
//     std::cout << current->x_n << " " << current->y_n << std::endl;
//     current = &graph[current->x_n][current->y_n];
//   }
// }
//
//
// int main()
// {
//   // Populate the graph
//   int rows = 10;
//   int cols = 10;
//   Graph graph;
//   for(int i = 0; i < rows; i++) {
//     std::vector<Info> row;
//     for(int j = 0; j < cols; j++) {
//       row.push_back({i, j, -1, -1, std::numeric_limits<float>::max(), 0.0, State::kEmpty});
//     }
//     graph.push_back(row);
//   }
//
//   int goal[2] = {5, 5};
//   int start[2] = {2, 2};
//
//   // 1) Set the start and goal
//   graph[start[0]][start[1]].state = State::kStart;
//   graph[start[0]][start[1]].current_cost = 0.0f;
//
//   graph[5][5].state = State::kGoal;
//
//   // 2) Add initial value to priority queue
//   Queue queue;
//   queue.push_back(&graph[2][2]);
//
//   int iter = 0;
//   while(!queue.empty() && iter < 100) {
//     // 3.1) Pop front from queue, add to closed set
//     std::sort(queue.begin(), queue.end(), compareInfo);
//     Info * current = queue.back();
//     queue.pop_back();
//     std::cout << "Current: " << current->x << " " << current->y << " " << current->current_cost + current->heuristic_cost << std::endl;
//
//     iter++;
//
//     // Allow for requeing
//     if (current->state == State::kClosed) {
//       continue;
//     }
//
//     // 3.2) Check if at the goal, if found backtrace and return result
//     if(current->state == State::kGoal) {
//       std::cout << "Solution found" << std::endl;
//       backtrace(current, graph);
//       return 0;
//     }
//
//     // 3.3 Add neighbors to the queue
//     for(const auto & action : action_space) {
//       int x_new = current->x + action[0];
//       int y_new = current->y + action[1];
//
//       if (x_new >= rows || x_new < 0) {
//         continue;
//       }
//
//       if (y_new >= cols || y_new < 0) {
//         continue;
//       }
//
//       if(graph[x_new][y_new].state == State::kClosed) {
//         continue;
//       }
//
//       if (graph[x_new][y_new].state == State::kObs) {
//         continue;
//       }
//
//       float new_current_cost = current->current_cost + 1.0f;
//       float new_heuristic_cost = std::sqrt(std::abs(x_new - goal[0]) + std::abs(y_new - goal[1]));
//
//       if (new_current_cost < graph[x_new][y_new].current_cost) {
//         graph[x_new][y_new].current_cost = new_current_cost;
//         graph[x_new][y_new].heuristic_cost = new_heuristic_cost;
//         graph[x_new][y_new].x_n = current->x;
//         graph[x_new][y_new].y_n = current->y;
//
//         queue.push_back(&graph[x_new][y_new]);
//       }
//     }
//   }
//   std::cout << "FAILURE" << std::endl;
// }
