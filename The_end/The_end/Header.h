#define _CRT_SECURE_NO_WARNINGS

#define User_max 20

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>

typedef struct
{
    char name[20]; char pwd[20]; char game[20];
}User;

User currentUser;

int gameModeSelection();
void playGameMode1();
User playGameMode2(); 
User writeToFile(); 
int same(); 
void registerUser(); 
int login_menu();


int playGameMode3(const char*);
void printque();
int isGameWon();
void saveUserToFile(User);