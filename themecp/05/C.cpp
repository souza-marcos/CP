#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int query(string s){
    cout << "? " << s << endl;
    cout.flush();
    int res; cin >> res;
    if(res == -1) exit(2266);
    return res;
}

void ans(string s) {
    cout << "! " << s << endl;
    cout.flush();
}

void solve(){
    int n; cin >> n;
    string cur = "";
    bool endright = false;
    int cnt = 0;

    map<string, bool> dict;

    while(sz(cur) < n){
        if(!endright){
            int res = 2;

            if(dict.count(cur + '0')) res = dict[cur + '0']; 
            else res = query(cur + '0'), cnt ++, dict[cur + '0'] = res;

            if(res == 1) { cur = cur + '0'; continue; } 
            
            if(dict.count(cur + '1')) res = dict[cur + '1']; 
            else res = query(cur + '1'), cnt ++, dict[cur + '1'] = res;

            if(res == 1) { cur = cur + '1'; continue; }

            endright = true;
        }
        else {
            int res = 2;

            if(dict.count('0' + cur)) res = dict['0' + cur]; 
            else res = query('0' + cur), cnt ++ , dict['0' + cur] = res;

            if(res == 1) { cur = '0' + cur; continue; } 
            dict['1' + cur] = 1;
            cur = '1' + cur;    
        }
    }
    ans(cur);
    // cout << "CNT: " << cnt << endl;;
}   

int main(){ 
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
