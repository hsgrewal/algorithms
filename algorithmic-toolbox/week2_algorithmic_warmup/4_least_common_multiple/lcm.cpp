#include <iostream>
#include <cassert>

long long lcm_naive(int a, int b) {
    for (long l = 1; l <= (long long) a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return (long long) a * b;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    int rem = a % b;
    return gcd(b, rem);
}

long long lcm_fast(int a, int b) {
    return ((long long)a * b) / gcd(a, b);
}

void test_solution() {
    assert(lcm_fast(6, 8) == 24);
    assert(lcm_fast(761457, 614573) == 467970912861);
    for (int i = 1; i < 20; ++i) {
        int a = rand() % 100;
        int b = rand() % 100;
        assert(lcm_fast(a, b) == lcm_naive(a, b));
    }
}

int main() {
    int a, b;
    std::cin >> a >> b;
    //std::cout << lcm_naive(a, b) << std::endl;
    std::cout << lcm_fast(a, b) << std::endl;
    //test_solution();
    return 0;
}
