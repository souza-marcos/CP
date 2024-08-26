#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

void solve(){
    int n, pulo, nado; cin >> n >> pulo >> nado;
    string s; cin >> s;

    vector<int> mad_ind, croc_ind;
    int i = 0;
    for(char c: s) {
        if(c == 'L') mad_ind.push_back(i);
        if(c == 'C') croc_ind.push_back(i);
        i ++;
    }

    for(auto el: mad_ind) cout << el << " ";
    cout << endl;


    for(auto el: croc_ind) cout << el << " ";
    cout << endl;

    int ptr_mad=0, ptr_croc =0;
    
    bool nocrocs = false, nologs = false;
    for(int i = -1; i < n;){
        
        while(ptr_croc < sz(croc_ind) and i >= croc_ind[ptr_croc]) ptr_croc ++;
        if(ptr_croc == sz(croc_ind)) nocrocs = true;

        while(ptr_mad < sz(mad_ind) and i >= mad_ind[ptr_mad]) ptr_mad ++;
        if(ptr_mad == sz(mad_ind)) nologs = true;

        if(!nologs){
            cout << __LINE__ << " " << mad_ind[ptr_mad] << endl;
            // Have logs
            if(mad_ind[ptr_mad]-i <= pulo) i+= pulo;
            else if(mad_ind[ptr_mad]-i > nado) {cout << __LINE__ << "NO\n"; return;}
            else if(!nocrocs){
                cout << __LINE__ << " " << croc_ind[ptr_croc] << endl;
            
                // Have crocs
                if(croc_ind[ptr_croc] < mad_ind[ptr_mad]){ cout << __LINE__ << "NO\n"; return;}
                else i = mad_ind[ptr_mad];
            }
            else i = mad_ind[ptr_mad];
            
        }else{
            // Have no logs
            if (n-i > nado) {cout << __LINE__ << "NO\n"; return;}
            else if(!nocrocs){
                // Have crocs
                cout << __LINE__ << " " << croc_ind[ptr_croc] << endl;
            
                if(croc_ind[ptr_croc] < n){cout << __LINE__ << "NO\n"; return;}
                else {cout << "YES\n"; return;}
            }
            else{ cout << "YES\n"; return;}
        }
    }
    cout << "YES\n";
}

int main(){ //_
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
