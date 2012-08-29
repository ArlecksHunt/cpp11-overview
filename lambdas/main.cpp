#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int someValue = 3;

    auto myFunc = [&someValue](double arg) {
            return someValue++ * arg;
        };

    cout << myFunc(2.5) << endl;
    cout << someValue;

    vector<string> stringVec{"herp", "derp", "herpiderp", "roflcopter"};
    char searchMe;
    cin >> searchMe;
    cout << *find_if(begin(stringVec), end(stringVec), [=](const string &candidate) {
            return candidate.front() == searchMe;
        });

    cout << endl << endl;

    vector<int> sums;
    transform(begin(stringVec), end(stringVec), back_inserter(sums), [](const string &item) {
            int res = 0;
            for (const auto &c : item) res += c;
            return res;
        });

    for (const auto &sum : sums) cout << sum << endl;
    //https://github.com/InfoAG/Jarvis.gui/blob/GUI/QMLModulePackage.cpp
    //https://github.com/InfoAG/Jarvis.Backend/blob/server/OperatorInterface.h
    //https://github.com/InfoAG/Jarvis.Backend/blob/server/modules/basicarith/basicarith.cpp

    return 0;
}

