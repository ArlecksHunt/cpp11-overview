#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> myVec{1,234,4,56,77,8};

    //old
    for (vector<int>::const_iterator it = myVec.cbegin(); it != myVec.cend(); ++it)
        cout << *it;
    cout << endl;

    //sometimes useful
    for (auto it = begin(myVec); it != end(myVec); ++it)
        cout << *it;
    cout << endl;

    //cool
    for (const auto &item : myVec) cout << item;

    cout << endl << endl;

    //just as cool
    for (const auto x : { 1,2,3,5,8,13,21,34 }) cout << x << endl;

    return 0;
}

