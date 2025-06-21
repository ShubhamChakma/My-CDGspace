#include <iostream>
using namespace std;

int main() {
    int marks[] = {70, 40, 67, 38, 89, 56, 78, 45};
    int n = 8;

    
    for (int i = 0; i < n; i++) {
        int countbigger = 0;

        for (int j = 0; j < n; j++) {
            if (marks[j] > marks[i]) {
                countbigger++;
            }
        }

        if (countbigger >= 2) {
            cout << marks[i] << " ";
        }
    }

    return 0;
}
