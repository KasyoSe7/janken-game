#include <iostream>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()
#include <Windows.h> // sleep()

using namespace std;

int main() {

    // 乱数の初期化
    srand(time(0));
    //勝利数カウント
    int count = 0;
    //負けカウント
    bool lose = false;
    //プレイヤー出目
    int player;
    // じゃんけんの選択肢
    string hands[3] = { "グー", "チョキ", "パー" };
    //プレイヤー入力
    string input;
    //継続判定
    string Continue;
    //引き分け
    bool drow=true;
    //プレイヤーネーム
    string playerName;
    cout << "プレイヤーの名前を入力してください：";
    cin >> playerName;


    while(!lose){
        if (!drow) {
            cout << "じゃんけん！(つづける YES/NO)" << endl;
            cin >> Continue;
            if (Continue == "NO") {
                cout << "ゲームを終了します。" << endl;
                cout << "勝利数:" << count << endl;
                break;
            }
            cout << "Enterキーで次へ進む...";
            cin.ignore();
            cin.get();
            system("cls");  // 画面クリア
        }
       
        drow = false;
        cout << "ジャン..." << endl;
        Sleep(500);
        cout << "ケン..." << endl;
        Sleep(500);
        cout << "ポン！" << endl;
        Sleep(500);

        cout << "じゃんけん！（グー / チョキ / パー）> "<<endl;
        cin >> input;
        
        player = -1;
        if (input == "グー") player = 0;
        else if (input == "チョキ") player = 1;
        else if (input == "パー") player = 2;
        else {
            cout << "無効な入力です。" << endl;
            continue;
        }


        // コンピュータの手（0～2）
        int computer = rand() % 3;

        cout <<playerName<< ": " << hands[player] << endl;
        cout << "コンピュータ: " << hands[computer] << endl;

        // 勝敗判定
        if (player == computer) {
            cout << "あいこ！" << endl;
            drow = true;
        }
        else if ((player == 0 && computer == 1) ||
            (player == 1 && computer == 2) ||
            (player == 2 && computer == 0)) {
            count += 1;
            cout <<playerName<< "の勝ち！ 勝利数:" << count << endl;
        }
        else {
            cout <<playerName<< "の負け！ 勝利数:" << count << endl;
            lose = true;
        }
    }
    return 0;
}
