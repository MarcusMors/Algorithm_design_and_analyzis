#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using uint = unsigned int;
using cuint = const unsigned int;

template<class T1, class T2> void print_table(std::vector<T1> measured, std::vector<T2> expected, unsigned n)
{
  cout << "n: " << n << endl;
  cout << std::setw(7) << "i|";
  cout << std::setw(11) << "measured|";
  cout << std::setw(11) << "expected|" << endl;

  for (uint i = 0; i < measured.size(); i++) {
    if (measured[i] == -1) { break; }
    cout << std::setw(6) << i << "|";
    cout << std::setw(10) << measured[i] << "|";
    cout << std::setw(10) << expected[i] << "|";
    cout << endl;
  }

  auto t_measured = std::accumulate(measured.begin(), measured.end(), 0);
  auto t_expected = std::accumulate(expected.begin(), expected.end(), 0);

  cout << std::setw(7) << "total|";
  cout << std::setw(10) << t_measured << "|";
  cout << std::setw(10) << t_expected << "|";
  cout << endl;
  //
}

class benchmark
{
  std::vector<int> measured;
  std::vector<int> expected;
  int max_i = -1;
  benchmark()
  {
    measured.resize(1000, 0);
    expected.resize(1000, 0);
  }
  void print_table();
  //
};

template<class T1> void f(uint n, T1 a)
{
  a(0, 1);// 1
  uint i = 1;
  while (a(1, n + 1 - 2) and i <= n) {
    a(2, n - 2);
    uint j = 1;
    while (a(3, 0) and j <= i) {
      a(4, (n - 2) * (n) + (n - 2) * (n - 1) / 2);
      j++;
    }
    a(5, n - 2);
    i++;
  }
  // 3n^2-3n-4
}

int main()
{
  uint n = 10;
  std::vector<int> measured(1000, 0);
  std::vector<int> expected(1000, 0);
  int max_i = -1;
  auto a = [&](int i, int expected_complexity = 0) {
    if (i > max_i) { max_i = i; }
    measured[i]++;
    expected[i] = expected_complexity;
    return true;
  };

  f(n, a);
  max_i++;
  measured.resize(max_i);
  expected.resize(max_i);

  print_table(measured, expected, n);
}
