#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

const int MAX = 1e5 + 10;
vector<int> maxdiv(MAX);
void crivo(){
    iota(maxdiv.begin(), maxdiv.end(), 0);
    maxdiv[0] = 1;
    for(int i = 2; i < MAX; i++){
        if(maxdiv[i] == i){
            for(int j = 2 * i; j < MAX; j += i){
                maxdiv[j] = i;
            }
        }
    }
}

int dp_i[MAX];
int main(){ _
    int n; cin >> n;
    vector<int> v(n); for(int& el: v) cin >> el;

    crivo();
    int max_tot = 0;
    for(auto el: v){
        int max_el = 0;
        vector<int> divs;
        while(el != 1){
            max_el = max(max_el, dp_i[maxdiv[el]]);
            divs.push_back(maxdiv[el]);
            el /= maxdiv[el];
        }
        max_tot = max(max_tot, max_el + 1);

        for(int i: divs) dp_i[i] = max_el + 1;
    }

    cout << max_tot << endl;

    return 0;
} 
