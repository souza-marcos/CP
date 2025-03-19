#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    string s; cin >> s;
    int sum = 0, cnt2 = 0, cnt3 = 0;
    for(auto ch : s) {
        int d = ch - '0';
        sum += d, sum %= 9;
        if(d == 2) cnt2 ++;
        if(d == 3) cnt3 ++;
    }

    if(sum == 0){
        cout << "YES\n";
        return;
    }
    // 3 -> +6, 2 -> +2
    for(int i = 0; i <= cnt3; i ++){
        int val = (sum + i * 6) % 9; 
        val = (18 - val) % 9;
        int needed = INF;
        if(val&1) needed = (val + 1)/2 + 4;
        else needed = val/2;

        if(cnt2 >= needed) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
