#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> fu(2002);

int grau(int index, int g){
    if(fu[index] == -1) return g;
    return grau(fu[index] - 1, g + 1);
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> fu[i];
    }

    //sort(fu.begin(), fu.begin() + n);

    set<int> g;
    
    for(int i = 0; i< n; i++){
        int gi = (grau(i, 0));
        //cout << gi << " ";
        g.insert(gi);
    }
    cout << g.size() << endl ;

    return 0;
} 
