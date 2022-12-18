#pragma once
#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class T003DocentesObject;
class QJsonArray;


class T_MODEL_EXPORT T003Docentes : public TAbstractModel {
public:
    T003Docentes();
    T003Docentes(const T003Docentes &other);
    T003Docentes(const T003DocentesObject &object);
    ~T003Docentes();

    int c003Id() const;
    QString c003Imagen() const;
    void setC003Imagen(const QString &c003Imagen);
    QString c003Nombre() const;
    void setC003Nombre(const QString &c003Nombre);
    QString c003Correo() const;
    void setC003Correo(const QString &c003Correo);
    QDateTime c003FechaCreacion() const;
    void setC003FechaCreacion(const QDateTime &c003FechaCreacion);
    QDateTime c003FechaActualizacion() const;
    void setC003FechaActualizacion(const QDateTime &c003FechaActualizacion);
    T003Docentes &operator=(const T003Docentes &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static T003Docentes create(const QString &c003Imagen, const QString &c003Nombre, const QString &c003Correo, const QDateTime &c003FechaCreacion, const QDateTime &c003FechaActualizacion);
    static T003Docentes create(const QVariantMap &values);
    static T003Docentes get(int c003Id);
    static int count();
    static QList<T003Docentes> getAll();
    static QJsonArray getAllJson(const QStringList &properties = QStringList());

private:
    QSharedDataPointer<T003DocentesObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend T_MODEL_EXPORT QDataStream &operator<<(QDataStream &ds, const T003Docentes &model);
    friend T_MODEL_EXPORT QDataStream &operator>>(QDataStream &ds, T003Docentes &model);
};

Q_DECLARE_METATYPE(T003Docentes)
Q_DECLARE_METATYPE(QList<T003Docentes>)

