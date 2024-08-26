#include <iostream>
#include <bit>

using namespace std;

void set_bit(int &x, int pos){
    x = x | (1 << pos);
}

void flip_bit(int &x, int pos){
    x = x ^ (1 << pos);
}

void clear_bit(int &x, int pos){
    x = x & ~(1 << pos);
}

bool is_bit_set(int x, int pos){
    return (x >> pos) & 1;
}  

bool is_odd(int x){
    return x & 1;
}

bool is_power_of_two(int x){
    return x && !(x & (x - 1));
}

int count_set_bits(int x){
    int cnt = 0;
    while(x){
        cnt++;
        x = x & (x - 1);
    }
    return cnt;
}

void clear_rightmost_set_bit(int &x){
    x = x & (x - 1);
}

int get_rightmost_set_bit(int x){
    return x & (-x);
}

void clear_all_trailing_ones(int &x){
    x = x & (x + 1);
}

void set_last_zero(int &x){
    x = x | (x + 1);
}

int main(){
    int x = 0b1'0000'0001; //257
    set_bit(x, 2);
    cout << x << endl; // 261 -> 0b1'0000'0101

    flip_bit(x, 2);
    cout << x << endl; // 257 -> 0b1'0000'0001

    clear_bit(x, 8);
    cout << x << endl; // 1 -> 0b1

    cout << "COMP 1\n";
    cout << is_bit_set(x, 8) << endl; // false
    set_bit(x, 8); // 257 -> 0b1'0000'0001
    cout << is_bit_set(x, 8) << endl; // true


    __has_single_bit(x);

    return 0;
}

/*

    C++ supports some of those operations since C++20 via the bit standard library:

    has_single_bit: checks if the number is a power of two
    bit_ceil / bit_floor: round up/down to the next power of two
    rotl / rotr: rotate the bits in the number
    countl_zero / countr_zero / countl_one / countr_one: count the leading/trailing zeros/ones
    popcount: count the number of set bits

    Additionally, there are also predefined functions in some compilers that help working with bits. E.g. GCC defines a list at Built-in Functions Provided by GCC that also work in older versions of C++:

    __builtin_popcount(unsigned int) returns the number of set bits (__builtin_popcount(0b0001'0010'1100) == 4)
    __builtin_ffs(int) finds the index of the first (most right) set bit (__builtin_ffs(0b0001'0010'1100) == 3)
    __builtin_clz(unsigned int) the count of leading zeros (__builtin_clz(0b0001'0010'1100) == 23)
    __builtin_ctz(unsigned int) the count of trailing zeros (__builtin_ctz(0b0001'0010'1100) == 2)

    https://cp-algorithms.com
*/