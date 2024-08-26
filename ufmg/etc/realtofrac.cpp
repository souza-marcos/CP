#include <iostream>

using namespace std;

int mdc(int a, int b){
    if(b > a) swap(a, b);
    if(a % b == 0) return b;
    return mdc(b, a % b);
}

int mmc(int a, int b){
    return (a * b)/mdc(a, b);
}

pair<int, int> realtofrac(double r){
    // to int 
    int mult = 1e6; // TODO: Verify what number is nicer to do this
    int number = r * mult;
    int md = mdc(number, mult);
    return {number/md, mult/md};
}


int main(){
    double in; cin >> in;
    auto el = realtofrac(in);
    cout << el.first << " / " << el.second << endl;
}

