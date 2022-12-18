#pragma once
#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class T004UsuarioCursoObject;
class QJsonArray;


class T_MODEL_EXPORT T004UsuarioCurso : public TAbstractModel {
public:
    T004UsuarioCurso();
    T004UsuarioCurso(const T004UsuarioCurso &other);
    T004UsuarioCurso(const T004UsuarioCursoObject &object);
    ~T004UsuarioCurso();

    int c004Id() const;
    int c001IdUsuario() const;
    void setC001IdUsuario(int c001IdUsuario);
    int c002IdCurso() const;
    void setC002IdCurso(int c002IdCurso);
    QDateTime c004FechaCreacion() const;
    void setC004FechaCreacion(const QDateTime &c004FechaCreacion);
    QDateTime c004FechaActualizacion() const;
    void setC004FechaActualizacion(const QDateTime &c004FechaActualizacion);
    T004UsuarioCurso &operator=(const T004UsuarioCurso &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static T004UsuarioCurso create(int c001IdUsuario, int c002IdCurso, const QDateTime &c004FechaCreacion, const QDateTime &c004FechaActualizacion);
    static T004UsuarioCurso create(const QVariantMap &values);
    static T004UsuarioCurso get(int c004Id);
    static int count();
    static QList<T004UsuarioCurso> getAll();
    static QJsonArray getAllJson(const QStringList &properties = QStringList());

private:
    QSharedDataPointer<T004UsuarioCursoObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend T_MODEL_EXPORT QDataStream &operator<<(QDataStream &ds, const T004UsuarioCurso &model);
    friend T_MODEL_EXPORT QDataStream &operator>>(QDataStream &ds, T004UsuarioCurso &model);
};

Q_DECLARE_METATYPE(T004UsuarioCurso)
Q_DECLARE_METATYPE(QList<T004UsuarioCurso>)

