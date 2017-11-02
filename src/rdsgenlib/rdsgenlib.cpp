#include <iostream>

#include "../../inc/rdsgenlib_EXPORTS.h"

void shared_EXP printlib()
{

    std::cout << "rdsgenlib printlib function" << std::endl;
}

int shared_EXP getnumberfromlib()
{
   std::cout << "rdsgenlib return5 function" << std::endl;
   return 5;
}

