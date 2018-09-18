#include "serial_device_class.hpp"

#include <cstdio>
#include <string>
#include <cstdint>
#include <iostream>

// system
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

SerialDevice::SerialDevice( std::string   path_device,
                            int           baudrate )
try {
    
    // file open
    this->fd = open( path_device.c_str(), O_RDWR );
    if ( this->fd < 0 ) {
        perror("device open error\n");
        throw 1;
    }
    std::cout << "fd=" << this->fd << std::endl;

    // initialization of serial communication
    this->tio.c_cflag = CREAD | CLOCAL | CS8;
    this->tio.c_lflag = ICANON;
    cfsetspeed( &(this->tio), baudrate ); // speed
    tcsetattr( this->fd, TCSANOW, &(this->tio) );
    ioctl( this->fd, TCSETS, &(this->tio) );

} catch( int error ) {
    throw 1;
}

SerialDevice::~SerialDevice()
{
    close( this->fd );
}

int SerialDevice::serial_read( int len )
{
    return read( this->fd, this->buffer_rx, len );
}

int SerialDevice::serial_readline( char delimiter )
{
//    unsigned char buffer_temp;
    std::uint8_t buffer_temp;
    this->buffer_rx_index = 0;

    while ( true ) {
        std::cout << "hogefuga" << std::endl;
        if ( read( this->fd, &buffer_temp, 1 ) ) {
            this->buffer_rx[ this->buffer_rx_index++ ] = buffer_temp;
            std::cout << "hoge" << std::endl;
            
            // 読み取りを終了する条件
            // デフォルトでは, LFのみに対応
            if ( buffer_temp == delimiter ) {
                return this->buffer_rx_index;
            }
        }
    }
}

int SerialDevice::serial_send( unsigned char *cmd, int len )
{
    return write( this->fd, cmd, len );
}
