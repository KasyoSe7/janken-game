#include <iostream>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()
#include <Windows.h> // sleep()

using namespace std;

int main() {

    // �����̏�����
    srand(time(0));
    //�������J�E���g
    int count = 0;
    //�����J�E���g
    bool lose = false;
    //�v���C���[�o��
    int player;
    // ����񂯂�̑I����
    string hands[3] = { "�O�[", "�`���L", "�p�[" };
    //�v���C���[����
    string input;
    //�p������
    string Continue;
    //��������
    bool drow=true;
    //�v���C���[�l�[��
    string playerName;
    cout << "�v���C���[�̖��O����͂��Ă��������F";
    cin >> playerName;


    while(!lose){
        if (!drow) {
            cout << "����񂯂�I(�Â��� YES/NO)" << endl;
            cin >> Continue;
            if (Continue == "NO") {
                cout << "�Q�[�����I�����܂��B" << endl;
                cout << "������:" << count << endl;
                break;
            }
            cout << "Enter�L�[�Ŏ��֐i��...";
            cin.ignore();
            cin.get();
            system("cls");  // ��ʃN���A
        }
       
        drow = false;
        cout << "�W����..." << endl;
        Sleep(500);
        cout << "�P��..." << endl;
        Sleep(500);
        cout << "�|���I" << endl;
        Sleep(500);

        cout << "����񂯂�I�i�O�[ / �`���L / �p�[�j> "<<endl;
        cin >> input;
        
        player = -1;
        if (input == "�O�[") player = 0;
        else if (input == "�`���L") player = 1;
        else if (input == "�p�[") player = 2;
        else {
            cout << "�����ȓ��͂ł��B" << endl;
            continue;
        }


        // �R���s���[�^�̎�i0�`2�j
        int computer = rand() % 3;

        cout <<playerName<< ": " << hands[player] << endl;
        cout << "�R���s���[�^: " << hands[computer] << endl;

        // ���s����
        if (player == computer) {
            cout << "�������I" << endl;
            drow = true;
        }
        else if ((player == 0 && computer == 1) ||
            (player == 1 && computer == 2) ||
            (player == 2 && computer == 0)) {
            count += 1;
            cout <<playerName<< "�̏����I ������:" << count << endl;
        }
        else {
            cout <<playerName<< "�̕����I ������:" << count << endl;
            lose = true;
        }
    }
    return 0;
}
