#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){_ 
    int n; cin >> n;
    string a, b; cin >> a >> b;

    vector<pair<int,int>> arr_a(2*n), arr_b(2*n);
    for(int i = 0; i < 2*n; i ++){
        arr_a[i] = {(a[i]-'0')*10 + (b[i]-'0'), i};
        arr_b[i] = {(b[i]-'0')*10 + (a[i]-'0'), i};
    }
    sort(arr_a.rbegin(), arr_a.rend());
    sort(arr_b.rbegin(), arr_b.rend());
    
    vector<bool> used(2*n, false); 

    int k = 0, j = 0;
    int sa = 0, sb = 0;
    for(int i = 0; i < n; i ++){
        while(k < 2 * n and used[arr_a[k].second]) k ++;
        int idx = arr_a[k].second;
        sa += a[idx]-'0';

        used[arr_a[k].second] = true;
        while(j < 2 * n and used[arr_b[j].second]) j ++;
        idx = arr_b[j].second;
        sb += b[idx]-'0';

        used[arr_b[j].second] = true;
    }
    // cout << k << " " << j << endl;
    // cout << sa << " " << sb << endl;
 
    if(sa > sb) cout << "First\n";
    else if(sa < sb) cout << "Second\n";
    else cout << "Draw\n";
}