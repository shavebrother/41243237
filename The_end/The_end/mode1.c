#include "Header.h"

void playGameMode1() {

    int userInput;

    printf("\n�ƿW������� 9x9 ���Ů�զ��C �z�u��ϥαq 1 �� 9 ���Ʀr�C\n");
    printf("�C�� 3x3 ���E�c�椤�u��t���Ʀr 1 �� 9�C �C�@��u��t���Ʀr 1 �� 9�C\n");
    printf("�C�@�C�u��t���Ʀr 1 �� 9�C\n");
    printf("�b�C�� 3x3 �E�c��B�C�@��B�C�@�C���A�C�ӼƦr�u��ϥΤ@���C\n\n");
    printf("�C���ͩR�Ȭ� 5 ,�����|���ͩR��");
    printf("\033[4m\033[1;33m�p�G�ͩR�Ȭ� 0 ,�h�C����F\033[m\n\n\n");

    printf("���U 0 �^�D�{��: ");
    scanf("%d", &userInput);

    while (1) {
        if (userInput == 0) {
            while (getchar() != '\n');
            printf("�^��椤...\n"); Sleep(1000); system("cls"); break;
        }
        else {
            printf("������ܡC\n");
            printf("���U 0 �^�D�{��: ");
            scanf("%d", &userInput);
        }
    }

}