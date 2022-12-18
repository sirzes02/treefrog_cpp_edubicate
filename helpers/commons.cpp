//
// Created by sirzes on 11/12/22.
//

#include "commons.h"
#include <QJsonArray>
#include <sstream>

static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<> dis(0, 15);
static std::uniform_int_distribution<> dis2(8, 11);

QJsonArray Commons::error_maker(QStringList errs) {
    QJsonArray arr;

    tError("Invalid Parameter : value");


    std::for_each(errs.begin(), errs.end(), [&arr](const QString &val) {
        arr.append(val);
    });

    return arr;
}

QString Commons::generate_uuid() {
    std::stringstream ss;

    int i;
    ss << std::hex;
    for (i = 0; i < 8; i++) {
        ss << dis(gen);
    }
    ss << "-";
    for (i = 0; i < 4; i++) {
        ss << dis(gen);
    }
    ss << "-4";
    for (i = 0; i < 3; i++) {
        ss << dis(gen);
    }
    ss << "-";
    ss << dis2(gen);
    for (i = 0; i < 3; i++) {
        ss << dis(gen);
    }
    ss << "-";
    for (i = 0; i < 12; i++) {
        ss << dis(gen);
    };
    return QString::fromStdString(ss.str());
}
