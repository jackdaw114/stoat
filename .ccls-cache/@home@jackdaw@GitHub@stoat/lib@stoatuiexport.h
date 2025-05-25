#ifndef STOATUIEXPORT_H
#define  STOATUIEXPORT_H
#include <QtCompilerDetection>
#ifdef STOAT_SHAREDLIBRARY
#define STOAT_EXPORT Q_DECL_EXPORT
#else
#define STOAT_EXPORT Q_DECL_IMPORT
#endif

#endif
