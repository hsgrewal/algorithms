# Uses python3
import random

def gcd_naive(a, b):
    current_gcd = 1
    for d in range(2, min(a, b) + 1):
        if a % d == 0 and b % d == 0:
            if d > current_gcd:
                current_gcd = d

    return current_gcd

def gcd_fast(a, b):
    if b == 0:
        return a

    rem = a % b

    return gcd_fast(b, rem)

def test_solution():
    assert gcd_fast(18, 35) == 1
    assert gcd_fast(1344, 217) == 7
    assert gcd_fast(3918848, 1653264) == 61232
    assert gcd_fast(28851538, 1183019) == 17657
    for _ in range(20):
        a, b = random.randint(0, 100), random.randint(0, 100)
        assert gcd_fast(a, b) == gcd_naive(a, b)

if __name__ == "__main__":
    a, b = map(int, input().split())
    print(gcd_fast(a, b))
    #print(gcd_naive(a, b))
    #test_solution()
