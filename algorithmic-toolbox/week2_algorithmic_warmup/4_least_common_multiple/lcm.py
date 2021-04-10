# Uses python3
import random

def lcm_naive(a, b):
    for l in range(1, a*b + 1):
        if l % a == 0 and l % b == 0:
            return l

    return a*b

def gcd(a, b):
    if b == 0:
        return a

    rem = a % b
    return gcd(b, rem)

def lcm_fast(a, b):
    return int((a * b) / gcd(a, b))

def test_solution():
    assert lcm_fast(6, 8) == 24
    assert lcm_fast(761457, 614573) == 467970912861
    for _ in range(20):
        a, b = random.randint(1,100), random.randint(1, 100)
        assert lcm_fast(a, b) == lcm_naive(a, b)

if __name__ == '__main__':
    a, b = map(int, input().split())
    print(lcm_fast(a, b))
    #print(lcm_naive(a, b))
    #test_solution()
