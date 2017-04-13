#include <iostream>
#include "vector.hpp"
#include "smartpoint.hpp"
using namespace std;
using namespace sjtu;

int main(){
	vector<int> a;
	for(int i = 0; i != 10; ++i) {
		a.push_back(i);
	} 

	SmartPoint<vector<int> > p;
	p->push_back(2);
	for (vector<int>::iterator it = (*p).begin(); it != (*p).end();++it){
		cout << *it << endl;
	}
	return 0;
}