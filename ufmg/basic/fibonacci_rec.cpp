#include <iostream>
using namespace std;

// 1 1 2 3 5 8 

int fibonacci(int n){
    int res;
    if(n == 0 || n == 1) res = 1;
    else res = fibonacci(n - 1) + fibonacci(n - 2);
    return res;
}


int main(){

    int n; cin >> n;
    cout << fibonacci(n) << endl;

    return 0;
}