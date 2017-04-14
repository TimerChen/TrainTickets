#include "smartpoint.hpp"
#include "vector.hpp"
#include <iostream>
using namespace std;
using namespace sjtu;

int main() {
    vector<int> a;
    for (int i = 0; i != 10; ++i) {
        a.push_back(i);
    }

    shared_ptr<vector<int>> p = &a;
    p->push_back(2);
    for (vector<int>::iterator it = (*p).begin(); it != (*p).end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}