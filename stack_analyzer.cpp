// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct stack_analyzer
{
  vector<unsigned> v;
  stack_analyzer(){
    // s.push
    // v.capacity();
  }
  ~stack_analyzer()
  {
    //
  }
    unsigned get_cost(){
    for(auto e: v){
    cout  << e << endl;
    }
    //
  }
};

using sa = stack_analyzer;

void g(std::vector<int> A)
{

    sa a{};
    for(int j = 1; sa() and j  < A.size() ;j++)
    {
        sa();
        int key = A[j];
        sa();
        int i = j - 1;
        while(sa() and  i > 0 and A[i] > key)
        {
            sa();
            A[i+1] = A[i];
            sa();
            i = i-1;
        }
        sa();
        A[i+1] = key;
    }


}

template<class T>
void f(std::vector<int>A, T a)
{
    for(int j = 1; a(0) and j  < A.size() ;j++)
    {
        a(1);
        int key = A[j];
        a(2);
        int i = j - 1;
        while(a(3) and  i > 0 and A[i] > key)
        {
            a(4);
            A[i+1] = A[i];
            a(5);
            i = i-1;
        }
        a(6);
        A[i+1] = key;
    }

}

int main() {

    std::vector<int> counters(7,0);
    auto a = [&](int i){
        counters[i]++;
        return true;
    };

    //std::vector<int> v{10,1,2,3,16,8,14,26};
    std::vector<int> v{0,1,2,3,4,5,6,7,8,9};
    f(v,a);
    for(auto e : counters)
    {
        cout << e << endl;
    }

}
