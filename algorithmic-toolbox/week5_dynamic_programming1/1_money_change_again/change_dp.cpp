#include <iostream>
#include <limits>

using namespace std;

int get_change(int m) {
    int change[m + 1];
    int c1, c3, c4;
    change[0] = 0;
    for (int i = 1; i <= m; ++i) {
        c1 = c3 = c4 = numeric_limits<int>::max();
        if (i - 1 >= 0) {
            c1 = 1 + change[i - 1];
            if (i - 3 >= 0) {
                c3 = 1 + change[i - 3];
                if (i - 4 >= 0) {
                    c4 = 1 + change[i - 4];
                }
            }
            change[i] = min(c1, min(c3, c4));
        }
    }
    return change[m];
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
