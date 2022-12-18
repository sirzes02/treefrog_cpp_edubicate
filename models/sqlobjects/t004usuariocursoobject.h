#pragma once
#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT T004UsuarioCursoObject : public TSqlObject, public QSharedData {
public:
    int c004_id {0};
    int c001_id_usuario {0};
    int c002_id_curso {0};
    QDateTime c004_fecha_creacion;
    QDateTime c004_fecha_actualizacion;

    enum PropertyIndex {
        C004Id = 0,
        C001IdUsuario,
        C002IdCurso,
        C004FechaCreacion,
        C004FechaActualizacion,
    };

    int primaryKeyIndex() const override { return C004Id; }
    int autoValueIndex() const override { return C004Id; }
    QString tableName() const override { return QStringLiteral("t004_usuario_curso"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int c004_id READ getc004_id WRITE setc004_id)
    T_DEFINE_PROPERTY(int, c004_id)
    Q_PROPERTY(int c001_id_usuario READ getc001_id_usuario WRITE setc001_id_usuario)
    T_DEFINE_PROPERTY(int, c001_id_usuario)
    Q_PROPERTY(int c002_id_curso READ getc002_id_curso WRITE setc002_id_curso)
    T_DEFINE_PROPERTY(int, c002_id_curso)
    Q_PROPERTY(QDateTime c004_fecha_creacion READ getc004_fecha_creacion WRITE setc004_fecha_creacion)
    T_DEFINE_PROPERTY(QDateTime, c004_fecha_creacion)
    Q_PROPERTY(QDateTime c004_fecha_actualizacion READ getc004_fecha_actualizacion WRITE setc004_fecha_actualizacion)
    T_DEFINE_PROPERTY(QDateTime, c004_fecha_actualizacion)
};

