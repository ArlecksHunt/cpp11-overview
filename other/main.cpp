#include <iostream>
#include <vector>

using namespace std;

struct SomeType {
    SomeType() = default; //The default constructor is explicitly stated.
    SomeType(int value);
};

struct NonCopyable {
    NonCopyable & operator=(const NonCopyable&) = delete;
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable() = default;
};

struct NoInt {
    void f(double i);
    void f(int) = delete;
};

struct OnlyDouble {
    void f(double d);
    template<class T> void f(T) = delete;
};

constexpr int get_five() { return 6; }

int main()
{
    int i = NULL;
    char c = NULL;

    //int i = nullptr; ->error

    int *myPtr = nullptr;
    bool myBool = nullptr;

    int ar[get_five() + 2];

    vector<vector<int>> derp;

    //alias templates
    //https://github.com/InfoAG/Jarvis.Framework/blob/List/Container/SmartList.h#L15

    /*
     * threading
     * pseudorandom numbers
     * noexcept
     * override / final
     * tuple
     * regex
     * chrono
     */

    return 0;
}

