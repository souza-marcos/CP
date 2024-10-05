#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
int main(){ _
    string s; cin >> s;

    s.push_back('$');
    int n = sz(s);
    vector<int> p(n), c(n);

    {
        vector<pair<char, int>> a(n);
        for(int i = 0; i < n; i ++)
            a[i] = {s[i], i};

        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++) p[i] = a[i].second;

        // Equivalence classes
        c[p[0]]=0;
        for(int i = 1; i < n; i ++){
            if(a[i].first == a[i-1].first) 
                c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]] + 1;
        }

    }

    int k = 0;
    while((1 << k) < n){

        vector<pair<pair<int, int>, int>> a(n);
        for(int i = 0; i < n; i ++){
            a[i]= {
                {c[i], c[(i + (1 << k))%n]},
                i
            };
        }

        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++) p[i] = a[i].second;

        // Equivalence classes
        c[p[0]]=0;
        for(int i = 1; i < n; i ++){
            if(a[i].first == a[i-1].first) 
                c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]] + 1;
        }
        k ++;
    }

    for(int i = 0; i < n; i ++){
        cout << p[i] << " " << s.substr(p[i], n-p[i]) << endl;
    }

    return 0;
} 
