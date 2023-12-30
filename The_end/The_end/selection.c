#include "Header.h"

int gameModeSelection() {
    int mode;
    printf("模式1: 遊戲介紹, 模式2: 註冊或登陸, 模式3: 離開\n");
    printf("請選擇模式: ");
    scanf("%d", &mode); system("cls");
    return mode;
}