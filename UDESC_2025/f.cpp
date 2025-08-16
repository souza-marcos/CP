#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define int ll
#define ss second 
#define ff first 
#define sz(x) (int)x.size()

int32_t main() { _
	int n,f,s;
    cin >> n >> f >> s;
    vector<int> p(n),q(n);
    for(int i=0;i<n;i++) {
        cin >> p[i];
        p[i]--;
    }
    for(int i=0;i<n;i++) {
        cin >> q[i];
        q[i]--;
    }

    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) a[p[i]] = i;
    for(int i=0;i<n;i++) b[q[i]] = i;

    int ans = LLONG_MAX;

    vector<bool> ss(n,false);
    
    for(int i=0;i<n;i++) {
        if(ss[p[i]]) continue;

        int iq = b[p[i]];
        int x = i,y=iq;
        while(x<n and y<n and p[x]==q[y]) {
            ss[p[x]] = true;
            x++;
            y++;
        }

        ans = min(ans,max(f*(i+iq),s*(n-x+n-y)));
    }

    cout << ans << '\n';
}