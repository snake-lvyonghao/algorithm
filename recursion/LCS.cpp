#include <iostream>
#include <string>

using namespace std;
#define N 100
char X[N],Y[N],str[N];
int c[N][N],num = 0;
int lcs_len(char* X,char* Y,int c[][N]){
    int m = strlen(X),n = strlen(Y);
    for (int i = 0; i <= m; ++i) {      //初始化字符串X每一个字符对Y最大公共子串长度都是0
        c[i][0] = 0;
    }
    for (int j = 0; j <= n; ++j) {      //初始化字符串Y每一个字符对X最大公共子串长度都是0
        c[0][j] = 0;
    }
    for (int i = 1; i <= m; ++i) {      //i代表行也是每一个X的字符
        for (int j = 1; j <= n; ++j) {  //j代表列也是每一个Y的字符
            if (X[i - 1] == Y[j - 1])   //字符相同，在原来的比较基础上+1
                c[i][j] = c[i - 1][j - 1] + 1;
            else if(c[i - 1][j] >= c[i][j - 1])           //不同，则选择X对Y和Y对X的最大公共子串
                c[i][j] = c[i - 1][j];
            else
                c[i][j] = c[i][j - 1];
        }
    }
    return c[m][n];                     //返回最终比较结果
}

char* build_lcs(char s[],char* X,char* Y){
    int i = strlen(X),j = strlen(Y);
    int k = lcs_len(X,Y,c);             //k及最大公共子串长度
    s[k] = '\0';
    while(k > 0){
        if(c[i][j] == c[i - 1][j]){
            i--;
        }
        else if(c[i][j] == c[i][j - 1]){
            j--;
        }
        else{
            s[--k] = X[i - 1];
            i--;j--;num++;
        }
    }
    return s;
}

int main(){
    cout << "输入一个长度小于" << N << "的字符串" << endl;
    cin >> X;
    cout << "再输入一个长度小于" << N << "的字符串" << endl;
    cin >> Y;
    cout << "Lsc=" << build_lcs(str,X,Y) << endl;
    cout << "最大子序列长度为"  << num << endl;
    return 0;
}