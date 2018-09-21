#ifndef IMADA_FORCEGAUGE_H_
#define IMADA_FORCEGAUGE_H_

#define IMADA_FORCEGAUGE_SERIAL_BAUDRATE 19200
#define IMADA_FORCEGAUGE_COMMAND_READ    'D'

#include "serial_device_class.hpp"

class ImadaForcegauge : public SerialDevice
{
protected:

public:
    ImadaForcegauge( std::string path_device );
    double read();   
};

#endif
