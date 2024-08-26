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
    vector<int> arr(n);
    for(auto& el: arr) cin >> el;

    // Algoritmo de Kadane
    int ans = -INF;
    int sum_prev = 0;
    for(auto el: arr){
        if(sum_prev >= 0) sum_prev += el;
        else sum_prev = el;

        if(sum_prev > ans) ans = sum_prev;
    }

    cout << ans << endl;
    return 0;
} 
