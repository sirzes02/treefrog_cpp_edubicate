#pragma once
#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ApiT001UsuariosController : public ApplicationController {
    Q_OBJECT
public slots:
    void index();
    void get(const QString &c001Id);
    void create();
    void save(const QString &c001Id);
    void remove(const QString &c001Id);
};

