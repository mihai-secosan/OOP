#include "../Header Files/MyExeptions.h"

void test_exeptions()
{
    std::string m1, m2;
    try
    {
        throw ItemAlreadyExists("alo");
    }
    catch (const std::exception& e)
    {
        m1 = e.what();
    }
    try
    {
        throw DontWorryItIsJustAnExeption("alo");
    }
    catch (const std::exception& e)
    {
        m1 = e.what();
    }
    try
    {
        throw SpaceLimitReached("sunt eu");
    }
    catch (const std::exception& e)
    {
        m2 = e.what();
    }
}
