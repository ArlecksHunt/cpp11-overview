#include <iostream>
#include <vector>

using namespace std;

class MyClass
{
    vector<int> vec;
public:
    MyClass(initializer_list<int> init) : vec(init) {
        cout << init.size();
    }
};

MyClass func()
{
    return {1,4,5,6,76,7};
}

int main()
{
    /*
    vector<int> intvec;
    intvec.push_back(1);
    intvec.push_back(3);
    intvec.push_back(7);
    ...
    */

    vector<int> intvec{1,3,7,42,12345};

    /*
     vector(initializer_list<value_type> __l,
         const allocator_type& __a = allocator_type())
      : _Base(__a)
      {
    _M_range_initialize(__l.begin(), __l.end(),
                random_access_iterator_tag());
      }
      */

    MyClass instance{1,42,3,5};
    func();

    return 0;
}

