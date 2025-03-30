#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){
    int n; cin >> n;
    list<int> s;
    vector<int> res;
    string t; cin >> t;
    
    map<char, int> mp;
    mp['T'] = 0;
    mp['I'] = 1;
    mp['L'] = 2;

    int cnt[3] = {0, 0, 0};
    for(int i = 0; i < n; i ++)
        s.push_back(mp[t[i]]), cnt[mp[t[i]]] ++;


    // for(auto el : s) cout << el << " ";
    // cout << endl;

    vector<int> vec(cnt, cnt + 3);

    sort(vec.begin(), vec.end());
    int needed = 2 * vec[2] - vec[1] - vec[0];
    // cout << needed << endl;
    if(needed > 2 * n) {
        cout << -1 << endl;
        return;
    } 

    if(n == 1) {
        cout << -1 << endl;
        return;
    }

    
    int ops = 0, i = 1;
    auto cur = s.begin();
    int maxv= vec[2];
    auto next = [&](_List_iterator<int> cur) -> _List_iterator<int>{
        auto n = ++cur;
        cur --;
        return n;
    };

    auto getelse = [&](int prev, int next) -> int {
        return 1 ^ 2 ^ prev ^ next;
    };  

    while(!(cnt[0] == cnt[1] and cnt[0] == cnt[2]) and ops < 2 * n){
        int last = sz(s);
        while(cur != s.end() and ops < 2 * n){
            // cout << *cur << " " << *next(cur)  << " cnt " << cnt [0] << cnt [1] << cnt [2] << " " << getelse(*cur, *next(cur)) << endl; 

            if(cnt[0] == cnt[1] and cnt[0] == cnt[2]) break;

            if(*next(cur) != *cur and cnt[getelse(*cur, *next(cur))] < maxv)
            {
                cnt[getelse(*cur, *next(cur))] ++;
                s.insert(next(cur), getelse(*cur, *next(cur)));
                ops ++;
                res.push_back(i);
            }
            ++cur;
            i ++;

            // cout << i  << " " << sz(s) << endl;
        }
        cur = s.begin();
        i = 1;
        if(last == sz(s)){
            // cout << "Dont change\n";
            break;
        }   

    }
    
    if(cnt[0] == cnt[1] and cnt[1] == cnt[2] and ops <= 2*n){
        cout << sz(res) << endl;
        for(auto el : res) cout << el << endl;
        return;
    }

    cout << -1 << endl;

}

int main(){ //_
    int t; cin >> t;
    while(t--) solve();
} 
