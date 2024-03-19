#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#define b(i, x) B(i, x, #x)

template<typename T = int> struct Benchmark
{
  std::vector<T> measured;
  std::vector<T> expected;
  std::vector<std::string> equations;
  unsigned n{ 0 };
  int max_i{ -1 };
  explicit Benchmark(unsigned t_n) : n{ t_n }
  {
    measured.resize(1000, 0);
    expected.resize(1000, 0);
    equations.resize(1000);
  }
  void cut_vars()
  {
    max_i++;
    measured.resize(max_i);
    expected.resize(max_i);
    equations.resize(max_i);
    max_i = -1;
  }

  void expand_vects()
  {
    measured.resize(1000, 0);
    expected.resize(1000, 0);
    equations.resize(1000, std::string{ "" });
  }

  void print_table()
  {
    using std::cout;
    using std::endl;
    std::string t_eq{ "" };

    cut_vars();
    cout << "n: " << n << endl;
    cout << std::setw(7) << "i|";
    cout << std::setw(11) << "measured|";
    cout << std::setw(11) << "expected|";
    cout << "equations" << endl;

    for (uint i = 0; i < measured.size(); i++) {
      if (measured[i] == -1) { break; }
      cout << std::setw(6) << i << "|";
      cout << std::setw(10) << measured[i] << "|";
      cout << std::setw(10) << expected[i] << "|";
      cout << equations[i] << endl;

      t_eq += equations[i] + "+";
    }

    auto t_measured = std::accumulate(measured.begin(), measured.end(), 0);
    auto t_expected = std::accumulate(expected.begin(), expected.end(), 0);
    t_eq.pop_back();

    cout << std::setw(7) << "total|";
    cout << std::setw(10) << t_measured << "|";
    cout << std::setw(10) << t_expected << "|";
    cout << t_eq;
    cout << endl;
    expand_vects();
  }

  bool operator()(int i, unsigned expected_complexity, std::string eq)
  {
    if (i > max_i) { max_i = i; }
    measured[i]++;
    expected[i] = expected_complexity;
    equations[i] = eq;
    return true;
  }
};
