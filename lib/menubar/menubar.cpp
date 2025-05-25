#include "menubar/menubar.hpp"
#include <QDebug>
#include <QFileDialog>
#include <QIcon>
#include <QKeySequence>
#include <QMenuBar>
#include <iostream>
#include <qaction.h>
#include <qchar.h>
#include <qobjectdefs.h>
#include <qpushbutton.h>
#include <qt6/QtCore/qdir.h>
#include <qt6/QtCore/qlogging.h>
#include <qwidget.h>
MenuBar::MenuBar(QWidget *parent) : QMenuBar(parent) {
    m_fileMenu = addMenu(tr("&File"));
    createActions();
    createMenus();
}

void MenuBar::showMenuBar() { std::cout << "hello from signal" << std::endl; }
void MenuBar::newProject() {
    std::cout << "hello from file signal" << std::endl;
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setViewMode(QFileDialog::Detail);

    QString dirPath;
    if (dialog.exec()) {
        dirPath = dialog.selectedFiles().first();
        m_window->openProject(&dirPath);
        if (!(QFile::exists(dirPath + ".stoat"))) {
            qDebug() << "project already exists";
            return;
        }
    }
    qDebug() << "dir path" << dirPath;
}

void MenuBar::createActions() {
    newAct = new QAction(tr("New Project"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create Project"));
    connect(newAct, &QAction::triggered, this, &MenuBar::newProject);
    openAct = new QAction(tr("Open Project"), this);
    saveAct = new QAction(tr("Save"), this);
}

void MenuBar::createMenus() { m_fileMenu->addAction(newAct); }

MenuBar::~MenuBar() {}
