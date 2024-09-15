#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18


int main(){ _
    int n; cin >> n;
    while(n--){
        string test; cin >> test;
        
        if(test[0] == 'b' && test[1] == 'c' ){cout << "NO\n";}
        else if(test[0] == 'c' && test[1] == 'a' ){cout << "NO\n";}
        else cout << "YES\n";
    }

    return 0;
} 
