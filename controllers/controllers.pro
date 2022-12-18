TARGET = controller
TEMPLATE = lib
CONFIG += shared x86_64
QT += network sql xml qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers ../models
DEPENDPATH  += ../helpers ../models
LIBS += -L../lib -lhelper -lmodel
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)

HEADERS += applicationcontroller.h
SOURCES += applicationcontroller.cpp
HEADERS += apit001usuarioscontroller.h
SOURCES += apit001usuarioscontroller.cpp
HEADERS += apit002cursoscontroller.h
SOURCES += apit002cursoscontroller.cpp
HEADERS += apit003docentescontroller.h
SOURCES += apit003docentescontroller.cpp
HEADERS += apit004usuariocursocontroller.h
SOURCES += apit004usuariocursocontroller.cpp
HEADERS += account/accountcontroller.h
SOURCES += account/accountcontroller.cpp
