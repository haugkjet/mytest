#include <iostream>

#include "../../inc/shared_EXPORTS.h"

#include "ndds_cpp.h"

void shared_EXP printlib()
{

    std::cout << "Print Lib4" << std::endl;
}

int shared_EXP getnumberfromlib()
{
   return 5;
}

void shared_EXP initNDDS()
{
    DDS_ReturnCode_t         rc;
    DDSDomainParticipant *   participant = NULL;
    DDSTopic *               topic = NULL;

    int i; int j; int u;
    i = 2;
    j = 12;
    u = i + j;

    //myvec vector = [1,2,3]
    std::cout << "Hellotest" << std::endl;
    std::cout << u << std::endl;

    std::cout << "Creating domain participant..." << std::endl;

    participant = DDSDomainParticipantFactory::get_instance()->
        create_participant(
            0,
            DDS_PARTICIPANT_QOS_DEFAULT,
            NULL,   /* Listener */
            DDS_STATUS_MASK_NONE);

    if (participant == NULL) {
        std::cerr << "! Unable to create DDS domain participant" << std::endl;
    }
    else
    {
        std::cout << "Participant OK." << std::endl;
    }
}
