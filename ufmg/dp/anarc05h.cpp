#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

string s;
ll memo[26][226];

int solve(int i, int prevsum){
    if(i == s.size()) return 1;

    auto& p = memo[i][prevsum];

    if(p != -1) return p;
    ll ans = 0;
    int val = 0;
    for(int j = i; j < s.size(); j++){
        val += s[i] - '0';
        if(prevsum <= val) ans += solve(j + 1, val);
    }
    return p = ans;

}

int main(){ _


// 635 -> [635], [6-35] -> 2
// 1117 -> [1117],[1-117],[1-1-17],[1-11-7],[1-1-1-7],[11-17],[111-7]

    int cnt = 1;
    while(cin >> s){
        if(s == "bye") return 0;
        memset(memo, -1, sizeof memo);
        cout << cnt ++ << ". " << solve(0, 0) << endl;
        s.clear();
    }


    return 0;
} 
