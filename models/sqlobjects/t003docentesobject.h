#pragma once
#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT T003DocentesObject : public TSqlObject, public QSharedData {
public:
    int c003_id {0};
    QString c003_imagen;
    QString c003_nombre;
    QString c003_correo;
    QDateTime c003_fecha_creacion;
    QDateTime c003_fecha_actualizacion;

    enum PropertyIndex {
        C003Id = 0,
        C003Imagen,
        C003Nombre,
        C003Correo,
        C003FechaCreacion,
        C003FechaActualizacion,
    };

    int primaryKeyIndex() const override { return C003Id; }
    int autoValueIndex() const override { return C003Id; }
    QString tableName() const override { return QStringLiteral("t003_docentes"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int c003_id READ getc003_id WRITE setc003_id)
    T_DEFINE_PROPERTY(int, c003_id)
    Q_PROPERTY(QString c003_imagen READ getc003_imagen WRITE setc003_imagen)
    T_DEFINE_PROPERTY(QString, c003_imagen)
    Q_PROPERTY(QString c003_nombre READ getc003_nombre WRITE setc003_nombre)
    T_DEFINE_PROPERTY(QString, c003_nombre)
    Q_PROPERTY(QString c003_correo READ getc003_correo WRITE setc003_correo)
    T_DEFINE_PROPERTY(QString, c003_correo)
    Q_PROPERTY(QDateTime c003_fecha_creacion READ getc003_fecha_creacion WRITE setc003_fecha_creacion)
    T_DEFINE_PROPERTY(QDateTime, c003_fecha_creacion)
    Q_PROPERTY(QDateTime c003_fecha_actualizacion READ getc003_fecha_actualizacion WRITE setc003_fecha_actualizacion)
    T_DEFINE_PROPERTY(QDateTime, c003_fecha_actualizacion)
};

