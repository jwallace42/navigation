#include <iostream>

// Taken from wikipedia
void plotLowPoints(int x0, int y0, int x1, int y1) 
{
  int dx = x1 - x0;
  int dy = y1 - y0;

  int yi = 1;
  if (dy < 0) {
    yi = -1;
    dy = -dy;
  }
  int D = ( 2 * dy ) - dx;
  int y = y0;

  for (int x = x0; x <= x1; ++x) {
    std::cout << x << " " << y << std::endl;
    if (D > 0) {
      y = y + yi;
      D = D + (2 * (dy -dx));
    } else {
      D = D + 2 * dy;
    }
  }
}

void plotHighPoints(int x0, int y0, int x1, int y1)
{
  int dx = x1 - x0;
  int dy = y1 - y0;

  int xi = 1;
  if (dx < 0){
    xi = -1;
    dx = -dx;
  }
  int D = (2 * dx) - dy;
  int x = x0;

  for (int y = y0; y <= y1; ++y) {
    std::cout << x << " " << y << std::endl;
    if (D > 0) {
      x = x + xi;
      D = D + (2 * (dx -dy));
    } else {
      D = D + 2 * dx;
    }
  }
}
void plotPoints(int x0, int y0, int x1, int y1) 
{

  // Edge cases
  if (x0 == x1 && y0 != y1) {
    std::cout << "Edge case 1: " << std::endl;
    for(int y = y0; y <= y1; ++y) {
      std::cout << x0 << " " << y << std::endl;
    }
    return;
  }

  if (x0 != x1 && y0 == y1) {
    std::cout << "Edge case 2: " << std::endl;
    for(int x = x0; x < x1; ++x) {
      std::cout << x << " " << y0 << std::endl;
    }
    return;
  }


  if (x0 == x1 && y0 == y1) {
    std::cout << "Edge case 3: " << std::endl;
    std::cout << x0 << " " << y0 << std::endl;
    return;
  }


  std::cout << "General: " << std::endl;
  // Add optimizations for x0 == x1 && y0 == y1
  if ( std::abs(y1 - y0) < std::abs(x1 - x0) ) {
    if (x0 > x1) {
      plotLowPoints(x1, y1, x0, y0);
    } else {
      plotLowPoints(x0, y0, x1, y1);
    }
  } else {
    if (y0 > y1) {
      plotHighPoints(x1, y1, x0, y0);
    } else {
      plotHighPoints(x0, y0, x1, y1);
    }
  }
}

int main()
{
  int x0 = 0;
  int y0 = 0;

  int x1 = 7;
  int y1 = 3;

  plotPoints(x0, y0, x1, y1);
}


