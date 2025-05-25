#ifndef STAPPLICATION_H
#define STAPPLICATION_H

#include "stoatuiexport.h"
#include <qapplication.h>
#include <qchar.h>

class MainWindow;

class STOAT_EXPORT StApplication :public QApplication{
        Q_OBJECT
    public:
        explicit StApplication(int &argc,char** argv);
        ~StApplication();
        /*
         * entitty system here?
         */ 
        MainWindow* mainWindow();
    private:
        MainWindow* m_mainWindow;
};


#endif
