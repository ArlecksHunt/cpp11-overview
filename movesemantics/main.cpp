#include <iostream>
#include <vector>

using namespace std;

vector<int> getBigVec()
{
    vector<int> local(1000);
    //return move(local);
    return local;
}

void takeBigVec(vector<int> vec)
{
    //use vec
}

int main()
{
    auto myVec = getBigVec(); //deep copy? u serious?

    //c++11:
    /*
     vector(vector&& __x) noexcept
      : _Base(std::move(__x)) { }

      _Vector_base(_Vector_base&& __x)
      : _M_impl(std::move(__x._M_get_Tp_allocator()))
      { this->_M_impl._M_swap_data(__x._M_impl); }
    */

    //https://github.com/InfoAG/Jarvis.Framework/blob/List/Container/LinkedList.h#L37

    takeBigVec(move(myVec));

    //myVec in unspecified state
    myVec.clear();
    //all clear
    myVec.push_back(3);
    return 0;
}

