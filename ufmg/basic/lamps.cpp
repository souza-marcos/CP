#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;

    int lamp1 = 0, lamp2 = 0;

    for(int i = 0; i < n; i++){
        int val; cin >> val;
        if(val == 1){
            if(lamp1 == 0) lamp1 = 1;
            else lamp1 = 0;
        }
        else{
            if(lamp1 == 0) lamp1 = 1;
            else lamp1 = 0;

            if(lamp2 == 0) lamp2 = 1;
            else lamp2 = 0;
        }
    }
    cout << lamp1 << endl << lamp2 << endl;

    return 0;
}