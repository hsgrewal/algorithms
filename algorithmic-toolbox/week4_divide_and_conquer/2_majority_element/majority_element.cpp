#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
    if (left == right) return -1;
    if (left + 1 == right) return a[left];
    
    vector<int> tmp;
    for (int i : a) {
        if (!tmp.empty() && tmp[tmp.size() - 1] != i) {
            tmp.pop_back();
        }
        else if (tmp.empty() || tmp[tmp.size() - 1] == i) {
            tmp.push_back(i);
        }
    }
    if (tmp.empty()) {
        return -1;
    }
    int candidate = tmp[tmp.size() - 1];
    tmp.pop_back();
    int count = 0;
    for (int x : a) {
        if (x == candidate) {
            ++count;
        }
    }
    if (count > a.size() / 2) {
        return candidate;
    }
    return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
