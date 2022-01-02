#include <stdio.h>
#include <stdlib.h> 
#include <windows.h>
#include <time.h>
#include <string.h>

void ft_swap(char **s1, char **s2)
{
    char *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int main()
{
    system("cls");
    char *test = "hello";
    char *test2 = "sinyor";

    printf("%s\t%s\n",test,test2);
    ft_swap(&test,&test2);
    printf("%s\t%s",test,test2);
}