#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    string s[n], t;
    for(int i = 0; i < n; i ++) cin >> s[i];
   
    int k, l;
    for(int i = 0; i < n; i ++) {
        cin >> t;
        for(int j = 0; j < n; j++){
            if(t[j] != s[i][j]) k = i, l = j;
        }
    }

    cout << k + 1 << " " << l + 1 << endl;  
    return 0;
} 
