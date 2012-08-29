#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <class T, class U>
auto add(const T &first, const U &second) -> decltype(first + second) { return first + second; }

int main()
{
    auto myInteger = 42;
    auto myDouble = 4.2;

    vector<vector<list<int> > > vec;
    //vector<vector<list<int>>>::const_iterator cit = vec.cbegin();
    auto cit_2 = vec.cbegin();

    const auto &myRef = myInteger;

    cout << add(1,2); //works if operator+(T, U) is defined
    decltype(add(1,2)) res = add(1,2);

    return 0;
}

