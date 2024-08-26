#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    int t; cin >> t;
    while(t -- ){
        string n; cin >> n;
        if(sz(n) <= 2){
            cout << "NO\n";
            continue;
        }  
        if(n[0] != '1' or n[1] != '0'){ 
            cout << "NO\n";
            continue;
        }

        if(n[2]== '0'){
            cout << "NO\n";
            continue;
        }
        if((n[2] == '1' and sz(n) == 3)){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }

    return 0;
} 
