#include "map.hpp"
#include <ctime>
#include "map_my.hpp"
#include <bits/stdc++.h>
sjtu::map<int,int> b;
ttd::map<int,int> a;
int temp[1111111];
int main()
{
	
	int t1 = 0, t2 = 0, t = clock();
	for (int i = 1; i < 1000000; ++i) {
		temp[i] = i;
	}
	std::random_shuffle(temp + 1, temp + 1000000);
	for (int i = 1; i< 1000000; i++)
	{
		t = clock();
		a[temp[i]] = rand();
		t1 += clock()-t, t = clock();
		b[temp[i]] = rand();
		t2 += clock()-t;
	}
	std::cout << t1 << ' ' << t2<<std::endl;
	
	t1 = t2 = 0;
	for (int i = 1; i< 5000000; i++)
	{
		t = clock();
		a.find(i);
		t1 += clock()-t, t = clock();
		b.find(i);
		t2 += clock()-t;
	}
	std::cout << t1 << ' ' << t2<<std::endl;
}
