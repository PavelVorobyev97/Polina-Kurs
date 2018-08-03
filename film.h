#ifndef FILM_H
#define FILM_H

#include <QString>
#include <QStringList>

class Film
{
public:
    Film();
    QString name;
    QString studio;
    QString genre;
    QString year;
    QString director;
    QStringList actors;
    QString info;


};

#endif // FILM_H
