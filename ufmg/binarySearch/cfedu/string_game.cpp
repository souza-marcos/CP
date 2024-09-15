// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/F
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);
#define sz(x) (int)x.size()

int main(){ _
    string p, t; cin >> p >> t;
    vector<int> perm(sz(p));
    for(int& el: perm) cin >> el, el--;

    auto canierase = [&](int guess){
        vector<bool> er(sz(p));
        for(int i= 0; i < guess; i ++) er[perm[i]] = true;

        int i = 0, j = 0;
        while(i < sz(p) and j < sz(t)){
            if(er[i]) {
                i ++; continue;
            }

            if(p[i] == t[j]) i ++, j ++;
            else i ++;
        }
        return j == sz(t);
    };

    int l = 0, r = sz(p);
    while(l + 1 < r){
        int m = (l + r)/2;
        if(canierase(m)) l = m;
        else r = m;
    }
    cout << l << endl;
    return 0;
} 
