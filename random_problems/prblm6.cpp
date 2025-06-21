#include <iostream>
using namespace std;

int main() {
    int scores[] = {5, 6, 3, 4, 2, 3, 4, 5, 1, 3};  
    int size = 10;  

    int count[7] = {0}; // team 1-6 are given so 7th index used

    for (int i = 0; i < size; i++) {  
        int team = scores[i]; 
        count[team]++;
    }

    int maxcount = 0;
    int winner = 0;
    for (int i = 1; i <= 6; i++) {
        if (count[i] > maxcount) {
            maxcount = count[i];
            winner = i;
        }
    }
    cout << "winning team is"<< winner << endl;  
    return 0;
}