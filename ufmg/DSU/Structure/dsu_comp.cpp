#include <vector>
using namespace std;

vector<int> id, sz;

int find(int p){
    return id[p] = (id[p] == p? p :find(id[p])); // Path compression
}

void uni(int p, int q){
    p = find(p), q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p, q);
    id[p] = q, sz[q] += sz[p];
}



