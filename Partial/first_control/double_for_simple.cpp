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

template<class T> void f(uint n, T a)
{
  a(0, 1);
  uint i = 1;
  while (a(1, n + 1) and i <= n) {
    a(2, n);
    uint j = i;

    /****************************
     *
     *     |_________ {-------- n+1 -------}
     *  ~  |j = 0   | [----- n ------] + [1]  // |[0,0]| = 1
     *  |  |j = 1   | [--- n-1 ---] + [1]     // |[0,1]| = 2
     *  n  |j = 2   | [-- n-2 --] + [1]       // |[0,2]| = 3
     *  |  | ...    | ...
     *  |  |j = n-2 | [-2-] + [1]             // |[0,n-2]| = n
     *  ~  |j = n-1 | [1] + [1]               // |[0,n-1]| = n
     *!   |j = n  | [] + [1] not valid, i != n
     *
     * Let's count including j=n, then we rest 1.
     *
     * formula: [(n+1) + 1][n+1]/2 - 1
     * formula: (n+2)(n+1)/2 - 1
     * formula: (n*n + n + 2n + 2) /2 -1
     * formula: (n*n + 3n + 2)/2 - 1
     **/

    while (a(3, (n * n + 3 * n + 2) / 2 - 1) and j <= n) {
      /****************************
       *
       *     |_________ {----- n ------}
       *  ~  |j = 0   | [----- n ------]   // |[0,0]| = 1
       *  |  |j = 1   | [--- n-1 ---]      // |[0,1]| = 2
       *  n  |j = 2   | [-- n-2 --]        // |[0,2]| = 3
       *  |  | ...    | ...
       *  |  |j = n-2 | [-2-]              // |[0,n-1]| = n
       *  ~  |j = n-1 | [1]                // |[0,n-1]| = n
       *!   |j = n  | []  not valid, i!=j != n
       *
       * formula: (n+1)(n)/2
       * formula: (n*n+n)/2
       **/

      a(4, (n * n + n) / 2);
      j++;
    }
    a(5, n);
    i++;
  }
  // n^2 + 5n + 2
}

int main()
{
  uint n = 10;
  std::vector<int> measured(1000, 0);
  std::vector<int> expected(1000, 0);
  int max_i = -1;
  auto a = [&](int i, int expected_complexity) {
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
