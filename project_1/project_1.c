#include <stdio.h>
#include <stdlib.h> 
#include <windows.h>
#include <time.h>

int main()
{
    int a = 0;
    while (a < 55)
    {
        system("cls");
        FILE *plane = fopen("plane.txt", "r");
        FILE *city = fopen("city.txt","r");

        char *p_ch, c_ch;
        int len;
        char str1[8], str2[2], str3[3], str4[7], str5[2];
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