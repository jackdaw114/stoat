#ifndef MENUBAR_H
#define MENUBAR_H 

#include <qaction.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qwidget.h>
#include "stoatuiexport.h"
#include <QMenuBar>
#include <mainwindow.hpp>

class STOAT_EXPORT MenuBar :public QMenuBar{
        Q_OBJECT
    public:
        explicit MenuBar(QWidget* parent=nullptr);
        ~MenuBar();

    private Q_SLOTS:
        void showMenuBar();
        void newProject();
    private:
        QAction *newAct;
        QAction *openAct;
        QAction *saveAct;

        QMenu *m_fileMenu;
        MainWindow* m_window;
        
        void createActions();
        void createMenus();
};

#endif
