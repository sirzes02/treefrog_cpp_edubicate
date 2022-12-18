#include "apit004usuariocursocontroller.h"
#include "apit004usuariocursoservice.h"

static ApiT004UsuarioCursoService service;


void ApiT004UsuarioCursoController::index()
{
    auto json = service.index();
    renderJson(json);
}

void ApiT004UsuarioCursoController::get(const QString &c004Id)
{
    auto json = service.get(c004Id.toInt());
    renderJson(json);
}

void ApiT004UsuarioCursoController::create()
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

void ApiT004UsuarioCursoController::save(const QString &c004Id)
{
    QJsonObject json;

    switch (request().method()) {
    case Tf::Post:
        json = service.save(request(), c004Id.toInt());
        break;
    default:
        setStatusCode(Tf::BadRequest);
        break;
    }
    renderJson(json);
}

void ApiT004UsuarioCursoController::remove(const QString &c004Id)
{
    QJsonObject json;

    switch (request().method()) {
    case Tf::Post:
        json = service.remove(c004Id.toInt());
        break;
    default:
        setStatusCode(Tf::BadRequest);
        return;
    }
    renderJson(json);
}

// Don't remove below this line
T_DEFINE_CONTROLLER(ApiT004UsuarioCursoController)
