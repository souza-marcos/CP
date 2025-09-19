#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
// #define sz(x) (int)x.size()
#define endl '\n'

struct State {
    int len, link;
    vector<int> next = vector<int>(26, -1);
};

vector<State> st;
int sz, last;

void sa_init(int n){
    // Empty string
    st.push_back({});
    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
    last = 0;
}

void sa_extend(int c){
    int cur = sz++;
    st.push_back({});
    st[cur].len = st[last].len + 1;
    int p = last;

    while(p != -1 and st[p].next[c] == -1){
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
            st.push_back({});
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
    
    string s; cin >> s;
    string t = s + s;    
    sa_init(t.size());
    for(char ch : t) {
        int val = ch - 'a';
        if(val >= 26 or val < 0) cout << "ERROR", exit(0);
        sa_extend(val);
    }
    t = "";
    int cur = 0;
    for(int i = 0; i < (int)s.size(); i ++){
        auto &it = st[cur].next;
        for(int i = 0; i < 26; i ++){
            if(it[i] != -1) {
                t.push_back((char)('a' + i)), cur = it[i];
                break;
            }
        } 
    }

    cout << t << endl;

    return 0;
} 
