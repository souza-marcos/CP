#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);
#define sz(x) (int)x.size()

const int MAX = 3001;
int memo[MAX][MAX];

int main(){ _
    string s, t; cin >> s >> t;

    for(int i = sz(s)-1; i >= 0; i --){
        for(int j = sz(t)-1; j >= 0; j--){
            if(s[i] == t[j]) memo[i][j] = 1 + memo[i+1][j+1];
            else memo[i][j] = max(memo[i][j+1], memo[i+1][j]);
        }
    }

    string res;
    int i = 0, j = 0;
    while(i < sz(s) and j < sz(t)){
        if(s[i] == t[j]) res.push_back(s[i]), i ++, j ++;
        else if(memo[i+1][j] > memo[i][j+1]) i ++;
        else j ++;
    }
    cout << res << endl;

    return 0;
} 
