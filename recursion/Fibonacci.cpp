#include <iostream>
using namespace std;
int fib(int n){
    int f = 0;
    if(n == 1) return 0;
    if(n == 2) return 1;
    f = fib(n - 1) + fib(n - 2);
    return f;
}
int main(){
    int n,m = 0;
    cin >> n;
    m = fib(n);
    cout << "第" << n << "项是" << m <<endl;
    m = 0;
    for(int i = 1;i <= n; i++){
        m = fib(i) + m;
        cout << "前" << i << "项和是" << m << endl;
    }
    return 0;
}
