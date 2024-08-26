#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int cost(vector<int> vals, int m){
    int cost = 0;
    for(auto el: vals){
        if(el > m + 1) cost += abs(el - (m + 1));
        else if(el < m - 1) cost += abs((m - 1) - el);
    }
    return cost;
}

int main(){_
    int n; cin >> n;
    vector<int> vals(n);
    int sum = 0;


    int max_val = -INF, min_val = INF;
    for(auto& el: vals){
        cin >> el; max_val = max(max_val, el); min_val = min(min_val, el);
    }

    pair<int, int> res = {0, INF};//m, cost
    for(int i = min_val; i <= max_val; i++){
        int cur = cost(vals, i);
        if(cur < res.second) res = {i, cur};
    }

    cout << res.first << " " << res.second << endl; 
    return 0;
}