#ifndef __ARPNOID_HH
#define __ARPNOID_HH 1

#include <iostream>
#include <istream>
#include <string>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if_arp.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <getopt.h>
#include <errno.h>
#include "util.h"

#ifndef ERROR
    #define ERROR(buff){\
        errbuf = string(buff);\
        return false;\
    }
#endif

#ifndef ERROR2
    #define ERROR2(buff){\
        errbuf = string(buff);\
        return nullptr;\
    }
#endif

using namespace std;

class Arpnoid {
    public:
        Arpnoid();
        ~Arpnoid();
        static std::shared_ptr<Arpnoid> instance( void );
        bool init( const char *iface );
        bool is_iface( const char *iface );
        bool cache( vector<string> endpoints );
        bool insert_entry( struct arpreq *req, const char *ip, const char *hw );
        struct ifreq * if_list( void );
        
    public:
        string errbuf;

    private:
        int _socket;
        const char *_iface;
        static std::shared_ptr<Arpnoid> _instance;
};

#endif