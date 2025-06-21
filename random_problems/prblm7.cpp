#include <iostream>
using namespace std;

int main() {
    int scores[] = {70, 40, 67, 38, 89, 56, 78, 45};
    int n = sizeof(scores) / sizeof(scores[0]);

    for (int i = 0; i < n; i++) {
        int countGreater = 0;

        // Count how many scores are greater than scores[i]
        for (int j = 0; j < n; j++) {
            if (scores[j] > scores[i]) {
                countGreater++;
            }
        }

        // Print if at least two students scored more
        if (countGreater >= 2) {
            cout << scores[i] << " ";
        }
    }

    return 0;
}
