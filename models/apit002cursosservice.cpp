#include "apit002cursosservice.h"
#include "objects/t002cursos.h"
#include <TreeFrogModel>


QJsonObject ApiT002CursosService::index()
{
    auto t002CursosList = T002Cursos::getAll();
    QJsonObject json = {{"data", tfConvertToJsonArray(t002CursosList)}};
    return json;
}

QJsonObject ApiT002CursosService::get(int c002Id)
{
    auto t002Cursos = T002Cursos::get(c002Id);
    QJsonObject json = {{"data", t002Cursos.toJsonObject()}};
    return json;
}

QJsonObject ApiT002CursosService::create(THttpRequest &request)
{
    QJsonObject json;
    auto t002Cursos = request.jsonData().toVariant().toMap();
    auto model = T002Cursos::create(t002Cursos);

    if (model.isNull()) {
        json.insert("error", QJsonObject({{"message", "Internal Server Error"}}));
    } else {
        json.insert("data", model.toJsonObject());
    }
    return json;
}

QJsonObject ApiT002CursosService::save(THttpRequest &request, int c002Id)
{
    QJsonObject json;
    auto model = T002Cursos::get(c002Id);

    if (model.isNull()) {
        json.insert("error", QJsonObject({{"message", "Not found"}}));
        return json;
    }

    auto t002Cursos = request.jsonData();
    model.setProperties(t002Cursos);

    if (!model.save()) {
        json.insert("error", QJsonObject({{"message", "Internal Server Error"}}));
    } else {
        json.insert("data", model.toJsonObject());
    }
    return json;
}

QJsonObject ApiT002CursosService::remove(int c002Id)
{
    QJsonObject json;
    auto t002Cursos = T002Cursos::get(c002Id);

    if (t002Cursos.remove()) {
        json.insert("status", "OK");
    }
    return json;
}

