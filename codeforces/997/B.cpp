#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    string line;
    vector<pair<int, int>> relative; // qtd, index

    for(int i = 0; i < n; i ++){
        cin >> line;
        int cnt = 0;
        for(int j = 0; j < i; j ++)
            if(line[j]=='1') cnt ++;
        for(int j = i + 1; j < n; j ++)
            if(line[j]=='0') cnt ++;

        relative.push_back({cnt, i});
    }

    sort(relative.begin(), relative.end());
    for(auto [bef, i] : relative) cout << i + 1 << " ";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
} 
