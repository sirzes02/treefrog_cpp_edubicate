#include "accountcontroller.h"
#include "apit001usuariosservice.h"
#include "t000tokenservice.h"
#include "account/loginvalidator.h"
#include "commons.h"

static ApiT001UsuariosService service;
static T000TokenService serviceToken;

void AccountController::login()
{
    QJsonObject json;

    // Validations ////////////////////////////////////////////////////
    QVariantMap values = httpRequest().formItems();
    LoginValidator validator;

    if (!validator.validate(values)) {
        QStringList errs = validator.errorMessages();

        json.insert("status", "fail");
        json.insert("error", Commons::error_maker(errs));
        renderJson(json);
        return;
    }
    ////////////////////////////////////////////////////////////////////

    QString email = httpRequest().formItemValue("email");
    QString password = httpRequest().formItemValue("password");

    if (email.isEmpty() || password.isEmpty()) {
        json.insert("status", "fail");
        json.insert("error", "send all parameters");
        renderJson(json);
        return;
    }

    QJsonValue user = service.authenticate(email, password).take("user");

    if (!user.isNull()) {
        json.insert("status", "ok");

        QString token = serviceToken.create(user.toObject().take("c001Id").toInt());
        QJsonObject subObj;

        subObj.insert("user", user);
        subObj.insert("token", token);
        json.insert("result", subObj);
    } else {
        json.insert("status", "fail");
        json.insert("error", "Login failed");
    }

    renderJson(json);
}

void AccountController::logout()
{
    QJsonObject json;

    //Valdiations///////////////
    T001UsuariosObject currentUser = serviceToken.thisTokenExists(httpRequest());

    if (currentUser.isNull()){
        renderErrorResponse(401);
        return;
    }
    ////////////////////////////

    serviceToken.remove(currentUser.c001_id);
    json.insert("status", "ok");
    json.insert("result", true);

    renderJson(json);

    // write code
}

// Don't remove below this line
T_DEFINE_CONTROLLER(AccountController)
