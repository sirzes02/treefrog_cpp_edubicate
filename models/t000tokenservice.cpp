#include "t000tokenservice.h"
#include "sqlobjects/t000tokenobject.h"
#include "sqlobjects/t001usuariosobject.h"
#include <TreeFrogModel>
#include "../helpers/commons.h"

QString T000TokenService::create(int c001IdUsuario) {
    TCriteria ctr(T000TokenObject::C001IdUsuario, c001IdUsuario);
    TSqlORMapper<T000TokenObject> mapper;

    auto tokenFind = mapper.findFirst(ctr);

    if (!tokenFind.isNull()) {
        tokenFind.remove();
    }

    QString tokenUuid = Commons::generate_uuid();
    T000TokenObject token;

    token.c001_id_usuario = c001IdUsuario;
    token.c000_token = tokenUuid + "-" + QString::number(c001IdUsuario);
    token.c000_fecha_creacion = QDateTime::currentDateTime();
    token.create();

    return token.c000_token;
}

void T000TokenService::remove(int c001IdUsuario) {
    TCriteria ctr(T000TokenObject::C001IdUsuario, c001IdUsuario);
    TSqlORMapper<T000TokenObject> mapper;

    auto tokenFind = mapper.findFirst(ctr);

    if (!tokenFind.isNull()) {
        tokenFind.remove();
    }
}

T001UsuariosObject T000TokenService::thisTokenExists(THttpRequest &httpRequest) {
    TCriteria ctr(T000TokenObject::C000Token, QString::fromStdString(httpRequest.cookie("auth").toStdString()));
    TSqlORMapper<T000TokenObject> mapperToken;

    int tokenFind = mapperToken.findFirst(ctr).c001_id_usuario;

    TSqlORMapper<T001UsuariosObject> mapperUser;
    T001UsuariosObject user = mapperUser.findByPrimaryKey(tokenFind);

    return user;
}

