//
// Created by sirzes on 17/12/22.
//
#include <TGlobal>

class T_HELPER_EXPORT Commons {
public:
    static QJsonArray error_maker(QStringList errs);
    static QString generate_uuid();

private:
    Commons() = default;
};
