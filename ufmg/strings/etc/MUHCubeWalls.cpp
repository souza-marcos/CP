// https://codeforces.com/problemset/problem/471/D
#include <iostream>
#include <vector>
using namespace std;
#define sz(x) (int)x.size()

int n, m;
vector<int> v, pat;


int main(){
    cin >> n >> m;
    v.resize(n-1), pat.resize(m-1);
    
    if(m == 1) {
        for(int i = 0; i<n; i ++){
            int a; cin >> a;
        }
        int a; cin >> a;
        cout << n << endl;
        return 0;
    }
    if(m > n){
        for(int i = 0; i <n; i ++){
            int a; cin >> a;
        }
        for(int i = 0; i < m; i ++){
            int a; cin >> a;
        }
        cout << 0 << endl;
        return 0;
    }
    
    int last, cur; cin >> last;
    for(int i = 1 ; i < n; i ++){
        cin >> cur;
        v[i-1] = cur - last;
        last = cur;
    }
    cin >> last;
    for(int i = 1; i < m; i ++){
        cin >> cur;
        pat[i-1] = cur - last;
        last = cur;
    }

    const int INF = 1e9 + 100;
    pat.push_back(-INF);
    pat.insert(pat.end(), v.begin(), v.end());

    vector<int> pi(sz(pat));
    pi[0] = 0;
    int cnt = 0;
    for(int i = 1, j=0; i < sz(pat); i ++){
        while(j > 0 and pat[i] != pat[j]) j = pi[j-1];
        if(pat[i] == pat[j]) j++;
        pi[i] = j;
        if(j == m-1) cnt ++;
    }
    cout << cnt << endl;
}