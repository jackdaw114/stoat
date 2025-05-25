#ifndef MAINWIDOW_H
#define  MAINWIDOW_H

#include <QList>
#include <qmainwindow.h>
#include <qnamespace.h>
#include <qobjectdefs.h>
#include <qwindowdefs.h>
#include "stoatuiexport.h"

class MenuBar;

class STOAT_EXPORT MainWindow:public QMainWindow{
    Q_OBJECT
    public:
        MainWindow(QWidget *parent=nullptr,Qt::WindowFlags flags=Qt::WindowFlags());
        ~MainWindow() = default;                  
        MenuBar* menuBar(){return m_menuBar;}
        void openProject(const QString& dir); 
    private:
        QString m_currentProject;
        MenuBar* m_menuBar;
        QWindow* m_glWindow;
};

#endif
