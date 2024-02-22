#include "grid_map.hpp"
#include <cassert>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
#include <math.h>
#include <map>
#include <numeric>

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

constexpr float MaxFloat = std::numeric_limits<float>::max();
constexpr int MaxIterations = 1000;

struct Node 
{
  // The 1d index
  int index{0};

  // The current cost of the node g(n)
  float g_cost{MaxFloat};

  // The heuristic cost of the node f(n) = g(n) + f(n)
  float f_cost{MaxFloat};

  // If true node is in the closed set
  bool visited{false};

  // If current queued
  bool queued{false};

  // Parent
  Node * parent{nullptr};
};

typedef std::map<int, Node> Graph;
typedef std::vector<Node*> Queue;

// Custom comparator
struct CostComparator
{
    bool operator()(const Node *lhs, const Node *rhs) const
    {
        return lhs->f_cost > rhs->f_cost;
    }
};

float heuristic(int row, int col, int start_row, int start_col)
{
    return std::sqrt( (row - start_row) * (row - start_row) + (col - start_col) * (col - start_col));
}

void backtrace(const Node * goal, const Graph &graph) 
{
    const Node * current = goal;

    while (current->parent != nullptr) {
        std::cout << goal->index << std::endl;
        current = current->parent;
    }
}

using namespace grid_map;

int main() {

    // Set the envornmental model
    int m = 7;
    int n = 4;
    int grid_size = 7 * 4;
    GridMap<double> grid_map(7, 4, 1.0f, 1.0f);
    Index index(1, 1);
    grid_map.setValue(index, 10);

    // Four connected
    int action_space[4] = {1, -1, n, -n};

    // Graph 
    Graph graph;

    // Add start to the graph
    int s_i = flattenIndex(1, 1, n);
    graph.insert({s_i, {s_i, 0.0}});

    int start_row;
    int start_col;
    expandIndex(s_i, n, start_row, start_col);

    // Add goal to the graph
    int g_i = flattenIndex(5, 6, n);
    graph.insert({g_i, {g_i}});

    Queue open_set;
    std::make_heap(open_set.begin(), open_set.end(), CostComparator());

    // Add start to queue
    open_set.push_back(&graph[s_i]);

    // Preallocate vars
    int iter = 0;

    int row, col;
    int new_row, new_col;

    while(!open_set.empty() && iter < MaxIterations) {
        Node * cur = open_set.front();

        if (cur->index == g_i) {
            // Found solution
            backtrace(cur, graph);
        }
        
        // move the lowest cost to the back
        std::pop_heap(open_set.begin(), open_set.end(), CostComparator());

        // pop the lowest cost from the elment list
        open_set.pop_back();

        if (cur->visited) {
            continue;
        }

        cur->visited = true;

        expandIndex(cur->index, n, row, col); 
        for (const int & action : action_space) {
            int new_idx = cur->index + action;

            if (new_idx < grid_size) {
                continue;
            }

            expandIndex(new_idx, n, new_row, new_col);

            // Bounds check
            if (col == 0 && new_col >= n -1 || col >= n-1 && new_col == 0) {
                continue;
            }

            if (row == 0 && new_row >= m -1 || row >= m -1 && new_row == 0) {
                continue;
            }

            // Get pointer to the new index in the graph
            Node * neighbor;
            if(graph.find(new_idx) != graph.end()) {
                neighbor = &graph[new_idx];
            } else {
                graph.insert({new_idx, {new_idx, false, MaxFloat}});
                neighbor = &graph[new_idx];
            }

            if(neighbor->visited) {
                continue;
            }

            // Add some collision checking here

            // Remove graph[] and just cache
            float new_g_cost = cur->g_cost + 1;
            if (new_g_cost < cur->g_cost) {
                neighbor->parent = cur;
                neighbor->g_cost = new_g_cost;
                neighbor->f_cost = new_g_cost + heuristic(new_row, new_col, start_row, start_col);
                if (!cur->queued) {
                    std::push_heap(open_set.begin(), open_set.end(), CostComparator());
                    cur->queued = true;
                }
            }
        }
    }


    return 0;
}

