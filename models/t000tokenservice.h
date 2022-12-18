#pragma once
#include <TGlobal>
#include "sqlobjects/t001usuariosobject.h"

class THttpRequest;

class T_MODEL_EXPORT T000TokenService {
public:
    T001UsuariosObject thisTokenExists(THttpRequest &httpRequest);
    QString create(int c001IdUsuario);
    void remove(int c001IdUsuario);
};

