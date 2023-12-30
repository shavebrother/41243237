#include "Header.h"

void playGameMode1() {

    int userInput;

    printf("\n數獨的網格由 9x9 的空格組成。 您只能使用從 1 到 9 的數字。\n");
    printf("每個 3x3 的九宮格中只能含有數字 1 到 9。 每一行只能含有數字 1 到 9。\n");
    printf("每一列只能含有數字 1 到 9。\n");
    printf("在每個 3x3 九宮格、每一行、每一列中，每個數字只能使用一次。\n\n");
    printf("每次生命值為 5 ,答錯會扣生命值");
    printf("\033[4m\033[1;33m如果生命值為 0 ,則遊戲輸了\033[m\n\n\n");

    printf("按下 0 回主程式: ");
    scanf("%d", &userInput);

    while (1) {
        if (userInput == 0) {
            while (getchar() != '\n');
            printf("回選單中...\n"); Sleep(1000); system("cls"); break;
        }
        else {
            printf("未知選擇。\n");
            printf("按下 0 回主程式: ");
            scanf("%d", &userInput);
        }
    }

}