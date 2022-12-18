#pragma once
#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT T001UsuariosObject : public TSqlObject, public QSharedData {
public:
    int c001_id {0};
    QString c001_cedula;
    QString c001_contrasena;
    QString c001_nombre;
    QString c001_email;
    QString c001_foto;
    QDateTime c001_fecha_creacion;
    QDateTime c001_fecha_actualizacion;

    enum PropertyIndex {
        C001Id = 0,
        C001Cedula,
        C001Contrasena,
        C001Nombre,
        C001Email,
        C001Foto,
        C001FechaCreacion,
        C001FechaActualizacion,
    };

    int primaryKeyIndex() const override { return C001Id; }
    int autoValueIndex() const override { return C001Id; }
    QString tableName() const override { return QStringLiteral("t001_usuarios"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int c001_id READ getc001_id WRITE setc001_id)
    T_DEFINE_PROPERTY(int, c001_id)
    Q_PROPERTY(QString c001_cedula READ getc001_cedula WRITE setc001_cedula)
    T_DEFINE_PROPERTY(QString, c001_cedula)
    Q_PROPERTY(QString c001_contrasena READ getc001_contrasena WRITE setc001_contrasena)
    T_DEFINE_PROPERTY(QString, c001_contrasena)
    Q_PROPERTY(QString c001_nombre READ getc001_nombre WRITE setc001_nombre)
    T_DEFINE_PROPERTY(QString, c001_nombre)
    Q_PROPERTY(QString c001_email READ getc001_email WRITE setc001_email)
    T_DEFINE_PROPERTY(QString, c001_email)
    Q_PROPERTY(QString c001_foto READ getc001_foto WRITE setc001_foto)
    T_DEFINE_PROPERTY(QString, c001_foto)
    Q_PROPERTY(QDateTime c001_fecha_creacion READ getc001_fecha_creacion WRITE setc001_fecha_creacion)
    T_DEFINE_PROPERTY(QDateTime, c001_fecha_creacion)
    Q_PROPERTY(QDateTime c001_fecha_actualizacion READ getc001_fecha_actualizacion WRITE setc001_fecha_actualizacion)
    T_DEFINE_PROPERTY(QDateTime, c001_fecha_actualizacion)
};

