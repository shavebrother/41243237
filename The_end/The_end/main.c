#include "Header.h"

//�C�|�Ҧ�
enum GameMode {
    INTRODUCTION = 1,
    ACC,
    EXIT
};


int main() {
    int mode;

    printf("=============== �ƿW�p�@�� ===============\n");

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
            printf("���~�Ҧ��C�Э��s�A�աC\n");
        }

    } while (mode != EXIT);

    return 0;
}
