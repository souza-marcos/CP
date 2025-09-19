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
 
vector<State> autom;
int szo, last;

void sa_init(){
    autom.push_back({});
    autom[0].len = 0;
    autom[0].link = -1;
    szo = 1;
    last = 0;
}

void sa_extend(char ch){

    int cur = szo ++;
    autom.push_back({});
    autom[cur].len = autom[last].len + 1; // The max length endpos class
    int p = last;

    while(p != -1 and autom[p].next.count(ch) == 0){ 
        // The transition not exist, move to up.
        autom[p].next[ch] = cur; // Updating the old suffixes with the new transition.
        p = autom[p].link;
    }

    if(p == -1){ // The character doesn't occured before.
        autom[cur].link = 0;
    }
    else {
        int q = autom[p].next[ch];
        if(autom[p].len + 1 == autom[q].len){ // Only represents one suffix
            // In this case we do not have to clone 
            autom[cur].link = q;
        }
        else{
            // We have to clone
            int clone = szo ++;
            autom.push_back({});
            autom[clone].len = autom[p].len + 1;
            autom[clone].next = autom[q].next;
            autom[clone].link = autom[q].link;

            while(p != -1 and autom[p].next[ch] == q){
                autom[p].next[ch] = clone;
                p = autom[p].link;
            }

            autom[q].link = autom[cur].link = clone;
        }
    }
    last = cur;
}


int32_t main(){  _ 
    string s; cin >> s;

    sa_init();
    for(auto ch : s)
        sa_extend(ch);


    // Count the substrings that init at node i
    vector<int> order(szo);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int l, int r) {
        return autom[l].len > autom[r].len;
    });

    vector<ll> count_ways(szo, 0), times_appear(szo, 0);

    int cur = last;
    while(cur != -1){
        times_appear[cur] = 1;
        cur = autom[cur].link;
    }

    for(int i : order) {
        for(auto [ch, to] : autom[i].next) {
            times_appear[i] += times_appear[to];
            count_ways[i] += count_ways[to];
        }
        count_ways[i] += times_appear[i];
        // cout << i << " " << times_appear[i] << " " << count_ways[i] << endl;
    }

    // ll k; cin >> k;

    auto get_kth = [&](ll k){
        int cur = 0;
        int last = -1;
        string res;
        while(k > 0){
            last = cur;
            for(auto [ch , to] : autom[cur].next){
                if(count_ways[to] < k) k -= count_ways[to];
                else {
                    res.push_back(ch);
                    k -= times_appear[to];
                    cur = to;
                    break;
                }
            }
            // cout << last << " " << cur << endl;
            if(last == cur) return string("No such line.");
        }
        return res;
    };

    ll k; cin >> k;
    cout << get_kth(k) << endl;
    return 0;
} 
