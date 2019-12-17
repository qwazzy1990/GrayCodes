#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sjt.h"

int main(int argc, char* argv[])
{

    int* perm = calloc(4, sizeof(int));
     for(int i = 1; i < 5; i++)perm[i-1] = i;
     sjt(perm, true, 4, 24, 0);
    // free(perm);

    return 0;
}