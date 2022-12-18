#include <TreeFrogModel>
#include "t003docentes.h"
#include "sqlobjects/t003docentesobject.h"


T003Docentes::T003Docentes() :
    TAbstractModel(),
    d(new T003DocentesObject())
{
    // set the initial parameters
}

T003Docentes::T003Docentes(const T003Docentes &other) :
    TAbstractModel(),
    d(other.d)
{ }

T003Docentes::T003Docentes(const T003DocentesObject &object) :
    TAbstractModel(),
    d(new T003DocentesObject(object))
{ }

T003Docentes::~T003Docentes()
{
    // If the reference count becomes 0,
    // the shared data object 'T003DocentesObject' is deleted.
}

int T003Docentes::c003Id() const
{
    return d->c003_id;
}

QString T003Docentes::c003Imagen() const
{
    return d->c003_imagen;
}

void T003Docentes::setC003Imagen(const QString &c003Imagen)
{
    d->c003_imagen = c003Imagen;
}

QString T003Docentes::c003Nombre() const
{
    return d->c003_nombre;
}

void T003Docentes::setC003Nombre(const QString &c003Nombre)
{
    d->c003_nombre = c003Nombre;
}

QString T003Docentes::c003Correo() const
{
    return d->c003_correo;
}

void T003Docentes::setC003Correo(const QString &c003Correo)
{
    d->c003_correo = c003Correo;
}

QDateTime T003Docentes::c003FechaCreacion() const
{
    return d->c003_fecha_creacion;
}

void T003Docentes::setC003FechaCreacion(const QDateTime &c003FechaCreacion)
{
    d->c003_fecha_creacion = c003FechaCreacion;
}

QDateTime T003Docentes::c003FechaActualizacion() const
{
    return d->c003_fecha_actualizacion;
}

void T003Docentes::setC003FechaActualizacion(const QDateTime &c003FechaActualizacion)
{
    d->c003_fecha_actualizacion = c003FechaActualizacion;
}

T003Docentes &T003Docentes::operator=(const T003Docentes &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

T003Docentes T003Docentes::create(const QString &c003Imagen, const QString &c003Nombre, const QString &c003Correo, const QDateTime &c003FechaCreacion, const QDateTime &c003FechaActualizacion)
{
    T003DocentesObject obj;
    obj.c003_imagen = c003Imagen;
    obj.c003_nombre = c003Nombre;
    obj.c003_correo = c003Correo;
    obj.c003_fecha_creacion = c003FechaCreacion;
    obj.c003_fecha_actualizacion = c003FechaActualizacion;
    if (!obj.create()) {
        return T003Docentes();
    }
    return T003Docentes(obj);
}

T003Docentes T003Docentes::create(const QVariantMap &values)
{
    T003Docentes model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

T003Docentes T003Docentes::get(int c003Id)
{
    TSqlORMapper<T003DocentesObject> mapper;
    return T003Docentes(mapper.findByPrimaryKey(c003Id));
}

int T003Docentes::count()
{
    TSqlORMapper<T003DocentesObject> mapper;
    return mapper.findCount();
}

QList<T003Docentes> T003Docentes::getAll()
{
    return tfGetModelListByCriteria<T003Docentes, T003DocentesObject>(TCriteria());
}

QJsonArray T003Docentes::getAllJson(const QStringList &properties)
{
    return tfConvertToJsonArray(getAll(), properties);
}

TModelObject *T003Docentes::modelData()
{
    return d.data();
}

const TModelObject *T003Docentes::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const T003Docentes &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, T003Docentes &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(T003Docentes)
