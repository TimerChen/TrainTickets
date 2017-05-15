//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
//#include <stdlib.h>

#include "vector.hpp"

#include "class-bint.hpp"
#include "class-integer.hpp"
#include "class-matrix.hpp"

#include <fstream>
#include <iostream>
#include <string>

#define test_bint

void
TestInteger()
{
    std::cout << "Test for classes without default constructor..." << std::endl;
    ttd::vector<Integer> vInt;
    for (int i = 1; i <= 100; ++i) {
        vInt.push_back(Integer(i));
    }
    std::cout << "Test OK..." << std::endl;
}

void
TestMatrix()
{
    std::cout << "Test for my Matrix..." << std::endl;
    ttd::vector<Diamond::Matrix<double>> vM;
    for (int i = 1; i <= 10; ++i) {
        vM.push_back(Diamond::Matrix<double>(i, i, i));
    }
    for (size_t i = 0; i < vM.size(); ++i) {
        std::cout << vM[i] << std::endl;
    }
}

#ifdef test_bint
void
TestBint()
{
    std::cout << "Test for big integer" << std::endl;
    ttd::vector<Util::Bint> vBint;
    for (long long i = 1LL << 50; i < (1LL << 50) + 10; ++i) {
        vBint.push_back(Util::Bint(i) * i);
    }
    for (ttd::vector<Util::Bint>::iterator it = vBint.begin();
         it != vBint.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
#endif

int
main()
{
    //_CrtDumpMemoryLeaks();
    // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
    TestInteger();
    TestMatrix();
#ifdef test_bint
    TestBint();
#endif
    return 0;
}