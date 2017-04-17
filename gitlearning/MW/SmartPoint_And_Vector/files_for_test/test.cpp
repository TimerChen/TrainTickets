#include "smartpoint.hpp"
#include "vector.hpp"
#include <iostream>
using namespace std;
using namespace sjtu;

struct node
{
    int x;
    int y;
    node(int _x = 0, int _y = 0)
      : x(_x)
      , y(_y)
    {
    }
};

int
main()
{
    vector<int> a;
    for (int i = 0; i != 10; ++i) {
        a.push_back(i);
    }

    normal_ptr<vector<int>> p = &a;
    p->push_back(2);
    for (vector<int>::iterator it = (*p).begin(); it != (*p).end(); ++it) {
        cout << *it << endl;
    }

    const shared_ptr<node> sp = new node(100, 2);
    cout << sp->x << endl;
    shared_ptr<node> sp2;
    sp2 = sp;
    shared_ptr<int, true> ip = new int[10];
    for (int i = 0; i != 10; ++i) {
        ip[i] = 10 * i;
    }
    cout << *(ip + 3) << endl;

    const_normal_ptr<int> ap = new int(200);
    cout << *ap << endl;

    return 0;
}