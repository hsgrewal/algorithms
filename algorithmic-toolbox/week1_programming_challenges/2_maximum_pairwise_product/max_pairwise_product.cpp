#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::vector;
using std::cin;
using std::cout;
using std::max;

long long MaxPairwiseProduct(const vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = max(max_product,
                (long long)numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const vector<int>& numbers) {
    int n = numbers.size();

    int max_index1 = -1;
    for (int first = 0; first < n; ++first) {
        if((max_index1 == -1) || (numbers[first] > numbers[max_index1])) {
            max_index1 = first;
        }
    }

    int max_index2 = -1;
    for (int second = 0; second < n; ++second) {
        if ((second != max_index1) && ((max_index2 == -1) || 
            (numbers[second] > numbers[max_index2]))) {
            max_index2 = second;
        }
    }

    return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main() {
    // Stress Test
    /*while (true) {
        int n = rand() % 10 + 2;
        cout << n << "\n";
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            a.push_back(rand() % 10000);
        }
        for (int j = 0; j < n; ++j) {
            cout << a[j] << ' ';
        }
        cout << "\n";
        long long result1 = MaxPairwiseProduct(a);
        long long result2 = MaxPairwiseProductFast(a);
        if (result1 != result2) {
            cout << "Wrong! " << result1 << ' ' << result2 << "\n";
            break;
        }
        else {
            cout << "OK\n";
        }
    }*/
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
