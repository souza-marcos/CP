#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    
    int n, m; cin >> n >> m;
    vector<int> probs(m);
    for(auto& el: probs) cin >> el;
    vector<pair<int, vector<int>>> players(n); // i have / remain
    int maxv = 0;
    int i = 1;
    for(auto& [sum, remain] : players){
        string s; cin >> s;
        sum = i ++;
        for(int i = 0; i < m; i ++){
            if(s[i]=='o') sum += probs[i];
            else remain.push_back(probs[i]);
        }
        if(sum > maxv) maxv = sum;
        sort(remain.rbegin(), remain.rend());
    }

    // cout << maxv << endl;
    i = 0;
    vector<int> res;
    for(auto& [sum, remain] : players){
        // cout << i ++ << " " << sum << " ";

        if(sum == maxv){
            res.push_back(0);
        } else {
            int cnt = 0;
            for(int el : remain){
                sum += el, cnt ++;
                if(sum > maxv) break;
            }
            res.push_back(cnt);
        }
        // cout << sum << endl;
    }
    for(auto el : res) cout << el << endl;
} 
