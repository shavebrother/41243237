#include "Header.h"

FILE* game = NULL;
char ans[9][9], que[9][9];
int which, space, end = 1;
int i_x = 0, i_y = 0; char i_ans = '0';
int heal = 5;
int test = 0;

int playGameMode3(const char* many) {

    srand(time(NULL));

    if (sscanf(many, "%d", &which) != 1) {
        printf("沒有題目\n");
        return -1;
    }

    switch (which) {
    case 1:
        game = fopen("01.txt", "r");
        break;
    case 2:
        game = fopen("02.txt", "r");
        break;
    case 3:
        game = fopen("03.txt", "r");
        break;
    case 4:
        game = fopen("04.txt", "r");
        break;
    case 5:
        game = fopen("05.txt", "r");
        break;
    case 6:
        game = fopen("06.txt", "r");
        break;
    case 7:
        game = fopen("07.txt", "r");
        break;
    case 8:
        game = fopen("08.txt", "r");
        break;
    case 9:
        game = fopen("09.txt", "r");
        break;
    case 10:
        game = fopen("10.txt", "r");
        break;
    }

    if (game == NULL) {
        printf("檔案無法開啟\n");
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            fscanf(game, "%c ", &ans[i][j]);
        }
        fscanf(game, "\n");
    }

    fclose(game);

    switch (which) {
    case 1:
        game = fopen("01.txt", "r");
        break;
    case 2:
        game = fopen("02.txt", "r");
        break;
    case 3:
        game = fopen("03.txt", "r");
        break;
    case 4:
        game = fopen("04.txt", "r");
        break;
    case 5:
        game = fopen("05.txt", "r");
        break;
    case 6:
        game = fopen("06.txt", "r");
        break;
    case 7:
        game = fopen("07.txt", "r");
        break;
    case 8:
        game = fopen("08.txt", "r");
        break;
    case 9:
        game = fopen("09.txt", "r");
        break;
    case 10:
        game = fopen("10.txt", "r");
        break;
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            fscanf(game, "%c ", &que[i][j]);
        }
        fscanf(game, "\n");
    }

    fclose(game);

    for (int j = 0; j < 9; j++) {
        for (int i = 1; i < 2; i++) {
            space = rand() % 9;
            ans[j][space] = '0';
        }
    }


    while (!isGameWon()) {
        printque();

        int validInput = 0;

        while (validInput != 1) {
            printf("\n輸入座標:");
            if (scanf("%d %d", &i_x, &i_y) != 2 || i_x < 0 || i_x > 9 || i_y < 0 || i_y > 9) {
                printf("錯誤座標\n");
            }
            else {
                validInput = 1;
                i_x -= 1; i_y -= 1;
            }
        }

        validInput = 0;

        while (validInput != 1) {
            printf("輸入答案:");
            if (scanf(" %c", &i_ans) != 1) {
                printf("錯誤答案\n");
            }
            else {
                validInput = 1;
            }
        }

        if (que[i_x][i_y] == i_ans) {
            ans[i_x][i_y] = i_ans;
        }
        else {
            heal--;
        }

        Sleep(1000);
        system("cls");

        if (heal == 0) {
            printf("遊戲輸了!!");
            Sleep(1000); system("cls");
            return -1;
        }
    }

    printf("\n\033[4m\033[1;33m恭喜過關\033[m\n\n\n");
    int currentLevel;
    sscanf(many, "%d", &currentLevel);
    currentLevel++;
    sprintf(currentUser.game, "%02d", currentLevel);
    saveUserToFile(currentUser);

    return -1;
}

void printque() {

    printf("生命值:%d\n", heal);
    printf(" ");
    for (int i = 0; i < 9; i++) {
        printf("%4d", i + 1);
    }
    printf("\n  +");
    for (int i = 0; i < 9; i++) {
        printf("---+");
    }
    printf("\n");
    for (int i = 0; i < 9; i++) {
        printf("%d", i + 1); printf(" |");
        for (int j = 0; j < 9; j++) {
            printf(" %c ", ans[i][j]); printf("|");
        }
        printf("\n  +");
        for (int k = 0; k < 9; k++) {
            printf("---+");
        }
        printf("\n");
    }

}

int isGameWon() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (ans[i][j] != que[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}
