#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int n1, n2;

// * * * * * * *
// * * * 

void solve(){
    vector<int> v1(n1);
    for(auto& el : v1) cin >> el;
    cin >> n2;
    vector<int> res(n2);
    for(auto& el: res) cin >> el;

    bool isPos = false;

    queue<vector<int>> q; q.push(v1);
    set<vector<int>> s;

    while(!q.empty()){
        vector<int> cur = q.front(); q.pop();

        if(cur.size() == res.size()){
            bool equal = true;
            for(int i = 0; i < cur.size(); i ++) if(cur[i] != res[i]) { equal = false; break; }
            if(equal) {cout << "S" << endl; return; }
            equal = true;

            for(int i = 0; i < cur.size(); i ++) if(cur[i] != res[res.size() - i - 1]) { equal = false; break; }
            if(equal) {cout << "S" << endl; return; }
            continue;
        }
        if(cur.size() < res.size()) continue;

        for(int i=0; i < cur.size()/2+1; i++){
            vector<int> newv;
            int j;
            for(j = cur.size()-1; j >= i; j--) newv.push_back(cur[j]);
            
            for(int k=newv.size()-1, j=i-1; j>=0; k--, j--) newv[k] += cur[j];
            
            if(!s.count(newv)) q.push(newv), s.insert(newv);
        }
    }
    cout << "N" << endl;
}

int main(){_
    while(cin >> n1) solve();
    return 0;
}