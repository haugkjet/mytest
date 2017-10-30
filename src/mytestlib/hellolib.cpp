#include <iostream>

#include "../../inc/shared_EXPORTS.h"

#include "ndds_cpp.h"

void shared_EXP printlib()
{
    DDS_ReturnCode_t         rc;
    DDSDomainParticipant *   participant = NULL;
    DDSTopic *               topic = NULL;
    std::cout << "Print Lib4" << std::endl;
}

int shared_EXP getnumberfromlib()
{
   return 5;
}
