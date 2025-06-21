//Using Xor method for finding out odd occurence
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> gifts = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
    int oddgift = 0;
    
    for (int gift : gifts) {
        oddgift ^= gift;
    }
    
    cout << "odd-occur val gift is: " <<oddgift << endl;
    return 0;
}


