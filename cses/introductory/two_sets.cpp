#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _
    
    // 1 2 3 4 5 6 7
    // 3 4 7
    // 1 2 5 6

    // 1 2 3
    ll n; cin >> n;
    ll sum = (n + 1) * n/2; 
    if(n <= 2 or sum %2 == 1) { cout << "NO\n"; return 0;}

    cout << "YES\n";
    int start = 1;
    vector<int> first, second;
    if(n&1){
        first = {1, 2};
        second = {3};
        start = 4;

    }
    vector<bool> used(n+1, false);
    bool time = 1;
    int j = n;
    for(int i = start; i <= n; i ++, j--){
        if(used[i]) break;
        if(time)
            first.push_back(i), first.push_back(j);
        else second.push_back(i), second.push_back(j);
        used[i]=used[j]=true;
        time = !time;
    }

    cout << sz(first) << endl;
    for(auto el: first) cout << el <<" ";
    cout << endl;


    cout << sz(second) << endl;
    for(auto el: second) cout << el <<" ";
    cout << endl;
    return 0;
} 
