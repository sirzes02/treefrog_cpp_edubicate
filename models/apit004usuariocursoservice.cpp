#include "apit004usuariocursoservice.h"
#include "objects/t004usuariocurso.h"
#include <TreeFrogModel>


QJsonObject ApiT004UsuarioCursoService::index()
{
    auto t004UsuarioCursoList = T004UsuarioCurso::getAll();
    QJsonObject json = {{"data", tfConvertToJsonArray(t004UsuarioCursoList)}};
    return json;
}

QJsonObject ApiT004UsuarioCursoService::get(int c004Id)
{
    auto t004UsuarioCurso = T004UsuarioCurso::get(c004Id);
    QJsonObject json = {{"data", t004UsuarioCurso.toJsonObject()}};
    return json;
}

QJsonObject ApiT004UsuarioCursoService::create(THttpRequest &request)
{
    QJsonObject json;
    auto t004UsuarioCurso = request.jsonData().toVariant().toMap();
    auto model = T004UsuarioCurso::create(t004UsuarioCurso);

    if (model.isNull()) {
        json.insert("error", QJsonObject({{"message", "Internal Server Error"}}));
    } else {
        json.insert("data", model.toJsonObject());
    }
    return json;
}

QJsonObject ApiT004UsuarioCursoService::save(THttpRequest &request, int c004Id)
{
    QJsonObject json;
    auto model = T004UsuarioCurso::get(c004Id);

    if (model.isNull()) {
        json.insert("error", QJsonObject({{"message", "Not found"}}));
        return json;
    }

    auto t004UsuarioCurso = request.jsonData();
    model.setProperties(t004UsuarioCurso);

    if (!model.save()) {
        json.insert("error", QJsonObject({{"message", "Internal Server Error"}}));
    } else {
        json.insert("data", model.toJsonObject());
    }
    return json;
}

QJsonObject ApiT004UsuarioCursoService::remove(int c004Id)
{
    QJsonObject json;
    auto t004UsuarioCurso = T004UsuarioCurso::get(c004Id);

    if (t004UsuarioCurso.remove()) {
        json.insert("status", "OK");
    }
    return json;
}

