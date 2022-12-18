#pragma once
#include <TGlobal>
#include <QJsonObject>

class THttpRequest;


class T_MODEL_EXPORT ApiT001UsuariosService {
public:
    QJsonObject index();
    QJsonObject get(int c001Id);
    QJsonObject create(THttpRequest &request);
    QJsonObject save(THttpRequest &request, int c001Id);
    QJsonObject remove(int c001Id);
    QJsonObject authenticate(const QString &email, const QString &password);

};

