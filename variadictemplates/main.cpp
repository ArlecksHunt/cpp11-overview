#include <iostream>
#include <stdexcept>

using namespace std;

void printf(const char *s)
{
    while (*s) {
        if (*s == '%' && *(++s) != '%')
            throw std::runtime_error("invalid format string: missing arguments");
        std::cout << *s++;
    }
}

template<typename T, typename... Args>
void printf(const char *s, T value, Args... args)
{
    while (*s) {
        if (*s == '%' && *(++s) != '%') {
            std::cout << value;
            ++s;
            printf(s, args...); // call even when *s == 0 to detect extra arguments
            return;
        }
        std::cout << *s++;
    }
    throw std::logic_error("extra arguments provided to printf");
}

int main()
{
    printf("%a derp %b derp %c", 1, 2.0, "lol");
    return 0;
}

