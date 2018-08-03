#ifndef LIBRARY_H
#define LIBRARY_H
#include <QString>
#include <film.h>

class Library
{
public:
    Library();
    Library(int num);
    Film *arr;
    QString info;
    int n;
    void sort();
};

#endif // LIBRARY_H
