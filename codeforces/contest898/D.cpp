#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18


int main(){ _
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'W') continue;
            count ++; i += (k - 1);
        }
        cout << count << endl;
    }

    return 0;
} 
