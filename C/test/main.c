#include <stdio.h>
#include "lala.h"
extern void lala();

void main()
{
#ifdef LALA
    lala();
#endif
}
