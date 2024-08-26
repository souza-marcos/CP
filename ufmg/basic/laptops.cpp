#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

int main(){ _

    int n; cin >> n;
    vector<pair<int, int>> laps(n);
    for(auto& [price, quali]: laps){
        cin >> price >> quali;
    }
    sort(laps.begin(), laps.end(), [](pair<int, int> &left, pair<int, int> &right){
        return left.f < right.f;
    });
    
    for(int i = 0; i + 1 < n; i ++){
        if(laps[i].s > laps[i + 1].s) { cout << "Happy Alex\n"; return 0; }
    }
    cout << "Poor Alex\n";

    return 0;
} 
