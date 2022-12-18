#include "apit001usuariosservice.h"
#include "objects/t001usuarios.h"
#include <TreeFrogModel>


QJsonObject ApiT001UsuariosService::index()
{
    auto t001UsuariosList = T001Usuarios::getAll();
    QJsonObject json = {{"data", tfConvertToJsonArray(t001UsuariosList)}};
    return json;
}

QJsonObject ApiT001UsuariosService::get(int c001Id)
{
    auto t001Usuarios = T001Usuarios::get(c001Id);
    QJsonObject json = {{"data", t001Usuarios.toJsonObject()}};
    return json;
}

QJsonObject ApiT001UsuariosService::create(THttpRequest &request)
{
    QJsonObject json;
    auto t001Usuarios = request.jsonData().toVariant().toMap();
    auto model = T001Usuarios::create(t001Usuarios);

    if (model.isNull()) {
        json.insert("error", QJsonObject({{"message", "Internal Server Error"}}));
    } else {
        json.insert("data", model.toJsonObject());
    }
    return json;
}

QJsonObject ApiT001UsuariosService::save(THttpRequest &request, int c001Id)
{
    QJsonObject json;
    auto model = T001Usuarios::get(c001Id);

    if (model.isNull()) {
        json.insert("error", QJsonObject({{"message", "Not found"}}));
        return json;
    }

    auto t001Usuarios = request.jsonData();
    model.setProperties(t001Usuarios);

    if (!model.save()) {
        json.insert("error", QJsonObject({{"message", "Internal Server Error"}}));
    } else {
        json.insert("data", model.toJsonObject());
    }
    return json;
}

QJsonObject ApiT001UsuariosService::remove(int c001Id)
{
    QJsonObject json;
    auto t001Usuarios = T001Usuarios::get(c001Id);

    if (t001Usuarios.remove()) {
        json.insert("status", "OK");
    }
    return json;
}

QJsonObject ApiT001UsuariosService::authenticate(const QString &email, const QString &password) {
    auto user = T001Usuarios::authenticate(email, password);

    return {{"user", user.toJsonObject()}};
}