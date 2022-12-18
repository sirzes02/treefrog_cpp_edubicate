#include "apit003docentesservice.h"
#include "objects/t003docentes.h"
#include <TreeFrogModel>


QJsonObject ApiT003DocentesService::index()
{
    auto t003DocentesList = T003Docentes::getAll();
    QJsonObject json = {{"data", tfConvertToJsonArray(t003DocentesList)}};
    return json;
}

QJsonObject ApiT003DocentesService::get(int c003Id)
{
    auto t003Docentes = T003Docentes::get(c003Id);
    QJsonObject json = {{"data", t003Docentes.toJsonObject()}};
    return json;
}

QJsonObject ApiT003DocentesService::create(THttpRequest &request)
{
    QJsonObject json;
    auto t003Docentes = request.jsonData().toVariant().toMap();
    auto model = T003Docentes::create(t003Docentes);

    if (model.isNull()) {
        json.insert("error", QJsonObject({{"message", "Internal Server Error"}}));
    } else {
        json.insert("data", model.toJsonObject());
    }
    return json;
}

QJsonObject ApiT003DocentesService::save(THttpRequest &request, int c003Id)
{
    QJsonObject json;
    auto model = T003Docentes::get(c003Id);

    if (model.isNull()) {
        json.insert("error", QJsonObject({{"message", "Not found"}}));
        return json;
    }

    auto t003Docentes = request.jsonData();
    model.setProperties(t003Docentes);

    if (!model.save()) {
        json.insert("error", QJsonObject({{"message", "Internal Server Error"}}));
    } else {
        json.insert("data", model.toJsonObject());
    }
    return json;
}

QJsonObject ApiT003DocentesService::remove(int c003Id)
{
    QJsonObject json;
    auto t003Docentes = T003Docentes::get(c003Id);

    if (t003Docentes.remove()) {
        json.insert("status", "OK");
    }
    return json;
}

