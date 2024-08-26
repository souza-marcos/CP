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

    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for(auto& el: arr) cin >> el;


    int sum = 0;
    for(int i = 0; i < n; i++){
        int diff = m - arr[i];
        arr[i] += diff;
        if(i + 1 < n) arr[i + 1] += diff;
        sum += abs(diff);
    }

    cout << sum << endl;

    return 0;
} 
