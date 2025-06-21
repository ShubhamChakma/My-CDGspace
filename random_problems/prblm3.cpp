#include <iostream>
#include <vector>
#include <string>

using namespace std;


string find_student_grade(const vector<string>& names, const vector<int>& grades, const string& targetname) {
    for (int i = 0; i < names.size(); ++i) {
        if (names[i] == targetname) {
            return to_string(grades[i]);
        }
    }
    return "Not Found";
}

int main() {
    vector<string> names = {"Aabb", "Bbcc", "Ccdd"};
    vector<int> grades = {75, 72, 35};

    cout << "Enter target student:-- "; 
    string targetname;
    cin >> targetname;

    string result = find_student_grade(names, grades, targetname); 
    if (result == "Not Found") {
        cout << targetname << " not found." << endl;
    } else {
        cout << "Target grade for " << targetname << " is: " << result << endl;
    }

    return 0;
}


