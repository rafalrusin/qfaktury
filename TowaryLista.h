#ifndef TowaryLista_H
#define TowaryLista_H
#include <QDialog>
#include "ui_TowaryLista.h"
class TowaryLista: public QDialog, public Ui::TowaryLista {
    Q_OBJECT
void init ();
    public:
    TowaryLista(QWidget *parent);
    public slots:
void readTow (QString progDir);
void doAccept ();
void comboBox1Changed (int x);
void calcNetto ();
void fillLv (int x);
void lv1selChanged (QListWidgetItem * item);
void readNettos (QString index);
void spinChanged (int a);
    public:
    QString selectedItem;
    QString progDir;
    QString ret;
    QMap<int, QString> nettos;
    QString id;
};
#endif