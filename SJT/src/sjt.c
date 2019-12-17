

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "sjt.h"


void sjt(int* perm, bool flag, int n, int max, int count)
{
    if(count >= max)return;

    if(flag == true)
    {
        for(int i = 0; i < n-1; i++)
        {
            char* s = printPerm(perm, n);
            printf("%s\n", s);
            free(s);
            int temp = perm[i];
            perm[i] = perm[i+1];
            perm[i+1] = temp;
            count++;
        }
        char* s = printPerm(perm, n);
        printf("%s\n", s);
        free(s);
        int temp = perm[0];
        perm[0] = perm[1];
        perm[1] = temp;
        s = printPerm(perm, n);
        printf("%s\n", s);
        free(s);
        count++;
        flag = false;
        sjt(perm, flag, n, max, count);
    }
    if(flag == false)
    {
        for(int i=n-1; i > 0; i--)
        {
            int temp = perm[i];
            perm[i] = perm[i-1];
            perm[i-1] = temp;
            char* s = printPerm(perm, n);
            printf("%s\n", s);
            free(s);
            count++;
        }
        flag = true;
        sjt(perm, flag, n, max, count);
    }
}


char* printPerm(int * perm, int size)
{
    printf("entrring\n");
    char* s = calloc(100, sizeof(char));
    char temp[100];
    for(int i = 0; i < size; i++)
    {
        sprintf(temp, "%d", perm[i]);
        strcat(s, temp);
    }
    printf("Leaving\n");
    return s;
}