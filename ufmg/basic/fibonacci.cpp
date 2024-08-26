#include <iostream>
using namespace std;

int main(){

    int n; cin >> n;

    if(n == 0 or n == 1){
        cout << 1 << endl;
        return 0;
    }

    int a = 1, b = 1; // a b 
    for(int i = 2; i < n; i++){ // Atualizar a e b
        int aux = a; 
        a = b;
        b = aux + b;
    }

    int res = a + b;
    cout << res << endl;

    return 0;
}