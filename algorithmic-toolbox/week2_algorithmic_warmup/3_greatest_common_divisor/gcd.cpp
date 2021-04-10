#include <iostream>
#include <cassert>

int gcd_naive(int a, int b) {
    int current_gcd = 1;
    for (int d = 2; d <= a && d <= b; d++) {
        if (a % d == 0 && b % d == 0) {
            if (d > current_gcd) {
                current_gcd = d;
            }
        }
    }
    return current_gcd;
}

int gcd_fast(int a, int b) {
    if (b == 0) {
        return a;
    }
    int rem = a % b;
    return gcd_fast(b, rem);
}

void test_solution() {
    assert(gcd_fast(18, 35) == 1);
    assert(gcd_fast(1344, 217) == 7);
    assert(gcd_fast(3918848, 1653264) == 61232);
    assert(gcd_fast(28851538, 1183019) == 17657);
    for (int i = 0; i < 20; ++i) {
        int a = rand() % 10;
        int b = rand() % 10;
        assert(gcd_fast(a, b) == gcd_naive(a, b));
    }
}

int main() {
    int a, b;
    std::cin >> a >> b;
    //std::cout << gcd_naive(a, b) << std::endl;
    std::cout << gcd_fast(a, b) << std::endl;
    //test_solution();
    return 0;
}
