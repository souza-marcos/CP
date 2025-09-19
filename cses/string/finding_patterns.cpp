#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

struct State {
    int len, link;
    map<char, int> next;
};

const int MAXLEN = 1e5+10;
State st[MAXLEN * 2];
int sz, last;

void sa_init(){
    // Empty string
    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
    last = 0;
}

void sa_extend(char c){
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;

    while(p != -1 and st[p].next.count(c) == 0){
        st[p].next[c] = cur;
        p = st[p].link;
    }

    if(p == -1){
        st[cur].link = 0;
    }
    else {
        int q = st[p].next[c];
        if(st[p].len + 1 == st[q].len){
            // Continuous transtion
            st[cur].link = q;
        }
        else{
            // We have to clone
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;

            while(p != -1 and st[p].next[c] == q){
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int32_t main(){ _ 
    // intuitively the suffix automaton store all the substrings in O(n) memory size.

    string s; cin >> s;
    sa_init();
    for(char ch : s) sa_extend(ch);

    int q; cin >> q;
    while(q --){
        string t; cin >> t;
        int cur = 0;
        bool ok = true;
        for(char ch : t){
            if(st[cur].next.count(ch) == 0){
                ok = false;
                break;
            }
            cur = st[cur].next[ch];
        }
        cout << (ok? "YES\n": "NO\n");
    }
    return 0;
} 
