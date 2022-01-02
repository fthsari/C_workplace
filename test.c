#include <stdio.h>
#include <stdlib.h> 
#include <windows.h>
#include <time.h>

char *str_reverse_order(char *arr,int size)
{
    char temp;
    int revIndex, arrIndex;
    revIndex = 0;
    arrIndex = size - 1;
    while (revIndex < arrIndex)
    {
        temp = arr[revIndex];
        arr[revIndex] = arr[arrIndex];
        arr[arrIndex] = temp;

        revIndex++;
        arrIndex++;
    }

    return arr;
}

int main()
{
    char *test;
    test = "hello";
    test = str_reverse_order(test,5);
    printf("%s",test);
}