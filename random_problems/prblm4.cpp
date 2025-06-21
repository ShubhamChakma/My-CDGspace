#include <iostream>

using namespace std;

int calculatingrewards(int items) {
    int total = 0;
    for (int i = 1; i <= items; i++) {
        total += 4 * i;    }
    return total;
}

int main() {
    int n, m; // quantity of iteams n and m
    cout << "enter alice buy item: ";
    cin >> n;
    cout << "enter bob item: ";
    cin >> m;

    cout << "Alice's reward: " << calculatingrewards(n) << endl;
    cout << "Bob's reward: " << calculatingrewards(m) << endl;
    return 0;
}
