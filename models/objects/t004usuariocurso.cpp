#include <TreeFrogModel>
#include "t004usuariocurso.h"
#include "sqlobjects/t004usuariocursoobject.h"


T004UsuarioCurso::T004UsuarioCurso() :
    TAbstractModel(),
    d(new T004UsuarioCursoObject())
{
    // set the initial parameters
}

T004UsuarioCurso::T004UsuarioCurso(const T004UsuarioCurso &other) :
    TAbstractModel(),
    d(other.d)
{ }

T004UsuarioCurso::T004UsuarioCurso(const T004UsuarioCursoObject &object) :
    TAbstractModel(),
    d(new T004UsuarioCursoObject(object))
{ }

T004UsuarioCurso::~T004UsuarioCurso()
{
    // If the reference count becomes 0,
    // the shared data object 'T004UsuarioCursoObject' is deleted.
}

int T004UsuarioCurso::c004Id() const
{
    return d->c004_id;
}

int T004UsuarioCurso::c001IdUsuario() const
{
    return d->c001_id_usuario;
}

void T004UsuarioCurso::setC001IdUsuario(int c001IdUsuario)
{
    d->c001_id_usuario = c001IdUsuario;
}

int T004UsuarioCurso::c002IdCurso() const
{
    return d->c002_id_curso;
}

void T004UsuarioCurso::setC002IdCurso(int c002IdCurso)
{
    d->c002_id_curso = c002IdCurso;
}

QDateTime T004UsuarioCurso::c004FechaCreacion() const
{
    return d->c004_fecha_creacion;
}

void T004UsuarioCurso::setC004FechaCreacion(const QDateTime &c004FechaCreacion)
{
    d->c004_fecha_creacion = c004FechaCreacion;
}

QDateTime T004UsuarioCurso::c004FechaActualizacion() const
{
    return d->c004_fecha_actualizacion;
}

void T004UsuarioCurso::setC004FechaActualizacion(const QDateTime &c004FechaActualizacion)
{
    d->c004_fecha_actualizacion = c004FechaActualizacion;
}

T004UsuarioCurso &T004UsuarioCurso::operator=(const T004UsuarioCurso &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

T004UsuarioCurso T004UsuarioCurso::create(int c001IdUsuario, int c002IdCurso, const QDateTime &c004FechaCreacion, const QDateTime &c004FechaActualizacion)
{
    T004UsuarioCursoObject obj;
    obj.c001_id_usuario = c001IdUsuario;
    obj.c002_id_curso = c002IdCurso;
    obj.c004_fecha_creacion = c004FechaCreacion;
    obj.c004_fecha_actualizacion = c004FechaActualizacion;
    if (!obj.create()) {
        return T004UsuarioCurso();
    }
    return T004UsuarioCurso(obj);
}

T004UsuarioCurso T004UsuarioCurso::create(const QVariantMap &values)
{
    T004UsuarioCurso model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

T004UsuarioCurso T004UsuarioCurso::get(int c004Id)
{
    TSqlORMapper<T004UsuarioCursoObject> mapper;
    return T004UsuarioCurso(mapper.findByPrimaryKey(c004Id));
}

int T004UsuarioCurso::count()
{
    TSqlORMapper<T004UsuarioCursoObject> mapper;
    return mapper.findCount();
}

QList<T004UsuarioCurso> T004UsuarioCurso::getAll()
{
    return tfGetModelListByCriteria<T004UsuarioCurso, T004UsuarioCursoObject>(TCriteria());
}

QJsonArray T004UsuarioCurso::getAllJson(const QStringList &properties)
{
    return tfConvertToJsonArray(getAll(), properties);
}

TModelObject *T004UsuarioCurso::modelData()
{
    return d.data();
}

const TModelObject *T004UsuarioCurso::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const T004UsuarioCurso &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, T004UsuarioCurso &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(T004UsuarioCurso)
