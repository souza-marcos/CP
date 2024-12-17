#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<int>> cnt(2, vector<int>(n));
    vector<int> hs1, hs2;
    for(int i = 0; i < n; i ++){
        int a; cin >> a; a --;
        cnt[0][a] ++;
        if(cnt[0][a] == 2) hs1.push_back(a);
    }
    for(int i = 0; i < n; i ++){
        int a; cin >> a; a --;
        cnt[1][a] ++;
        if(cnt[1][a] == 2) hs2.push_back(a);
    }
    vector<int> res1, res2;
    k *= 2;
    set<int> used;
    while(k > 1 and sz(hs1) and sz(hs2)){
        res1.push_back(hs1.back()), res2.push_back(hs2.back());
        res1.push_back(hs1.back()), res2.push_back(hs2.back());
        
        used.insert(hs1.back()), used.insert(hs2.back());
        hs1.pop_back(), hs2.pop_back();
        k -= 2;
    }

    for(int i = 0; i < n; i ++)
    {
        if(k <= 0) break;
        if(cnt[0][i] == 1 and used.count(i)== 0){
            res1.push_back(i), res2.push_back(i);
            k --;
        }
    }

    for(auto el: res1) cout << el + 1 << " ";
    cout << endl;
    for(auto el: res2) cout << el + 1 << " ";
    cout << endl;
}   

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
