#include <cassert>
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <math.h>





// Graph map<int, Node>
// Node: 
// x, y, cost, index
//
// obstacle map
// obs, closed, empty, start, goal
//
//

enum class State 
{
  kObs,
  kClosed,
  kEmpty,
  kStart,
  kGoal
};

struct Info 
{
  // Current
  int x{-1};
  int y{-1};

  // Neighbor x,y
  int x_n{-1};
  int y_n{-1};

  float current_cost{std::numeric_limits<float>::max()};
  float heuristic_cost{std::numeric_limits<float>::max()};
  State state{State::kEmpty};
};

bool compareInfo(const Info *lhs, const Info *rhs)
{
  return lhs->current_cost + lhs->heuristic_cost > rhs->current_cost + rhs->heuristic_cost;
}

typedef std::vector<std::vector<Info>> Graph;
typedef std::vector<Info*> Queue;

// [x,y]
int action_space[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void backtrace(Info * goal, const Graph & graph)
{
  const Info * current = goal;
  std::cout << current->x << " " << current->y << std::endl;
  while(current->x_n != -1 && current->y_n != -1) {
    std::cout << current->x_n << " " << current->y_n << std::endl;
    current = &graph[current->x_n][current->y_n];
  }
}


// Currently dikstra implementation
int main()
{
  // Populate the graph
  int rows = 10;
  int cols = 10;
  Graph graph;
  for(int i = 0; i < rows; i++) {
    std::vector<Info> row;
    for(int j = 0; j < cols; j++) {
      row.push_back({i, j, -1, -1, std::numeric_limits<float>::max(), 0.0, State::kEmpty});
    }
    graph.push_back(row);
  }

  int goal[2] = {5, 5};
  int start[2] = {2, 2};

  // 1) Set the start and goal
  graph[start[0]][start[1]].state = State::kStart;
  graph[start[0]][start[1]].current_cost = 0.0f;
  // graph[start[0]][start[1]].heuristic_cost = std::sqrt(std::abs(start[0] - goal[0]) + std::abs(goal[0] - goal[1]));

  graph[5][5].state = State::kGoal;

  // 2) Add initial value to priority queue
  Queue queue;
  queue.push_back(&graph[2][2]);

  int iter = 0;
  while(!queue.empty() && iter < 100) {
    // 3.1) Pop front from queue, add to closed set
    std::sort(queue.begin(), queue.end(), compareInfo);
    Info * current = queue.back();
    queue.pop_back();
    std::cout << "Current: " << current->x << " " << current->y << " " << current->current_cost + current->heuristic_cost << std::endl;

    iter++;

    // Allow for requeing
    if (current->state == State::kClosed) {
      continue;
    }

    // 3.2) Check if at the goal, if found backtrace and return result
    if(current->state == State::kGoal) {
      std::cout << "Solution found" << std::endl;
      backtrace(current, graph);
      return 0;
    }

    // 3.3 Add neighbors to the queue
    for(const auto & action : action_space) {
      int x_new = current->x + action[0];
      int y_new = current->y + action[1];

      if (x_new >= rows || x_new < 0) {
        continue;
      }

      if (y_new >= cols || y_new < 0) {
        continue;
      }

      if(graph[x_new][y_new].state == State::kClosed) {
        continue;
      }

      if (graph[x_new][y_new].state == State::kObs) {
        continue;
      }

      float new_current_cost = current->current_cost + 1.0f;
      float new_heuristic_cost = std::sqrt(std::abs(x_new - goal[0]) + std::abs(y_new - goal[1]));

      if (new_current_cost < graph[x_new][y_new].current_cost) {
        graph[x_new][y_new].current_cost = new_current_cost;
        graph[x_new][y_new].heuristic_cost = new_heuristic_cost;
        graph[x_new][y_new].x_n = current->x;
        graph[x_new][y_new].y_n = current->y;

        queue.push_back(&graph[x_new][y_new]);
      }
    }
  }
  std::cout << "FAILURE" << std::endl;
}
