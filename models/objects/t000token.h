#pragma once
#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class T000TokenObject;
class QJsonArray;


class T_MODEL_EXPORT T000Token : public TAbstractModel {
public:
    T000Token();
    T000Token(const T000Token &other);
    T000Token(const T000TokenObject &object);
    ~T000Token();

    int c000Id() const;
    QString c000Token() const;
    void setC000Token(const QString &c000Token);
    int c001IdUsuario() const;
    void setC001IdUsuario(int c001IdUsuario);
    QDateTime c000FechaCreacion() const;
    void setC000FechaCreacion(const QDateTime &c000FechaCreacion);
    T000Token &operator=(const T000Token &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static T000Token create(const QString &c000Token, int c001IdUsuario, const QDateTime &c000FechaCreacion);
    static T000Token create(const QVariantMap &values);
    static T000Token get(int c000Id);
    static int count();
    static QList<T000Token> getAll();
    static QJsonArray getAllJson(const QStringList &properties = QStringList());

private:
    QSharedDataPointer<T000TokenObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend T_MODEL_EXPORT QDataStream &operator<<(QDataStream &ds, const T000Token &model);
    friend T_MODEL_EXPORT QDataStream &operator>>(QDataStream &ds, T000Token &model);
};

Q_DECLARE_METATYPE(T000Token)
Q_DECLARE_METATYPE(QList<T000Token>)

