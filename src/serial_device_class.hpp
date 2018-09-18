#ifndef SERIALDEVICE_H_
#define SERIALDEVICE_H_

#define SERIALDEVICE_SERIAL_BUFFERSIZE_RECIEVE  1024

#include <string>
#include <termios.h>

class SerialDevice
{
protected:
    int         fd;  // file descripter of serial device
    unsigned char buffer_rx[ SERIALDEVICE_SERIAL_BUFFERSIZE_RECIEVE  ];
    int           buffer_rx_index;
    struct termios tio;

    /*
     * Serial Communication
     */
    int  serial_read( int len );
    int  serial_readline( char delimiter = '\n' );
    int  serial_send( unsigned char *cmd, int len );

public:
    SerialDevice( std::string path_device,
                  int baudrate );
    ~SerialDevice();
};

#endif
