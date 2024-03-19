#include "Benchmark.hpp"
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using uint = unsigned int;
using cuint = const unsigned int;


template<class T> void f(Benchmark<T> &B, uint n)
{
  b(0, 1);// 1
  uint i = 3;
  while (b(1, n + 1 - 2) and i <= n) {
    b(2, n - 2);
    uint j = i;
    while (b(3, (n - 2) * (n + 1) + (n - 2) * (n - 1) / 2) and j <= 2 * n) {
      b(4, (n - 2) * (n) + (n - 2) * (n - 1) / 2);
      j++;
    }

    b(5, n - 2);
    i++;
  }
  // 3n^2-3n-4
}

int main()
{
  // simplify
  // 3n*n - 3*n - 4
  // 300 - 30 - 4
  uint n = 10;
  Benchmark b{ n };

  f(b, n);
  b.print_table();
}
