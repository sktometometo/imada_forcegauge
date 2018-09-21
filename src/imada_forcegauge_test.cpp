#include "imada_forcegauge.hpp"

#include <iostream>
#include <string>
#include <csignal>
#include <cstdlib>

ImadaForcegauge *a;

void sigint( int hoge )
{
    delete a;
    std::exit(0);
}

int main( int argc, char **argv )
{
    if ( argc < 2 ) {
        std::cout << "usage:program <serial port>" << std::endl;
        return 0;
    }

    std::string serialport( argv[1] );
    try {
        a = new ImadaForcegauge( serialport );
    } catch( int error ) {
        std::cout << "object generation error" << std::endl;
        std::exit(1);
    }

    signal( SIGINT, sigint );

    while (true) {
        std::cout << a->read() << std::endl;
    }
}
