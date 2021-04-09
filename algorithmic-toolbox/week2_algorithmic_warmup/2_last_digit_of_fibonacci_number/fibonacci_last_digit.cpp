#include <iostream>
#include <cassert>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;

    int fibonacci_last[n];
    fibonacci_last[0] = 0;
    fibonacci_last[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fibonacci_last[i] = (fibonacci_last[i - 1] + fibonacci_last[i - 2]) 
                            % 10;
    }

    return fibonacci_last[n];
}

void test_solution() {
    assert(get_fibonacci_last_digit_fast(3) == 2);
    assert(get_fibonacci_last_digit_fast(331) == 9);
    assert(get_fibonacci_last_digit_fast(327305) == 5);
    for (int n = 0; n < 20; ++n) {
        assert(get_fibonacci_last_digit_fast(n) == 
                get_fibonacci_last_digit_naive(n));
    }
}

int main() {
    int n;
    std::cin >> n;
    //int c = get_fibonacci_last_digit_naive(n);
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    //test_solution();
}
