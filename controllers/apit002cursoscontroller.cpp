#include "apit002cursoscontroller.h"
#include "apit002cursosservice.h"

static ApiT002CursosService service;


void ApiT002CursosController::index()
{
    auto json = service.index();
    renderJson(json);
}

void ApiT002CursosController::get(const QString &c002Id)
{
    auto json = service.get(c002Id.toInt());
    renderJson(json);
}

void ApiT002CursosController::create()
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

void ApiT002CursosController::save(const QString &c002Id)
{
    QJsonObject json;

    switch (request().method()) {
    case Tf::Post:
        json = service.save(request(), c002Id.toInt());
        break;
    default:
        setStatusCode(Tf::BadRequest);
        break;
    }
    renderJson(json);
}

void ApiT002CursosController::remove(const QString &c002Id)
{
    QJsonObject json;

    switch (request().method()) {
    case Tf::Post:
        json = service.remove(c002Id.toInt());
        break;
    default:
        setStatusCode(Tf::BadRequest);
        return;
    }
    renderJson(json);
}

// Don't remove below this line
T_DEFINE_CONTROLLER(ApiT002CursosController)
