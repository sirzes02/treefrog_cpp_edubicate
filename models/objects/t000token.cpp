#include <TreeFrogModel>
#include "t000token.h"
#include "sqlobjects/t000tokenobject.h"


T000Token::T000Token() :
    TAbstractModel(),
    d(new T000TokenObject())
{
    // set the initial parameters
}

T000Token::T000Token(const T000Token &other) :
    TAbstractModel(),
    d(other.d)
{ }

T000Token::T000Token(const T000TokenObject &object) :
    TAbstractModel(),
    d(new T000TokenObject(object))
{ }

T000Token::~T000Token()
{
    // If the reference count becomes 0,
    // the shared data object 'T000TokenObject' is deleted.
}

int T000Token::c000Id() const
{
    return d->c000_id;
}

QString T000Token::c000Token() const
{
    return d->c000_token;
}

void T000Token::setC000Token(const QString &c000Token)
{
    d->c000_token = c000Token;
}

int T000Token::c001IdUsuario() const
{
    return d->c001_id_usuario;
}

void T000Token::setC001IdUsuario(int c001IdUsuario)
{
    d->c001_id_usuario = c001IdUsuario;
}

QDateTime T000Token::c000FechaCreacion() const
{
    return d->c000_fecha_creacion;
}

void T000Token::setC000FechaCreacion(const QDateTime &c000FechaCreacion)
{
    d->c000_fecha_creacion = c000FechaCreacion;
}

T000Token &T000Token::operator=(const T000Token &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

T000Token T000Token::create(const QString &c000Token, int c001IdUsuario, const QDateTime &c000FechaCreacion)
{
    T000TokenObject obj;
    obj.c000_token = c000Token;
    obj.c001_id_usuario = c001IdUsuario;
    obj.c000_fecha_creacion = c000FechaCreacion;
    if (!obj.create()) {
        return T000Token();
    }
    return T000Token(obj);
}

T000Token T000Token::create(const QVariantMap &values)
{
    T000Token model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

T000Token T000Token::get(int c000Id)
{
    TSqlORMapper<T000TokenObject> mapper;
    return T000Token(mapper.findByPrimaryKey(c000Id));
}

int T000Token::count()
{
    TSqlORMapper<T000TokenObject> mapper;
    return mapper.findCount();
}

QList<T000Token> T000Token::getAll()
{
    return tfGetModelListByCriteria<T000Token, T000TokenObject>(TCriteria());
}

QJsonArray T000Token::getAllJson(const QStringList &properties)
{
    return tfConvertToJsonArray(getAll(), properties);
}

TModelObject *T000Token::modelData()
{
    return d.data();
}

const TModelObject *T000Token::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const T000Token &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, T000Token &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(T000Token)
