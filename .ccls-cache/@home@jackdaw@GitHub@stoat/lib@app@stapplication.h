#ifndef STAPPLICATION_H
#define STAPPLICATION_H

#include "stoatuiexport.h"
#include <qapplication.h>

class STOAT_EXPORT StApplication : QApplication{
    public:
        explicit StApplication(int &argc,char** argv);
        ~StApplication();
};

#endif
