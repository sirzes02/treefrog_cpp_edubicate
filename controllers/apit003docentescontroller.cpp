#include "apit003docentescontroller.h"
#include "apit003docentesservice.h"

static ApiT003DocentesService service;


void ApiT003DocentesController::index()
{
    auto json = service.index();
    renderJson(json);
}

void ApiT003DocentesController::get(const QString &c003Id)
{
    auto json = service.get(c003Id.toInt());
    renderJson(json);
}

void ApiT003DocentesController::create()
{
    QJsonObject json;

    switch (request().method()) {
    case Tf::Post:
        json = service.create(request());
        break;
    default:
        setStatusCode(Tf::BadRequest);
        break;
    }
    renderJson(json);
}

void ApiT003DocentesController::save(const QString &c003Id)
{
    QJsonObject json;

    switch (request().method()) {
    case Tf::Post:
        json = service.save(request(), c003Id.toInt());
        break;
    default:
        setStatusCode(Tf::BadRequest);
        break;
    }
    renderJson(json);
}

void ApiT003DocentesController::remove(const QString &c003Id)
{
    QJsonObject json;

    switch (request().method()) {
    case Tf::Post:
        json = service.remove(c003Id.toInt());
        break;
    default:
        setStatusCode(Tf::BadRequest);
        return;
    }
    renderJson(json);
}

// Don't remove below this line
T_DEFINE_CONTROLLER(ApiT003DocentesController)
