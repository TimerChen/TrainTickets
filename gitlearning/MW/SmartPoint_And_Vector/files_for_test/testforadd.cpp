#include "smartpoint.hpp"
#include <iostream>
using namespace std;

int
main()
{
    shared_ptr<int, true> p = new int[10];
    for (int i = 0; i < 10; ++i) {
        p[i] = i;
    }
    cout << *(p + 2) << endl;
    normal_ptr<int> a = p + 3;
    cout << *(a++) << endl;
    return 0;
}