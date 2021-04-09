# Uses python3
def calc_fib(n):
    if (n <= 1):
        return n

    return calc_fib(n - 1) + calc_fib(n - 2)


def fibonacci_fast(n):
    fibonacci = []
    fibonacci.append(0)
    fibonacci.append(1)

    for i in range(2, n + 1):
        fibonacci.append(fibonacci[i - 1] + fibonacci[i - 2])

    return fibonacci[n]


def test_solution():
    assert fibonacci_fast(3) == 2
    assert fibonacci_fast(10) == 55
    for n in range(20):
        assert fibonacci_fast(n) == calc_fib(n)

n = int(input())
print(fibonacci_fast(n))
#test_solution()
