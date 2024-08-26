#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18


int main(){ _

    int x; cin >> x;

    // Contar quantos bits 1 tem em x
    int cnt = 0;
    while(x){
        cnt++;
        x = x & (x - 1); // Limpa o bit menos significativo 
    }
    
    cout << cnt << endl;


    return 0;
} 
