#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
typedef long long ll;

int main(){
    string s; cin >> s;
    int n = sz(s);
    vector<int> pi(n), cnt(n);
    
    for(int i = 1, j = 0; i < n; i ++){
        while(j > 0 and s[i] != s[j]) j = pi[j-1];
        if(s[i]==s[j]) j ++;
        pi[i]=j;
        cnt[j] ++;
    }

    for(int i = n-1; i > 0; i --){
        cnt[pi[i-1]] += cnt[i];
    }

    vector<pair<int, int>> res;
    
    int j = pi[n-1];
    while(j > 0){
        res.emplace_back(j, cnt[j]+1);
        j = pi[j-1];
    }

    cout << sz(res) + 1 << endl;
    for(int i = sz(res)-1; i >= 0; i--){
        cout << res[i].first << " " << res[i].second << endl;
    }
    cout << n << " " << 1 << endl;
}