#include <limits>
#include <queue>
#include <stack>
#include <map>


// 2.2.1 General forward search for 2d
// +---+---+---+---+
// |   |   |   |   |
// +---+---+---+---+
// |   |   |   |   |
// +---+---+---+---+
// |   |   |   |   |
// +---+---+---+---+
// |   |   |   |   |
// +---+---+---+---+
// |   |   |   |   |
// +---+---+---+---+


// util methods

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

// Constants
constexpr float MaxFloat = std::numeric_limits<float>::max();
constexpr int MaxIterations = 1000;

struct Node 
{
   // The 1d index
   int index{-1};

   // f(n)
   float f_cost{MaxFloat};

   bool visited{false};

   bool queued{false};

   Node * parent{nullptr};
};

typedef std::map<int, Node> Graph;
std::stack<Node *> Alive;


// struct CostComparator
// {
//     bool operator()(const Node *lhs, const Node *rhs) const
//     {
//         return lhs->f_cost > rhs->f_cost;
//     }
// };

int main()
{
   // The number of rows, jmax
   // The number of cols, imax
   int m = 6;
   int n = 10;

   int action_space[4] = {1, -1, n, -n};

   // Graph
   Graph graph;


}








