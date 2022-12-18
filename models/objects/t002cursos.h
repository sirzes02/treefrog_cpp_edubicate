#pragma once
#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class T002CursosObject;
class QJsonArray;


class T_MODEL_EXPORT T002Cursos : public TAbstractModel {
public:
    T002Cursos();
    T002Cursos(const T002Cursos &other);
    T002Cursos(const T002CursosObject &object);
    ~T002Cursos();

    int c002Id() const;
    QString c002Imagen() const;
    void setC002Imagen(const QString &c002Imagen);
    QString c002Nombre() const;
    void setC002Nombre(const QString &c002Nombre);
    QString c002Descripcion() const;
    void setC002Descripcion(const QString &c002Descripcion);
    QString c002Codigo() const;
    void setC002Codigo(const QString &c002Codigo);
    QString c002Salon() const;
    void setC002Salon(const QString &c002Salon);
    QString c002Horario() const;
    void setC002Horario(const QString &c002Horario);
    int c003IdDocente() const;
    void setC003IdDocente(int c003IdDocente);
    QDateTime c003FechaCreacion() const;
    void setC003FechaCreacion(const QDateTime &c003FechaCreacion);
    QDateTime c003FechaActualizacion() const;
    void setC003FechaActualizacion(const QDateTime &c003FechaActualizacion);
    T002Cursos &operator=(const T002Cursos &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static T002Cursos create(const QString &c002Imagen, const QString &c002Nombre, const QString &c002Descripcion, const QString &c002Codigo, const QString &c002Salon, const QString &c002Horario, int c003IdDocente, const QDateTime &c003FechaCreacion, const QDateTime &c003FechaActualizacion);
    static T002Cursos create(const QVariantMap &values);
    static T002Cursos get(int c002Id);
    static int count();
    static QList<T002Cursos> getAll();
    static QJsonArray getAllJson(const QStringList &properties = QStringList());

private:
    QSharedDataPointer<T002CursosObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend T_MODEL_EXPORT QDataStream &operator<<(QDataStream &ds, const T002Cursos &model);
    friend T_MODEL_EXPORT QDataStream &operator>>(QDataStream &ds, T002Cursos &model);
};

Q_DECLARE_METATYPE(T002Cursos)
Q_DECLARE_METATYPE(QList<T002Cursos>)

