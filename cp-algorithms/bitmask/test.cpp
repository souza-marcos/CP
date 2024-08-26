#include <iostream>
#include <cassert> 

using namespace std;

int main(){

    unsigned int x = 13;
    assert(x == 0b1101);

    int positive_signed_number = 13;
    assert(positive_signed_number == 0b1101);

    int negative_signed_number = -13;
    assert(negative_signed_number == 0b1111'1111'1111'1111'1111'1111'1111'0011);

    return 0;
}