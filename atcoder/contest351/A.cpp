#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    int sum1 = 0;
    for(int i = 0; i < 9; i++){
        int a; cin >> a;
        sum1 += a;
    }
    int sum2 = 0;
    for(int i = 0; i < 8; i++){
        int a; cin >> a;
        sum2 += a;
    }
    
    cout << sum1 - sum2 + 1 << endl;

    return 0;
} 
