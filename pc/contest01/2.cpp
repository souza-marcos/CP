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
 
    for(auto& el: vals){
        cin >> el;
        sum += el;
    }
    int mean = sum/n; 
    int x = cost(vals, mean);
    int y = cost(vals, mean - 1); 
    int z = cost(vals, mean + 1);

    // cout << x << " " << y << " " << z << endl;
    int res = min(z, min(x, y));
    if(res == x) cout << mean << " ";
    else if (res == y) cout << mean - 1 << " ";
    else cout << mean + 1 << " ";

    cout << res << endl; 
    return 0;
}