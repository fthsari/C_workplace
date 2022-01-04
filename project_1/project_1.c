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
    int a = 0;
    while (a < 55 && a >= 0)
    {
        system("cls");
        FILE *plane = fopen("plane.txt", "r");
        FILE *city = fopen("city.txt","r");

        char *p_ch, c_ch;
        int len;
        char str1[10], str2[10], str3[10], str4[10], str5[10];
        p_ch = malloc((a+1) * sizeof(char));
        for(int t = 0; t < a; t++)
        {
            p_ch[t] = ' ';
        }
        p_ch[a] = '\0';
        fscanf(plane, "%s %s %s %s %s", str1,str2,str3,str4,str5);
        printf("%s%s %s\n",p_ch,str1, str2);
        printf("%s%s %s\n",p_ch,str3, str4);
        printf("%s        %s\n",p_ch,str5);
        for (int i = 0; i < 20; i++)
        {
            putchar('\n');
        }
        while ((c_ch = fgetc(city)) != EOF)
        {
            putchar(c_ch);
        }

        fclose(plane);
        fclose(city);
        a++;
    }
    return 0;
}