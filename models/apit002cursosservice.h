#pragma once
#include <TGlobal>
#include <QJsonObject>

class THttpRequest;
class TSession;


class T_MODEL_EXPORT ApiT002CursosService {
public:
    QJsonObject index();
    QJsonObject get(int c002Id);
    QJsonObject create(THttpRequest &request);
    QJsonObject save(THttpRequest &request, int c002Id);
    QJsonObject remove(int c002Id);
};

