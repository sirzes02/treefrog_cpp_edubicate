#include "apit001usuarioscontroller.h"
#include "apit001usuariosservice.h"

static ApiT001UsuariosService service;


void ApiT001UsuariosController::index()
{
    auto json = service.index();
    renderJson(json);
}

void ApiT001UsuariosController::get(const QString &c001Id)
{
    auto json = service.get(c001Id.toInt());
    renderJson(json);
}

void ApiT001UsuariosController::create()
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

void ApiT001UsuariosController::save(const QString &c001Id)
{
    QJsonObject json;

    switch (request().method()) {
    case Tf::Post:
        json = service.save(request(), c001Id.toInt());
        break;
    default:
        setStatusCode(Tf::BadRequest);
        break;
    }
    renderJson(json);
}

void ApiT001UsuariosController::remove(const QString &c001Id)
{
    QJsonObject json;

    switch (request().method()) {
    case Tf::Post:
        json = service.remove(c001Id.toInt());
        break;
    default:
        setStatusCode(Tf::BadRequest);
        return;
    }
    renderJson(json);
}

// Don't remove below this line
T_DEFINE_CONTROLLER(ApiT001UsuariosController)
