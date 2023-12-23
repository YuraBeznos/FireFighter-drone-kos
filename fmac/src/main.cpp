#include "server.h"

#include "fmac_actions.h"
#include <connections.h>
#include <iostream>

#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void)
{
    std::cerr << connections::FMAC << ": started" << std::endl;

    Server server;
    auto retCode = server.Run();

    std::cerr << connections::FMAC << ": stoped. Exit code = " << retCode
           << std::endl;

    return retCode;
}