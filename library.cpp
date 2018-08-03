#include "library.h"
#include "film.h"
#include <QDebug>

Library::Library()
{

}
Library::Library(int num)
{
    n = num;
    arr = new Film [num];
}



void Library::sort()
{
    long i, j, k;
    QString x;
    Film tmp;

    for(i = 0; i < n; i++) { // i - номер текущего шага
        k = i; x = arr[i].genre; tmp = arr[i];
        for( j = i + 1; j < n; j++) // цикл выбора наименьшего элемента
            if ( arr[j].genre < x ) {
                k = j; x = arr[j].genre; tmp = arr[j];// k - индекс наименьшего элемента
            }
        arr[k] = arr[i]; arr[i] = tmp; // меняем местами наименьший с a[i]
    }
}


