#ifndef BASEDONNEE_H
#define BASEDONNEE_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlQuery>
#include <iostream>
#include <map>
//Json
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#include "Contact.h"
#include "GestionContacts.h"
#include "Interaction.h"
#include "Tache.h"

class basedonnee : public QObject
{
    Q_OBJECT

private:
    QSqlDatabase db;
    //GestionContacts *gc;
    Contact *c;
    Interaction *I;
    Tache *T;
    string idC;
    string idI;
    string idT;

public:
    explicit basedonnee(QObject *parent = nullptr);
    ~basedonnee();

    //void remplirListGC();
    //void modifier();
    QJsonArray remplirJson();

signals:
    void envoyerContact(Contact *);
    void message(QString);
    void sendLC(list<Contact *>);
    void sendLI(list<Interaction *>, Contact *);
    void sendLCIT(map<Interaction *, list<Tache *>>, Contact *);
    void messageLI(QString, Contact *);
    void messageLITI(QString, Contact *);
    //void sendLIDA(list<Interaction *>, Contact *);
    void sendLIDA(map<Interaction *, list<Tache *>>, Contact *);
    void messageLIDA(QString, Contact *);

public slots:
    void ajouterContact(Contact *);
    void reception(string);
    void receiveEntreprise(QString);
    void receiveMail(QString);
    void receivePhone(QString);
    void r2supp();
    void recN(QString);
    void recE(QString);
    void recD(QString);
    void recInteraction(Interaction *);
    void recID(string);
    void recTache(Tache *);
    void recIDCI(string);
    void recIDCIT(string);
    void recdda(QString, QString, string);

};

#endif // BASEDONNEE_H
