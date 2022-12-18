#pragma once
#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class T001UsuariosObject;
class QJsonArray;


class T_MODEL_EXPORT T001Usuarios : public TAbstractModel {
public:
    T001Usuarios();
    T001Usuarios(const T001Usuarios &other);
    T001Usuarios(const T001UsuariosObject &object);
    ~T001Usuarios();

    int c001Id() const;
    QString c001Cedula() const;
    void setC001Cedula(const QString &c001Cedula);
    QString c001Contrasena() const;
    void setC001Contrasena(const QString &c001Contrasena);
    QString c001Nombre() const;
    void setC001Nombre(const QString &c001Nombre);
    QString c001Email() const;
    void setC001Email(const QString &c001Email);
    QString c001Foto() const;
    void setC001Foto(const QString &c001Foto);
    QDateTime c001FechaCreacion() const;
    void setC001FechaCreacion(const QDateTime &c001FechaCreacion);
    QDateTime c001FechaActualizacion() const;
    void setC001FechaActualizacion(const QDateTime &c001FechaActualizacion);
    T001Usuarios &operator=(const T001Usuarios &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static T001Usuarios authenticate(const QString &email, const QString &password);
    static T001Usuarios create(const QString &c001Cedula, const QString &c001Contrasena, const QString &c001Nombre, const QString &c001Email, const QString &c001Foto, const QDateTime &c001FechaCreacion, const QDateTime &c001FechaActualizacion);
    static T001Usuarios create(const QVariantMap &values);
    static T001Usuarios get(int c001Id);
    static int count();
    static QList<T001Usuarios> getAll();
    static QJsonArray getAllJson(const QStringList &properties = QStringList());

private:
    QSharedDataPointer<T001UsuariosObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend T_MODEL_EXPORT QDataStream &operator<<(QDataStream &ds, const T001Usuarios &model);
    friend T_MODEL_EXPORT QDataStream &operator>>(QDataStream &ds, T001Usuarios &model);
};

Q_DECLARE_METATYPE(T001Usuarios)
Q_DECLARE_METATYPE(QList<T001Usuarios>)

