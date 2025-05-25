#ifndef GLVIEWPORT_H
#define GLVIEWPORT_H

#include <qobject.h>
#include <qobjectdefs.h>
#include <QWindow>
#include <qopenglfunctions.h>
#include <qsurface.h>
#include <qsurfaceformat.h>
#include "stoatuiexport.h"
#include "viewport/openglwindow.hpp"
#include <QOpenGLFunctions>
#include <qwindow.h>
#include <QOpenGLPaintDevice>

class MainWindow;



class STOAT_EXPORT GLViewport: OpenGLWindow{
    Q_OBJECT
    public:
        explicit GLViewport(QWindow *parent=nullptr);
        ~GLViewport() = default;
        
        void initialize() override;
        void render() override;    
};

#endif

