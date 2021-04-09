# Uses python3
def get_fibonacci_last_digit_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % 10


def get_fibonacci_last_digit_fast(n):
    if n <= 1:
        return n

    fibonacci_last = []
    fibonacci_last.append(0)
    fibonacci_last.append(1)

    for i in range(2, n + 1):
        fibonacci_last.append((fibonacci_last[i - 1] + 
            fibonacci_last[i - 2]) % 10)

    return fibonacci_last[n]


def test_solution():
    assert get_fibonacci_last_digit_fast(3) == 2
    assert get_fibonacci_last_digit_fast(331) == 9
    assert get_fibonacci_last_digit_fast(327305) == 5
    for n in range(20):
        assert get_fibonacci_last_digit_fast(n) == get_fibonacci_last_digit_naive(n)


if __name__ == '__main__':
    n = int(input())
    print(get_fibonacci_last_digit_fast(n))
    #test_solution()
