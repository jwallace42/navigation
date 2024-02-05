#include <iostream>
#include <vector>
#include <array>


struct Point 
{
  float x;
  float y;
};


std::vector<int> intersection(int a, int b, int c, int d) {
  std::vector<int> result;

  if (a > b) std::swap(a,b);
  if (c > d) std::swap(c,d);

  if (std::max(a,c) <= std::min(b,d)) {
    result.push_back(std::max(a,c));
    result.push_back(std::min(b,d));
  }

  return result;
}


int main()
{
  auto x = intersection(0, 4, 5, 10);
  for(const auto & value : x) {
    std::cout << value << std::endl;
  }

  auto y = intersection(0, 4, 5, 10);
  for(const auto & value : y) {
    std::cout << value << std::endl;
  }

  if (x.empty() || y.empty() ) {
    std::cout << "no intersection" << std::endl;
  }
}

