#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'


struct Vertex {
    int left, right;
    int sum = 0;

    Vertex *left_child = nullptr, *right_child = nullptr;

    Vertex (int lb, int rb){
        left = lb, right = rb;
    }

    // divide coordinate
    void extend(){
        if(!left_child and left + 1 < right){
            int t = (left + right)/2;
            left_child = new Vertex(left, t);
            right_child = new Vertex(t, right);
        }
    }

    // point update
    void add(int k, int x){
        extend();
        sum += x;
        if(left_child){
            if(k < left_child->right)
                left_child->add(k, x);
            else right_child->add(k, x);
        }
    }

    // queries [lq, rq)
    int get_sum(int lq, int rq){
        if(lq <= left and right <= rq){
            return sum;
        }
        if(max(left, lq) >= min(right, rq)) return 0;
        extend();
        return left_child->get_sum(lq, rq) + right_child->get_sum(lq, rq);
    }
};


int main(){ _



    Vertex root(0, 1e9);
    root.add(10, 3);
    root.add(90, 2);
    root.add(100, 1);
    root.add(1e6, 100);

    cout << root.get_sum(0, 1e9) << endl;
    cout << root.get_sum(10, 1e6 + 1) << endl;
    cout << root.get_sum(90, 90) << endl;
    cout << root.get_sum(90, 100) << endl;

    return 0;
} 
