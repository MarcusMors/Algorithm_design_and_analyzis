#include "../../Benchmark.hpp"
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using uint = unsigned int;
using cuint = const unsigned int;


template<class T> void f(Benchmark<T> &B, uint n)
{
  
  uint i = 3; b(0, 1);// 1
  while (b(1, n + 1 - 2) and i <= n) {
    
    uint j = i; b(2, n - 2);

    while (b(3, (n - 2) * (n + 1) + (n - 2) * (n - 1) / 2) and j <= 2 * n) {
      
      j++; b(4, (n - 2) * (n) + (n - 2) * (n - 1) / 2);
    }

    
    i++;b(5, n - 2);
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
