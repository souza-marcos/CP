#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<int> people(n); for(int& el: people) cin >> el, el --;
    vector<int> slides;
    int last = -1;
    for(int i = 0; i < m; i ++){
        int a; cin >> a; a--;
        if(a != last) last = a, slides.push_back(a);
    }

    vector<bool> ativo(n, false);
    int j = 0; // p index
    for(int i = 0; i < sz(slides); i ++){
        if(j >= sz(people)) {
            cout << "YA\n"; return;
        }

        if(people[j] == slides[i]) ativo[people[j]] = true, j ++;
        else if(ativo[slides[i]] == false){
            cout << "TIDAK\n"; return;
        }
    }
    cout << "YA\n";
}
int main(){ //_
    int t; cin >> t;
    while(t --) solve();    

    return 0;
} 
