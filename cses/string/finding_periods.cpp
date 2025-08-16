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
    int n = sz(s);
    vector<int> pi(n);

    for(int i = 1, j = 0; i < n; i ++){
        while(j > 0 and s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j ++;
        pi[i] = j;
    }

    vector<int> res;
    
    int b = pi[n-1]; 
    while(b > 0) res.push_back(n-b), b=pi[b-1];    
    res.push_back(n);
    for(int el : res) cout << el << " ";
    cout << endl;
    return 0;
} 
