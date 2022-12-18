#pragma once
#include <TGlobal>
#include <QJsonObject>

class THttpRequest;
class TSession;


class T_MODEL_EXPORT ApiT004UsuarioCursoService {
public:
    QJsonObject index();
    QJsonObject get(int c004Id);
    QJsonObject create(THttpRequest &request);
    QJsonObject save(THttpRequest &request, int c004Id);
    QJsonObject remove(int c004Id);
};

