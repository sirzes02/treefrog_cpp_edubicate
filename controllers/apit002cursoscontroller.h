#pragma once
#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ApiT002CursosController : public ApplicationController {
    Q_OBJECT
public slots:
    void index();
    void get(const QString &c002Id);
    void create();
    void save(const QString &c002Id);
    void remove(const QString &c002Id);
};

