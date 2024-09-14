#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18

string s, t;
int n, m; 

bool isSuffix(){
    int it_s = n - 1, it_t = m - 1;
    while(it_s >= 0 and it_t >= 0){
        if(s[it_s] != t[it_t]) return false;
        it_s--; it_t--;
    }
    return true;
}

bool isPrefix(){
    int it_s = 0, it_t = 0;
    while(it_s < n and it_t < m){
        if(s[it_s] != t[it_t]) return false;
        it_s ++ , it_t ++ ;
    }
    return true;
}


int main(){ _
    cin >> n >> m;
    cin >> s >> t;
    bool is_suffix = isSuffix();
    bool is_prefix = isPrefix();
    if(is_suffix and is_prefix) cout << 0 << endl;
    else if(is_suffix) cout << 2 << endl;
    else if(is_prefix) cout << 1 << endl;
    else cout << 3 << endl;

    return 0;
} 
