#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    string s; cin >> s;

    int cnt = 0; 
    char cur = s[0];
    vector<int> cont;

    for(char el: s){
        if(el == cur) cnt ++;
        else cont.push_back(cnt), cnt = 1, cur = el;
    }
    cont.push_back(cnt);
    
    int maxval = 0;
    for(int i = 0; i < sz(cont)-1; i ++)
        maxval = max(maxval, min(cont[i], cont[i + 1]));
    
    for(int i = 1; i < sz(cont) -1; i ++){
        int val = cont[i-1] + cont[i + 1];
        if(val >= cont[i]) maxval = max(maxval, cont[i]);
    }

    cout << maxval * 2 << endl;

    return 0;
}
