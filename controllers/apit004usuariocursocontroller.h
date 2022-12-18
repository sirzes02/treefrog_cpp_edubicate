#pragma once
#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ApiT004UsuarioCursoController : public ApplicationController {
    Q_OBJECT
public slots:
    void index();
    void get(const QString &c004Id);
    void create();
    void save(const QString &c004Id);
    void remove(const QString &c004Id);
};

