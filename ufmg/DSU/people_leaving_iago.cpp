#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> id;

int find(int x){
    return id[x] = (id[x] == x ? x : find(id[x]));
}

void unio(int a, int b){
    a = find(a), b = find(b);
    id[a] = b; 
}

int main(){ _
    int n;
    int m; cin >> n >> m;
    id.resize(n+1);
    iota(all(id), 0);

    for(int i = 0; i < m; i++){
        char c; int a; cin >> c >> a; a--;
        if(c == '-') unio(a, a+1);
        else (find(a) < n) ? cout << find(a)+1 << endl : cout << -1 << endl;
    }

    exit(0);
}