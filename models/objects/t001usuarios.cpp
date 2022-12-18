#include <TreeFrogModel>
#include "t001usuarios.h"
#include "sqlobjects/t001usuariosobject.h"

T001Usuarios::T001Usuarios() :
        TAbstractModel(),
        d(new T001UsuariosObject()) {
    // set the initial parameters
}

T001Usuarios::T001Usuarios(const T001Usuarios &other) :
        TAbstractModel(),
        d(other.d) {}

T001Usuarios::T001Usuarios(const T001UsuariosObject &object) :
        TAbstractModel(),
        d(new T001UsuariosObject(object)) {}

T001Usuarios::~T001Usuarios() {
    // If the reference count becomes 0,
    // the shared data object 'T001UsuariosObject' is deleted.
}

int T001Usuarios::c001Id() const {
    return d->c001_id;
}

QString T001Usuarios::c001Cedula() const {
    return d->c001_cedula;
}

void T001Usuarios::setC001Cedula(const QString &c001Cedula) {
    d->c001_cedula = c001Cedula;
}

QString T001Usuarios::c001Contrasena() const {
    return d->c001_contrasena;
}

void T001Usuarios::setC001Contrasena(const QString &c001Contrasena) {
    d->c001_contrasena = c001Contrasena;
}

QString T001Usuarios::c001Nombre() const {
    return d->c001_nombre;
}

void T001Usuarios::setC001Nombre(const QString &c001Nombre) {
    d->c001_nombre = c001Nombre;
}

QString T001Usuarios::c001Email() const {
    return d->c001_email;
}

void T001Usuarios::setC001Email(const QString &c001Email) {
    d->c001_email = c001Email;
}

QString T001Usuarios::c001Foto() const {
    return d->c001_foto;
}

void T001Usuarios::setC001Foto(const QString &c001Foto) {
    d->c001_foto = c001Foto;
}

QDateTime T001Usuarios::c001FechaCreacion() const {
    return d->c001_fecha_creacion;
}

void T001Usuarios::setC001FechaCreacion(const QDateTime &c001FechaCreacion) {
    d->c001_fecha_creacion = c001FechaCreacion;
}

QDateTime T001Usuarios::c001FechaActualizacion() const {
    return d->c001_fecha_actualizacion;
}

void T001Usuarios::setC001FechaActualizacion(const QDateTime &c001FechaActualizacion) {
    d->c001_fecha_actualizacion = c001FechaActualizacion;
}

T001Usuarios &T001Usuarios::operator=(const T001Usuarios &other) {
    d = other.d;  // increments the reference count of the data
    return *this;
}

T001Usuarios T001Usuarios::create(const QString &c001Cedula, const QString &c001Contrasena, const QString &c001Nombre,
                                  const QString &c001Email, const QString &c001Foto, const QDateTime &c001FechaCreacion,
                                  const QDateTime &c001FechaActualizacion) {
    T001UsuariosObject obj;
    obj.c001_cedula = c001Cedula;
    obj.c001_contrasena = c001Contrasena;
    obj.c001_nombre = c001Nombre;
    obj.c001_email = c001Email;
    obj.c001_foto = c001Foto;
    obj.c001_fecha_creacion = c001FechaCreacion;
    obj.c001_fecha_actualizacion = c001FechaActualizacion;
    if (!obj.create()) {
        return T001Usuarios();
    }
    return T001Usuarios(obj);
}

T001Usuarios T001Usuarios::create(const QVariantMap &values) {
    T001Usuarios model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

T001Usuarios T001Usuarios::get(int c001Id) {
    TSqlORMapper<T001UsuariosObject> mapper;
    return T001Usuarios(mapper.findByPrimaryKey(c001Id));
}

int T001Usuarios::count() {
    TSqlORMapper<T001UsuariosObject> mapper;
    return mapper.findCount();
}

QList<T001Usuarios> T001Usuarios::getAll() {
    return tfGetModelListByCriteria<T001Usuarios, T001UsuariosObject>(TCriteria());
}

QJsonArray T001Usuarios::getAllJson(const QStringList &properties) {
    return tfConvertToJsonArray(getAll(), properties);
}

TModelObject *T001Usuarios::modelData() {
    return d.data();
}

const TModelObject *T001Usuarios::modelData() const {
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const T001Usuarios &model) {
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, T001Usuarios &model) {
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

T001Usuarios T001Usuarios::authenticate(const QString &email, const QString &password) {
    TSqlORMapper<T001UsuariosObject> mapper;
    T001UsuariosObject obj = mapper.findFirst(TCriteria(T001UsuariosObject::C001Email, email));

    if (obj.isNull() || obj.c001_contrasena != password) {
        obj.clear();
    }

    return obj;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(T001Usuarios)
