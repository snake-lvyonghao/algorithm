#include <iostream>
using namespace std;
const int Normallize = 9;       //定义常量，用来同一数组下标
int Num = 0;                    //整形变量，记录方案数
int Queen[9];                   //记录8个皇后所占用的列号

bool C[9];                      //判断当前列是否可行
bool L[17];                     //判断当前左对角线是否可行
bool R[17];                     //判断当前右对角线是否可行

void check(int i){
    int j;                      //循环变量
    for(j = 1; j <= 8; j++){
        if((C[j] == true) && (R[i + j] == true) && (L[i - j + Normallize] == true)){
            //表示第i行第j列可行
            Queen[i] = j;       //占用位置（i，j）
            C[j] = false;       //修改可行标志，所在列以及两个对角线
            L[i -j + Normallize] = false;
            R[i + j] = false;
            if(i < 8){
                check(i + 1);   //递归放置下一个皇后
            } else{
                Num++;          //递归结束，方案数+1
                cout << "方案" << Num << ";" << "\t";
                for(int k = 1; k <= 8; k++){
                    cout << k << "行" << Queen[k] << "列" << "\t";
                }
                cout << endl;
            }

            //修改可行标志，回溯
            C[j] = true;
            L[i - j + Normallize] = true;
            R[i + j] = true;
        }
    }
}

int main(){
    Num = 0;
    //初始化所有bool判断标志
    for (int i = 1; i < 9; ++i) {
        C[i] = true;
    }
    for (int j = 0; j < 17; ++j) {
        L[j] = R[j] = true;
    }
    check(1);               //从第一行放置棋子
    return 0;
}
