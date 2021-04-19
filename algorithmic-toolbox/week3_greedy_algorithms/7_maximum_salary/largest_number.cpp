#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool compare(string l, string r) {
    string a, b;
    a = l.append(r);
    b = r.append(l);
    return a.compare(b) > 0 ? 1 : 0;
}

string largest_number(vector<string> a) {
    std::sort(a.begin(), a.end(), compare);
    std::stringstream ret;
    for (size_t i = 0; i < a.size(); i++) {
        ret << a[i];
    }
    string result;
    ret >> result;
    return result;
}

int main() {
    int n;
    std::cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    std::cout << largest_number(a);
}
