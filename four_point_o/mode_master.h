#ifndef MODE_MASTER_H
#define MODE_MASTER_H
#include "modes.h"

class ModeMaster {
   public:
     ModeMaster();
     ~ModeMaster();
     void setModeUnlessNull(Mode* mode);
     void loop();

     Mode* current_mode;
     Mode* mode_breathe;
};

#endif