#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

int main(){ _

    int n; cin >> n;
    vector<int> v(n); for(int& el: v) cin >> el;

    deque<pair<int, int>> q;
    int k; cin >> k;
    
    for(int i = 0; i < k; i ++){
        while(!q.empty() and q.back().first <= v[i])
            q.pop_back();
        q.push_back({v[i], i});
    }
    vector<int> ans;
    ans.push_back(q.front().first);
    for(int i = k; i < n; i++){
        if(q.front().second <= i-k) q.pop_front();
        while(!q.empty() and q.back().first <= v[i])
            q.pop_back();

        q.push_back({v[i], i});
        ans.push_back(q.front().first);
    }


    for(auto el: ans) cout << el << " ";
    cout << endl;

    return 0;
} 
