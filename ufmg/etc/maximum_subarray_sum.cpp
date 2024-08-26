#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

int main(){ _

    int n, a, b; cin >> n >> a >> b;
    vector<int> v(n); for(int& el : v) cin >> el;


    int i = 0, j = 0;
    ll cur_sum = 0, max_sum = 0;
    while(i < n and j < n){
        while(j-i > b) cur_sum -= v[i++];
        while(j-i < a) cur_sum += v[j], j++;
        while(j-i < b and v[j] >= 0) cur_sum+= v[j ++];

        while(j-i > a and v[i] <= 0) cur_sum -= v[i ++];
        cout << cur_sum << endl;
        max_sum = max(max_sum, cur_sum);
        j++;
    }
    while(i < n) cur_sum -= v[i ++], max_sum=max(cur_sum, max_sum), cout << cur_sum << endl;
    cout << max_sum << endl;

    return 0;
} 
