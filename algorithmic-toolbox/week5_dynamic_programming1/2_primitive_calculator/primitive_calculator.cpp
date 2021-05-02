#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using std::vector;

vector<int> optimal_sequence(int n) {
    std::vector<int> sequence;
    vector<int> array(n + 1);
    int a1, m2, m3;
    for (int i = 2; i <= n; ++i) {
        a1 = m2 = m3 = std::numeric_limits<int>::max();
        if (i - 1 >= 0) {
            a1 = 1 + array.at(i - 1);
        }
        if (i % 2 == 0 and i / 2 >= 0) {
            m2 = 1 + array.at(i / 2);
        }
        if (i % 3 == 0 and i / 3 >= 0) {
            m3 = 1 + array.at(i / 3);
        }
        array[i] = std::min(a1, std::min(m2, m3));
    }
    while (n > 1) {
        sequence.push_back(n);
        if (n % 3 == 0 and array.at(n / 3) + 1 == array.at(n)) {
            n /= 3;
        } else if (n % 2 == 0 and array.at(n / 2) + 1 == array.at(n)) {
            n /= 2;
        } else if (array.at(n - 1) + 1 == array.at(n)) {
            n = n - 1;
        }
    }
    sequence.push_back(1);
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> sequence = optimal_sequence(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
}
