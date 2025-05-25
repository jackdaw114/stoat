#ifndef SIDEBAR_H
#define  SIDEBAR_H

#include <qobject.h>
#include <qwidget.h>
#include "stoatuiexport.h"

class SideBarManager;

class STOAT_EXPORT SideBar :public QWidget{
        Q_OBJECT
    public:
        explicit SideBar();
    private:
        SideBarManager* m_manager;
};

class STOAT_EXPORT SideBarManager :public QObject{
        Q_OBJECT
    public:
        explicit SideBarManager();  
};

#endif
