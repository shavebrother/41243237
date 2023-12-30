#include "Header.h"

User list[User_max];

User login()//登入函式
{
    char name[20]; char pwd[20];
    User lg;
    printf("登入\n");
    printf("輸入使用者名稱:"); scanf("%s", name); strcpy(lg.name, name);
    printf("輸入使用者密碼:"); scanf("%s", pwd); strcpy(lg.pwd, pwd);
    return lg;
}

User writeToFile(User u)//寫入txt檔案，每一行存在一個使用者
{
    FILE* wf = fopen("member.txt", "a+");
    fprintf(wf, "\n");fprintf(wf, u.name); fprintf(wf, "\t"); fprintf(wf, u.pwd); fprintf(wf, "\t"); fprintf(wf, u.game);
    fclose(wf); return u;
}

int same(User u) {//判斷使否有此用戶
    for (int i = 0; i < User_max; i++) {
        if (strcmp(list[i].name, u.name) == 0 && strcmp(list[i].pwd, u.pwd) == 0) {
            return 1;
        }
    }
    return 0;
}

void registerUser()//註冊使用者
{
    char name[20];
    char pwd[20];
    User user;

    printf("| 註冊 |\n");
    printf("輸入使用者名稱:"); scanf("%s", name); strcpy(user.name, name);//複製字串

    for (int i = 0; i < User_max; i++)//判斷註冊的使用者是否已存在
        if (0 == strcmp(list[i].name, name)){
            printf("使用者名稱已經存在\n");
            return;
        }

    printf("輸入使用者密碼:"); scanf("%s", pwd); strcpy(user.pwd, pwd); strcpy(user.game, "01");
    user = writeToFile(user);
    printf("註冊成功\n"); Sleep(1000); 
    printf("\033[4m\033[1;33m請重新登錄，並開始遊戲\033[m\n\n\n"); 
    Sleep(1000); system("cls");
}

int login_menu() {//模式2介面
    int choice;

    printf("\033[4m\033[1;33m登入、註冊\033[m\n");
    printf("1.登入\n"); printf("2.註冊\n"); fflush(stdin);
    printf("輸入你的選擇:"); 
    if (scanf("%d", &choice) != 1 ) {
        printf("錯誤選擇"); fflush(stdin); choice = 0;
    }
    return choice;
}

User playGameMode2() {
    FILE* fu = fopen("member.txt", "r");//開啟使用者檔案，並讀取
    User u;//目前使用者

    if (fu == NULL) {
        printf("FILE NOT FOUND(u)\n");return u;
    }

    for (int i = 0; i < User_max; i++) {//將檔案內容全部存進list裡面
        if (fscanf(fu, "%s%s%s", list[i].name, list[i].pwd, list[i].game) != 3) {
            break;
        }
    }

    fclose(fu);

    while (1) {
        int choice = login_menu();//開啟選單

        if (choice == 1) {//登陸
            system("cls");
            u = login();
            if (same(u)) {//登陸成功，開啟遊戲
                for (int i = 0; i < User_max; i++) {
                    if (strcmp(list[i].name, u.name) == 0 && strcmp(list[i].pwd, u.pwd) == 0) {
                        strcpy(u.game, list[i].game); break;
                    }
                }
                printf("登入成功\n"); Sleep(1000); system("cls"); 
                currentUser = u;
                playGameMode3(currentUser.game);
                break;
            }
            else {//登陸失敗，重新登錄
                printf("錯誤的使用者或密碼\n");Sleep(1000);system("cls");
            }
        }
        else if (choice == 2) {//註冊帳號
            system("cls"); registerUser(); Sleep(1000); system("cls"); break;
        }
    }
}

void saveUserToFile(User u) {//當成功過關時，將此玩家關卡數+1，並覆蓋原本檔案
    FILE* wf = fopen("member.txt", "r");
    FILE* tempFile = fopen("temp.txt", "w");

    if (wf == NULL || tempFile == NULL) {
        printf("Error opening file for saving user data.\n");
        return;
    }
    for (int i = 0; i < User_max; i++) {
        while (fscanf(wf, "%s%s%s", list[i].name, list[i].pwd, list[i].game) == 3) {
            if (strcmp(list[i].name, u.name) == 0 && strcmp(list[i].pwd, u.pwd) == 0) {
                fprintf(tempFile, "%s\t%s\t%s\n", u.name, u.pwd, u.game);
            }
            else {
                fprintf(tempFile, "%s\t%s\t%s\n", list[i].name, list[i].pwd, list[i].game);
            }
        }
    }

    fclose(wf);
    fclose(tempFile);

    remove("member.txt");
    rename("temp.txt", "member.txt");
}