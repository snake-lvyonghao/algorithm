#include <iostream>
using namespace std;
void move(int n,char x,char y){
    cout << "把" << n << "号从" << x << "挪动到" << y << endl;
}
void Hannoi(int n, char A,char B, char C) {
    //将n个盘子从A柱借助B柱移动到c柱
    if (n == 1)          //递归终止条件
    {
        move(1, A, C);
    } else {
        Hannoi(n - 1 ,A,C,B);       //递归调用
        move(n,A,C);
        Hannoi(n - 1,B,A,C);        //递归调用
    }
}
int main(){
    int n;
    cout << "请输入盘子个数:" << endl;
    cin >> n;
    Hannoi(n,'A','B','C');
    return 0;
}
