#include <iostream>
#include <memory>

using namespace std;

template<typename T, typename ...Args>
std::unique_ptr<T> make_unique( Args&& ...args )
{
    return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
}

struct MyType
{
    MyType(int i) : d{i + 0.5}, f{i - 0.5f}, i{i} {}
    double d;
    float f;
    int i;
};

void takeOwnership(unique_ptr<MyType> i)
{
    //it's mine now, break it :D
    i.reset();
}

int main()
{
    //int **rawPtr = new int[1000];
    auto oneInteger = make_unique<int>(3);
    auto manyIntegers = unique_ptr<int[]>(new int[1000]);

    auto myPtr = make_unique<MyType>(2);
    cout << myPtr->f << endl;
    cout << *oneInteger;

    shared_ptr<int> p1 = make_shared<int>(5);
    shared_ptr<int> p2 = p1; //Both now own the memory.

    p1.reset(); //Memory still exists, due to p2.
    p2.reset(); //Deletes the memory, since no one else owns the memory.

    takeOwnership(move(myPtr)); //no copy ctor

    return 0;
}

