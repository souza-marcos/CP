#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class DSU{
public:
    int *arr;
    int *rank;

    DSU(int max_size){
        arr = new int[max_size];
        rank = new int[max_size];
    }

    ~DSU(){
        delete[] arr;
    }

    void make_set(int n){
        arr[n] = n;
        rank[n] = 0;
    }

    int find_set(int x){
        if(arr[x] == x) return x;
        // Optimization: Path Compression
        return arr[x] = find_set(arr[x]); 
    }   

    void union_set(int x,int y){
        x = find_set(x);
        y = find_set(y);
        if(x != y) {
            if(rank[x] < rank[y]) {
                int aux = x;
                x = y;
                y = aux;
            }
            arr[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
};

int main(){ _
    int n; cin >> n;
    DSU dsu(n);
    for(int i = 0; i < n; i++) dsu.make_set(i);

    vector<pair<int, int>> edges;
    set<int> parents_set;
    int i = n;
    while(i --> 1){
        int v, u;
        cin >> v >> u;
        if(dsu.find_set(v) != dsu.find_set(u)) dsu.union_set(v, u);
        else {
            edges.push_back({v, u});
        }
    }
    for(int i = 0; i < n; i++) parents_set.insert(dsu.find_set(i));
    cout << edges.size() << endl;
    for(auto e : edges){
        cout << e.first << " " << e.second << " " << *parents_set.begin() << " " << *(++parents_set.begin()) << endl;
        
    }

    return 0;
} 
