#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    for(auto& el: arr){
        cin >> el.first >> el.second;
    }

    sort(arr.begin(), arr.end(), 
    [](pair<int,int>& a, pair<int,int>& b){
        if(a.second == b.second) return a.first < b.first; // It's not necessary for this problem.
        return a.second < b.second;
    });

    int r_last = -1;
    int count = 0;
    for(auto el: arr){
        if(el.first > r_last){
            count ++;
            r_last = el.second;
        }
    }
    cout << count << endl;

    return 0;
} 
