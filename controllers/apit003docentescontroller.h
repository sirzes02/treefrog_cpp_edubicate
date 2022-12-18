#pragma once
#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ApiT003DocentesController : public ApplicationController {
    Q_OBJECT
public slots:
    void index();
    void get(const QString &c003Id);
    void create();
    void save(const QString &c003Id);
    void remove(const QString &c003Id);
};

