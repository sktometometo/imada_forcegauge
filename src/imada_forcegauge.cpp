#include "imada_forcegauge.hpp"

#include <iostream>
#include <cstdlib>
#include <string>

ImadaForcegauge::ImadaForcegauge( std::string path_device )
    : SerialDevice( path_device, 19200 )
{

}

double ImadaForcegauge::read()
{
    unsigned char buf[] = { IMADA_FORCEGAUGE_COMMAND_READ, '\r' };
    this->serial_send( buf, sizeof(buf) );
    std::cout << "fuga" << std::endl;
    
    //this->serial_readline( '\r' );
    this->serial_read( 10 );
    //
    // buffer は, "+XX.XXKT0\r" で届く
    // 上でKのところをnull文字にして, 文字列として扱えるようにする
    this->buffer_rx[10] = '\0';
    std::cout << "recieved:" << this->buffer_rx << std::endl;

    this->buffer_rx[6] = '\0';
    return atof( (char*)this->buffer_rx );
}
