#include "common.h"
int cmp_int( void *p, void *q )
{
    int *a;
    int *b;

    a = ( int * )p;
    b = ( int * )q;

    if( *a < *b )
        return 1;
    else
        return 0;
}

int cmp_struct( void *p, void *q )
{
    Book a;
    Book b;

    a = (Book)p;
    b = (Book)q;

    if( a -> id < b -> id )
        return 1;
    else
        return 0;
}
