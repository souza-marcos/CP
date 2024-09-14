#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18


int main(){ _
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 0; i + 2 < n; i++){
        if(s[i] == 'A' and s[i+1] == 'B' and s[i+2] == 'C'){
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
} 
