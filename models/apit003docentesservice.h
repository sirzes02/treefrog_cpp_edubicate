#pragma once
#include <TGlobal>
#include <QJsonObject>

class THttpRequest;
class TSession;


class T_MODEL_EXPORT ApiT003DocentesService {
public:
    QJsonObject index();
    QJsonObject get(int c003Id);
    QJsonObject create(THttpRequest &request);
    QJsonObject save(THttpRequest &request, int c003Id);
    QJsonObject remove(int c003Id);
};

