#ifndef AMADA_FORCEGAUGE_H_
#define AMADA_FORCEGAUGE_H_

#define AMADA_FORCEGAUGE_SERIAL_BAUDRATE 19200
#define AMADA_FORCEGAUGE_COMMAND_READ    'D'

#include "serial_device_class.hpp"

class AmadaForcegauge : public SerialDevice
{
protected:

public:
    AmadaForcegauge( std::string path_device );
    double read();   
};

#endif
