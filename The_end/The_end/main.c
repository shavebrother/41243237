#include "Header.h"

//列舉模式
enum GameMode {
    INTRODUCTION = 1,
    ACC,
    EXIT
};


int main() {
    int mode;

    printf("=============== 數獨小世界 ===============\n");

    do {
        mode = gameModeSelection();

        switch (mode) {
        case INTRODUCTION:
            playGameMode1();
            break;
        case ACC:
            playGameMode2();
            break;
        case EXIT:
            break;
        default:
            printf("錯誤模式。請重新再試。\n");
        }

    } while (mode != EXIT);

    return 0;
}
