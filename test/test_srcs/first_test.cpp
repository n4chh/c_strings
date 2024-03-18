#include "CppUTest/TestHarness.h"

extern "C" {
    #include "libstrings.h"
}

TEST_GROUP(lexer_test)
{
};


TEST(lexer_test, init) {
    CHECK_EQUAL(1, 1);
}

TEST(lexer_test, checkSimple)
{
    t_string test, cpy;
    ctor(&test, (char*)"hola muy buenas hola hola");
    printnl(test);
    cpy = str_rmpos(test, 5, 7);
    printnl(cpy);
    CHECK(NULL != cpy);
    dtor(&test);
    dtor(&cpy);
    
}

