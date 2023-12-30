#include "Header.h"

User list[User_max];

User login()//�n�J�禡
{
    char name[20]; char pwd[20];
    User lg;
    printf("�n�J\n");
    printf("��J�ϥΪ̦W��:"); scanf("%s", name); strcpy(lg.name, name);
    printf("��J�ϥΪ̱K�X:"); scanf("%s", pwd); strcpy(lg.pwd, pwd);
    return lg;
}

User writeToFile(User u)//�g�Jtxt�ɮסA�C�@��s�b�@�ӨϥΪ�
{
    FILE* wf = fopen("member.txt", "a+");
    fprintf(wf, "\n");fprintf(wf, u.name); fprintf(wf, "\t"); fprintf(wf, u.pwd); fprintf(wf, "\t"); fprintf(wf, u.game);
    fclose(wf); return u;
}

int same(User u) {//�P�_�ϧ_�����Τ�
    for (int i = 0; i < User_max; i++) {
        if (strcmp(list[i].name, u.name) == 0 && strcmp(list[i].pwd, u.pwd) == 0) {
            return 1;
        }
    }
    return 0;
}

void registerUser()//���U�ϥΪ�
{
    char name[20];
    char pwd[20];
    User user;

    printf("| ���U |\n");
    printf("��J�ϥΪ̦W��:"); scanf("%s", name); strcpy(user.name, name);//�ƻs�r��

    for (int i = 0; i < User_max; i++)//�P�_���U���ϥΪ̬O�_�w�s�b
        if (0 == strcmp(list[i].name, name)){
            printf("�ϥΪ̦W�٤w�g�s�b\n");
            return;
        }

    printf("��J�ϥΪ̱K�X:"); scanf("%s", pwd); strcpy(user.pwd, pwd); strcpy(user.game, "01");
    user = writeToFile(user);
    printf("���U���\\n"); Sleep(1000); 
    printf("\033[4m\033[1;33m�Э��s�n���A�ö}�l�C��\033[m\n\n\n"); 
    Sleep(1000); system("cls");
}

int login_menu() {//�Ҧ�2����
    int choice;

    printf("\033[4m\033[1;33m�n�J�B���U\033[m\n");
    printf("1.�n�J\n"); printf("2.���U\n"); fflush(stdin);
    printf("��J�A�����:"); 
    if (scanf("%d", &choice) != 1 ) {
        printf("���~���"); fflush(stdin); choice = 0;
    }
    return choice;
}

User playGameMode2() {
    FILE* fu = fopen("member.txt", "r");//�}�ҨϥΪ��ɮסA��Ū��
    User u;//�ثe�ϥΪ�

    if (fu == NULL) {
        printf("FILE NOT FOUND(u)\n");return u;
    }

    for (int i = 0; i < User_max; i++) {//�N�ɮפ��e�����s�ilist�̭�
        if (fscanf(fu, "%s%s%s", list[i].name, list[i].pwd, list[i].game) != 3) {
            break;
        }
    }

    fclose(fu);

    while (1) {
        int choice = login_menu();//�}�ҿ��

        if (choice == 1) {//�n��
            system("cls");
            u = login();
            if (same(u)) {//�n�����\�A�}�ҹC��
                for (int i = 0; i < User_max; i++) {
                    if (strcmp(list[i].name, u.name) == 0 && strcmp(list[i].pwd, u.pwd) == 0) {
                        strcpy(u.game, list[i].game); break;
                    }
                }
                printf("�n�J���\\n"); Sleep(1000); system("cls"); 
                currentUser = u;
                playGameMode3(currentUser.game);
                break;
            }
            else {//�n�����ѡA���s�n��
                printf("���~���ϥΪ̩αK�X\n");Sleep(1000);system("cls");
            }
        }
        else if (choice == 2) {//���U�b��
            system("cls"); registerUser(); Sleep(1000); system("cls"); break;
        }
    }
}

void saveUserToFile(User u) {//���\�L���ɡA�N�����a���d��+1�A���л\�쥻�ɮ�
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