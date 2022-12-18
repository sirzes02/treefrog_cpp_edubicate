#pragma once
#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT T002CursosObject : public TSqlObject, public QSharedData {
public:
    int c002_id {0};
    QString c002_imagen;
    QString c002_nombre;
    QString c002_descripcion;
    QString c002_codigo;
    QString c002_salon;
    QString c002_horario;
    int c003_id_docente {0};
    QDateTime c003_fecha_creacion;
    QDateTime c003_fecha_actualizacion;

    enum PropertyIndex {
        C002Id = 0,
        C002Imagen,
        C002Nombre,
        C002Descripcion,
        C002Codigo,
        C002Salon,
        C002Horario,
        C003IdDocente,
        C003FechaCreacion,
        C003FechaActualizacion,
    };

    int primaryKeyIndex() const override { return C002Id; }
    int autoValueIndex() const override { return C002Id; }
    QString tableName() const override { return QStringLiteral("t002_cursos"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int c002_id READ getc002_id WRITE setc002_id)
    T_DEFINE_PROPERTY(int, c002_id)
    Q_PROPERTY(QString c002_imagen READ getc002_imagen WRITE setc002_imagen)
    T_DEFINE_PROPERTY(QString, c002_imagen)
    Q_PROPERTY(QString c002_nombre READ getc002_nombre WRITE setc002_nombre)
    T_DEFINE_PROPERTY(QString, c002_nombre)
    Q_PROPERTY(QString c002_descripcion READ getc002_descripcion WRITE setc002_descripcion)
    T_DEFINE_PROPERTY(QString, c002_descripcion)
    Q_PROPERTY(QString c002_codigo READ getc002_codigo WRITE setc002_codigo)
    T_DEFINE_PROPERTY(QString, c002_codigo)
    Q_PROPERTY(QString c002_salon READ getc002_salon WRITE setc002_salon)
    T_DEFINE_PROPERTY(QString, c002_salon)
    Q_PROPERTY(QString c002_horario READ getc002_horario WRITE setc002_horario)
    T_DEFINE_PROPERTY(QString, c002_horario)
    Q_PROPERTY(int c003_id_docente READ getc003_id_docente WRITE setc003_id_docente)
    T_DEFINE_PROPERTY(int, c003_id_docente)
    Q_PROPERTY(QDateTime c003_fecha_creacion READ getc003_fecha_creacion WRITE setc003_fecha_creacion)
    T_DEFINE_PROPERTY(QDateTime, c003_fecha_creacion)
    Q_PROPERTY(QDateTime c003_fecha_actualizacion READ getc003_fecha_actualizacion WRITE setc003_fecha_actualizacion)
    T_DEFINE_PROPERTY(QDateTime, c003_fecha_actualizacion)
};

