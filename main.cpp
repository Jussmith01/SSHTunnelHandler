#include "tools.h"

int main (int argc, char *argv[])
{
    if (argc < 6)
    {
        std::cerr << "Missing arguments!\n";
        std::cerr << "Syntax for port forwarding is:\n";
        std::cerr << "sshtunnelhandler [hostsshport] [localport] [hostport] [user] [host]\n";
        exit(EXIT_FAILURE);
    }

    std::string sshport = argv[1];
    std::string localport = argv[2];
    std::string hostport = argv[3];
    std::string user = argv[4];
    std::string server = argv[5];

    std::stringstream ss;

    ss << "ssh -p" << sshport <<  " -x -N -T -R" << localport << ":localhost:" << hostport << " " << user <<  "@" << server;

    while (true)
    {
        std::cout << "Executing Command: " << ss.str() << std::endl;
        std::cout << "Attempting Connection...\n";
        tools::exec(ss.str().c_str());
        std::cout << "Connection failed, retrying in 15 seconds...\n";
        sleep(15);

    }

	return 0;
}
