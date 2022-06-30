//
//  main.cpp
//  euclid-algo
//
//  Created by mndx on 30/06/2022.
//

#include <iostream>

using namespace std;

typedef struct Triple {
    long gcd;
    long x;
    long y;
} triple_t;


triple_t F(long a, long b) {

    triple_t res = {0, 0, 0};

    if(a == 0) {
        return {b, 0, 1};
    }

    if(a > 0) {
        triple_t triple_loc = F(b % a, a);
        long c = triple_loc.gcd;
        long x = triple_loc.x;
        long y = triple_loc.y;

        return {c, y - x * (b / a), x};
    }

    return res;
}

triple_t F_wrap(long a, long b) {

    triple_t res = a < b ? F(a, b) : F(b, a);

    if(a > b) {
        long tmp = res.x;
        res.x = res.y;
        res.y = tmp;
    }

    return res;
}

int main(int argc, char * argv[]) {

    long a = 27;
    long b = 111;

    triple_t res = F_wrap(a, b);

    cout << "c: " << res.gcd << ", x: " << res.x << ", y: " << res.y << endl;
    cout << "ax + by: " << (a * res.x + b * res.y) << endl;

    return 0;
}



