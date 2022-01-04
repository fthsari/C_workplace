//
//  main.c
//  ProjectAttempt1
//
//  Created by Mehmet Soner Korucu on 1.01.2022.
//

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

struct gamestate
{
 int planePos;
 int bombPos;
 int distance;
 int index;
 int letter;
 int score;
};



struct gamestate save = {0,0,0,0,0,0};
void loadGame(void)
{
    char userName[20];
    char fileName[25];
    printf("Please write a file name to load game: ");
    scanf("%s",userName);
    printf("Searching for file..\n");
    sleep(1);
    sprintf(fileName,"%s.txt",userName);
    FILE *savePtr = fopen(fileName,"r");
    if(savePtr == NULL)
    {
        printf("No such file.\nReturning to menu...");
        sleep(1);
        system("cls");
        theMenu();
    }
    else
    {
        printf("File founded.\nLoading game...");
        sleep(1);
        fscanf(savePtr,"%d%d%d%d%d%d",&save.planePos,&save.bombPos,&save.distance,&save.index,&save.letter,&save.score);
        fclose(savePtr);
    }
    gamePlay();
}
void saveGame(void)
{
    if(save.planePos== 0 && save.bombPos== 0 && save.distance==0 && save.index== 0 && save.letter==0 && save.score==0)
    {
        system("cls");
        printf("You really wanna save the default game??\nReturning menu...");
        sleep(1);
        system("cls");
        theMenu();
    }
    char userName[20];
    char fileName[25];
    printf("Please write a file name to save game: ");
    scanf("%s",userName);
    sprintf(fileName,"%s.txt",userName);
    FILE *savePtr = fopen(fileName,"w");
    if(savePtr == NULL) printf("no save founded.\n");
    else
    {
        fprintf(savePtr,"%d\n%d\n%d\n%d\n%d\n%d\n",save.planePos,save.bombPos,save.distance,save.index,save.letter,save.score);
        fclose(savePtr);
    }
    printf("Game is being saved...\n");
    sleep(1);
    printf("Game saved successfully!\n");
    sleep(1);
    system("cls");
    theMenu();
}

void gamePlay(void)
{
    char words[40][11] = {"ape","car","big","123","book","door","epic","band","test","apple","catch","super","level","small","basket","mehmet","hatice","carbon","program","buzzcut","jimjams","muzzles","puzzles","dazzled","football","absolute","campaign","casualty","division","quizzical","twizzling","bedazzled","fuzziness","maximizer","strawberry","friendship","motivation","everything","undertaker"};

    system("cls");
    int reverseDistance = 15 - save.distance;
    int sleepTime = 200000;
    while(1)
        {
            while (_kbhit())
            {
                char c = _getch();
                if (c == 27)
                {
                    system("cls");
                    theMenu();
                }
                else if(c==words[save.index][save.letter])
                {
                    save.score++;
                    if(words[save.index][save.letter+1]== '\0')
                    {
                        save.index++;
                        save.letter=0;
                        save.distance=0;
                        reverseDistance = 15 - save.distance;
                        if ((save.planePos/8)%2 == 0) save.bombPos = save.planePos;
                        if ((save.planePos/8)%2 == 1) save.bombPos = 16-save.planePos;
                    }
                    else save.letter++;
                }
                else if(save.score >0) save.score--;
            }
            FILE *city = fopen("city.txt","r");
            save.distance ++;
            reverseDistance--;
            char cityCH;
            system("cls");
            if((save.planePos/32)%2 == 1) save.planePos =0;
            if((save.planePos/16)%2 == 0)
            {
                for(int d = save.planePos; d>0;d--) printf("  ");
                printf("(|__.-. |");
                for(int d = save.planePos; d<22;d++) printf("  ");
                printf("SCORE: %d\n",save.score);
                for(int d = save.planePos; d>0;d--) printf("  ");
                printf("== ===_]+\n");
                for(int d = save.planePos; d>0;d--) printf("  ");
                printf("        |\n");
            }
            if((save.planePos/16)%2 == 1)
            {
                for(int d = save.planePos; d<32;d++) printf("  ");
                printf("(|__.-. |");
                for(int d = save.planePos; d>10;d--) printf("  ");
                printf("SCORE: %d\n",save.score);
                for(int d = save.planePos; d<32;d++) printf("  ");
                printf("== ===_]+\n");
                for(int d = save.planePos; d<32;d++) printf("  ");
                printf("        |\n");
            }
            for(int j = reverseDistance; j<=15;j++) printf("\n");
            for(int d = save.bombPos; d>0;d--) printf("  ");
            printf("<|>\n");
            for(int d = save.bombPos; d>0;d--) printf("  ");
            printf(" |");
            for(int i= save.letter; i<11;i++) printf("%c",words[save.index][i]);
            printf("\n");
            for(int d = save.bombPos; d>0;d--) printf("  ");
            printf(" *\n");
            for (int i = save.distance; i<=15 ; i++) printf("\n");
            if(save.distance >15) break;
            while((cityCH = fgetc(city)) != EOF) putchar(cityCH);
            usleep(sleepTime);
            if(save.index%5 == 0) sleepTime -=2000;
            save.planePos++;
            fclose(city);
        }
    system("cls");
    if(save.index == 11) printf("YOU WIN!\n");
    else if (save.distance == 15) printf("YOU LOSE!\n");
    theMenu();
}
void returnGame(void)
{
    if(save.planePos== 0 && save.bombPos== 0 && save.distance==0 && save.index== 0 && save.letter==0 && save.score==0)
    {
        system("cls");
        printf("Nothing to load.\nLoading new game..");
        sleep(1);
        system("cls");
    }
    gamePlay();
}
void newGame(void)
{
    save.bombPos = 0; save.planePos = 0; save.bombPos = 0; save.distance = 0; save.index = 0; save.letter = 0; save.score = 0;
    gamePlay();
}
void theMenu()
{
    int menuInput;
    printf("1. New game\n2. Load a Saved Game\n3. Save Current Game\n4. Return to Game\n5. Exit\n");
    scanf("%d",&menuInput);
    switch(menuInput)
    {
        case 1: printf("map is being created...\n");sleep(1);newGame(); break;
        case 2: loadGame(); break;
        case 3: saveGame();break;
        case 4: printf("Return menu selected.\n"); returnGame(); break;
        case 5: break;
        default: system("cls");printf("invalid input!");sleep(1);system("cls");theMenu();
    }
}
int main()
{
    theMenu();
    system("cls");
    return 0;
}
