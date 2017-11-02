#include "../../inc/rdsgenlib.h"
#include "../../inc/rdsnddslib.h"
#include <iostream>

int main()
{
    std::cout << "rdsConsole version 1.0" << std::endl;
    std::cout << "rdsConsole tesing rdsgenlib" << std::endl;
    printlib();
    std::cout << "rdsConsole tesing rdsnddslib" << std::endl;
    initNDDS();
    std::cin.get();
    return 0;
}
