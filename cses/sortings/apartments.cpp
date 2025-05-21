#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _

    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m); 
    for(int& el: a) cin >> el;
    for(int& el: b) cin >> el;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    int cnt = 0;
    while(i < n and j < m){
        if(b[j] > a[i] + k) i++;
        else if(b[j] < a[i] - k) j++; 
        else cnt ++, i ++, j++;
    }
    cout << cnt << endl;
    return 0;
} 
