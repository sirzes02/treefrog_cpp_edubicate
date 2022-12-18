#include <TreeFrogModel>
#include "t002cursos.h"
#include "sqlobjects/t002cursosobject.h"


T002Cursos::T002Cursos() :
    TAbstractModel(),
    d(new T002CursosObject())
{
    // set the initial parameters
}

T002Cursos::T002Cursos(const T002Cursos &other) :
    TAbstractModel(),
    d(other.d)
{ }

T002Cursos::T002Cursos(const T002CursosObject &object) :
    TAbstractModel(),
    d(new T002CursosObject(object))
{ }

T002Cursos::~T002Cursos()
{
    // If the reference count becomes 0,
    // the shared data object 'T002CursosObject' is deleted.
}

int T002Cursos::c002Id() const
{
    return d->c002_id;
}

QString T002Cursos::c002Imagen() const
{
    return d->c002_imagen;
}

void T002Cursos::setC002Imagen(const QString &c002Imagen)
{
    d->c002_imagen = c002Imagen;
}

QString T002Cursos::c002Nombre() const
{
    return d->c002_nombre;
}

void T002Cursos::setC002Nombre(const QString &c002Nombre)
{
    d->c002_nombre = c002Nombre;
}

QString T002Cursos::c002Descripcion() const
{
    return d->c002_descripcion;
}

void T002Cursos::setC002Descripcion(const QString &c002Descripcion)
{
    d->c002_descripcion = c002Descripcion;
}

QString T002Cursos::c002Codigo() const
{
    return d->c002_codigo;
}

void T002Cursos::setC002Codigo(const QString &c002Codigo)
{
    d->c002_codigo = c002Codigo;
}

QString T002Cursos::c002Salon() const
{
    return d->c002_salon;
}

void T002Cursos::setC002Salon(const QString &c002Salon)
{
    d->c002_salon = c002Salon;
}

QString T002Cursos::c002Horario() const
{
    return d->c002_horario;
}

void T002Cursos::setC002Horario(const QString &c002Horario)
{
    d->c002_horario = c002Horario;
}

int T002Cursos::c003IdDocente() const
{
    return d->c003_id_docente;
}

void T002Cursos::setC003IdDocente(int c003IdDocente)
{
    d->c003_id_docente = c003IdDocente;
}

QDateTime T002Cursos::c003FechaCreacion() const
{
    return d->c003_fecha_creacion;
}

void T002Cursos::setC003FechaCreacion(const QDateTime &c003FechaCreacion)
{
    d->c003_fecha_creacion = c003FechaCreacion;
}

QDateTime T002Cursos::c003FechaActualizacion() const
{
    return d->c003_fecha_actualizacion;
}

void T002Cursos::setC003FechaActualizacion(const QDateTime &c003FechaActualizacion)
{
    d->c003_fecha_actualizacion = c003FechaActualizacion;
}

T002Cursos &T002Cursos::operator=(const T002Cursos &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

T002Cursos T002Cursos::create(const QString &c002Imagen, const QString &c002Nombre, const QString &c002Descripcion, const QString &c002Codigo, const QString &c002Salon, const QString &c002Horario, int c003IdDocente, const QDateTime &c003FechaCreacion, const QDateTime &c003FechaActualizacion)
{
    T002CursosObject obj;
    obj.c002_imagen = c002Imagen;
    obj.c002_nombre = c002Nombre;
    obj.c002_descripcion = c002Descripcion;
    obj.c002_codigo = c002Codigo;
    obj.c002_salon = c002Salon;
    obj.c002_horario = c002Horario;
    obj.c003_id_docente = c003IdDocente;
    obj.c003_fecha_creacion = c003FechaCreacion;
    obj.c003_fecha_actualizacion = c003FechaActualizacion;
    if (!obj.create()) {
        return T002Cursos();
    }
    return T002Cursos(obj);
}

T002Cursos T002Cursos::create(const QVariantMap &values)
{
    T002Cursos model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

T002Cursos T002Cursos::get(int c002Id)
{
    TSqlORMapper<T002CursosObject> mapper;
    return T002Cursos(mapper.findByPrimaryKey(c002Id));
}

int T002Cursos::count()
{
    TSqlORMapper<T002CursosObject> mapper;
    return mapper.findCount();
}

QList<T002Cursos> T002Cursos::getAll()
{
    return tfGetModelListByCriteria<T002Cursos, T002CursosObject>(TCriteria());
}

QJsonArray T002Cursos::getAllJson(const QStringList &properties)
{
    return tfConvertToJsonArray(getAll(), properties);
}

TModelObject *T002Cursos::modelData()
{
    return d.data();
}

const TModelObject *T002Cursos::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const T002Cursos &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, T002Cursos &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(T002Cursos)
