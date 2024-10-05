// https://cses.fi/problemset/task/1732
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

    vector<int> pi(sz(s));
    for(int i = 1, j = 0; i < sz(s); i ++){
        while(j > 0 and s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j ++;
        pi[i] = j;
    }

    int j = sz(s) - 1;
    stack<int> res;
    while(pi[j] > 0){
        res.push(pi[j]);
        j = pi[j]-1;
    }

    while(!res.empty()){
        cout << res.top() << " ";
        res.pop();
    }
    cout << endl;
    return 0;
} 
