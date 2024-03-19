#include "Benchmark.hpp"
#include <iostream>

using namespace std;

// int hanoi(int i, int j, int k, Benchmark &b)
// {
//   if (n > 0) {
//     hanoi(n - 1, i, k, j);
//     mover(i, j);
//     hanoi(n - 1, k, j, i);
//   } else {
//     mover(i, j);
//   }
// }

// int g(int t, Benchmark &b)
// {
//   if (t == 0) {
//   } else {
//     mover(i, j);
//   }
// }

int main()
{
  Benchmark b;
  g(10, 10, 10, b);
  cout << "Hello world\n";
  return 0;
}
