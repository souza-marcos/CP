#include <bits/stdc++.h>
using namespace std;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    if (n%2 == 0)
    {
        int maxo = -INF, maxe = -INF;
        int sum[2][26]; memset(sum, 0, sizeof sum); 
        
        for(int i = 0; i < n; i++){
            sum[i%2][s[i]-'a'] ++; 
        }
        for(int i = 0; i < 26; i ++){
            maxo = max(maxo, sum[1][i]);
            maxe = max(maxe, sum[0][i]);
        }
        cout << n - maxo - maxe << endl;
    }
    else
    {
        int pref[2][26], suff[2][26];
        memset(pref, 0, sizeof pref);
        memset(suff, 0, sizeof suff);

        for (int i=n-1;i>=0;i--){
            suff[i%2][s[i]-'a']++;
        }

        int minv = INF;
        for (int i = 0; i < n; i++){
            suff[i%2][s[i]-'a']--;
            int maxe = 0, maxo = 0; 
            for (int j = 0; j < 26; j++){
                maxe = max(maxe, pref[i%2][j] + suff[(i+1)%2][j]);
                maxo = max(maxo, pref[(i+1)%2][j] + suff[i%2][j]);
            }
            minv = min(n-maxe-maxo, minv);
            pref[i%2][s[i]-'a']++;
        }
        cout << minv << endl;
    }
}

int main()
{
    _ int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
