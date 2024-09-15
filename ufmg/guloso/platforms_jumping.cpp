// https://codeforces.com/contest/1256/problem/C
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    int n, m, d; cin >> n >> m >> d;
    
    vector<int> blanks(m); for(int& el: blanks) cin >> el;
    vector<int> res(n);

    int sum = accumulate(blanks.begin(), blanks.end(), 0), 
        pulo_cur = d;
    bool ok = true, blocked = false;
    for(int i = n-1; i >= 0; i--){
        ok = (i >= sum);
        
        if(pulo_cur > 1 and ok and not blocked) { pulo_cur--; continue;}
        if(pulo_cur == 1) pulo_cur = d;

        if(m > 0 and !blanks[m-1]) m--;
        res[i] = m;
        sum --;
        if(m > 0) blanks[m-1]--;
        blocked = (m > 0 and blanks[m-1]);
    }
    int dist = 1;
    for(int i = 0; i < n; i ++){
        if(res[i]==0) dist ++;
        else dist = 1;

        if(dist > d) return cout << "NO\n", 0;         
    }


    cout << "YES\n";
    for(auto el: res) cout << el << " ";
    cout << endl;
    return 0;
} 
