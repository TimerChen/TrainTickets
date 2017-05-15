#include "E:\College-2\DataStructure\Train\time.hpp"
#include <iostream>
#include <cstdlib>
int main()
{
    printf("Now begin with the tests\n");
    
    Time test1("2017-03-28 20:02:22");
    printf("constructor \"Time::Time(const string &t)\" is being tested\n");
    
    printf("\"Time::to_int()\" is tested\n");
    int test_to_int = test1.to_int();
    printf("This is output of \"Time::to_int() - \"\n%d\n", test_to_int);

    printf("constructor \"Time::Time(const int &t)\" is tested\n");
    Time test2(test_to_int);

    printf("\"Time::to_int()\" is tested\n");
    int test_to_int2 = test2.to_int();
    printf("This is output of Time::to_int()\n %d\n", test_to_int2);

    printf("\"Time::to_string()\" is tested\n");
    string test_to_string = test2.to_string();
    cout << test_to_string << endl;

    system("pause");
    return 0;
}