#pragma once
#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT T000TokenObject : public TSqlObject, public QSharedData {
public:
    int c000_id {0};
    QString c000_token;
    int c001_id_usuario {0};
    QDateTime c000_fecha_creacion;

    enum PropertyIndex {
        C000Id = 0,
        C000Token,
        C001IdUsuario,
        C000FechaCreacion,
    };

    int primaryKeyIndex() const override { return C000Id; }
    int autoValueIndex() const override { return C000Id; }
    QString tableName() const override { return QStringLiteral("t000_token"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int c000_id READ getc000_id WRITE setc000_id)
    T_DEFINE_PROPERTY(int, c000_id)
    Q_PROPERTY(QString c000_token READ getc000_token WRITE setc000_token)
    T_DEFINE_PROPERTY(QString, c000_token)
    Q_PROPERTY(int c001_id_usuario READ getc001_id_usuario WRITE setc001_id_usuario)
    T_DEFINE_PROPERTY(int, c001_id_usuario)
    Q_PROPERTY(QDateTime c000_fecha_creacion READ getc000_fecha_creacion WRITE setc000_fecha_creacion)
    T_DEFINE_PROPERTY(QDateTime, c000_fecha_creacion)
};

