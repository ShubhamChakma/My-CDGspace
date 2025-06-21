#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

// All employee info as per given problem
struct Emp {
    char name[50];
    int id;
    char department[30];
    int salary;
    char address[200];
    long long contact_no;
    char email_id[50];
    char position[30];
    int experience;
};

Emp employees[50]; // Declare and allocate memory to an array of structure of size 50.
int currentSize = 0;     // Tracks how many employees are currently here
int shiftCounter = 0;    // counts data shifts during insertion deletion etc.

// Arrays for generating random data
const char* names[] = {
    "Aarav", "Aditi", "Akash", "Ananya", "Arjun",
    "Bhavya", "Chaitanya", "Divya", "Gaurav", "Ishaan",
    "Jaya", "Karan", "Kavita", "Lakshmi", "Manish",
    "Neha", "Pooja", "Priya", "Rahul", "Riya",
    "Rohan", "Sanjay", "Shreya", "Suresh", "Tanvi",
    "Varun", "Vidya", "Yash", "Zara", "Amit"
};
const char* departments[] = {
    "HR", "IT", "Sales", "Marketing", "Finance",
    "Operations", "Support", "Research", "Legal", "Admin"
};

const char* addresses[] = {
    "123 MG Road, Mumbai", "456 Electronic City, Bangalore", "789 Punjabi Bagh, Delhi",
    "88 Salt Lake, Kolkata", "10 Banjara Hills, Hyderabad", "55 Koregaon Park, Pune",
    "22 Gandhi Nagar, Ahmedabad", "33 Jubilee Hills, Hyderabad", "44 Indiranagar, Bangalore",
    "77 Bandra West, Mumbai"
};

const char* emails[] = {
    "emp1@abc.com", "emp2@xyz.com", "emp3@test.com", "emp4@corp.com"
};
const char* positions[] = {
    "Manager", "Engineer", "Intern", "Analyst", "Developer",
    "Director", "Technician", "Consultant", "Coordinator", "Assistant"
};


//  Construct a database for 30 employees in the array by random values using file handling.
void generateRandEmp(const char* empfile) {
    ofstream file(empfile);
    srand(time(0));

    for (int i = 0; i < 30; i++) { // for generate 30 emp data
        const char* name = names[rand() % 8];
        int id = rand() % 9000 + 1000;
        const char* dept = departments[rand() % 4];
        int salary = 25000 + rand() % 50000;
        const char* addr = addresses[rand() % 4];
        long long contact = rand() % 1000000000 + 9000000000;
        const char* email = emails[rand() % 4];
        const char* posi = positions[rand() % 4];
        int exp = rand() % 11;

        file << name << " " << id << " " << dept << " " << salary << " "
             << addr << " " << contact << " " << email << " " << posi << " " << exp << "\n";
    }

    file.close();
    cout << "30 random emp saved saved in dataset";
}

// function to load Data from empfile
void loadEmp(const char* empfile) {
    ifstream file(empfile);
    while (currentSize < 30 && !file.eof()) {
        Emp e;
        file >> e.name >> e.id >> e.department >> e.salary;
        file.ignore(); // to skip space before getline
        file.getline(e.address, 200);
        file >> e.contact_no >> e.email_id >> e.position >> e.experience;

        employees[currentSize++] = e;
    }
    file.close();
}

// Search for 4th person ( by ID) and print name of the employee
void searchByID(int id) {
    for (int i = 0; i < currentSize; i++) {
        if (employees[i].id == id) {
            cout << "Found: " << employees[i].name << endl;
            return;
        }
    }
    cout << "Employee not found.\n";
}
// Print data for the first employee
void printfirstEmp(const Emp& e) {
    cout << "Name: " << e.name << ", ID: " << e.id << ", Dept: " << e.department
         << ", Salary: " << e.salary << ", Position: " << e.position
         << ", Experience: " << e.experience << " yrs" << endl;
}



// delete data for the last employee
void deleteLast() {
    if (currentSize > 0) {
        currentSize--;
        shiftCounter = 0; // no shifting needed
    }
}

// Delete data for the employee at first position
void deleteFirst() {
    shiftCounter = 0;
    for (int i = 1; i < currentSize; i++) {
        employees[i - 1] = employees[i];
        shiftCounter++;
    }
    currentSize--;
}

// Delete data for the employee at third position
void deleteThird() {
    shiftCounter = 0;
    for (int i = 3; i < currentSize; i++) {
        employees[i - 1] = employees[i];
        shiftCounter++;
    }
    currentSize--;
}

// insertion voids
Emp createNewEmployee(int id) {
    Emp e;
    strcpy(e.name, "NewEmp");
    e.id = id;
    strcpy(e.department, "IT");
    e.salary = 40000;
    strcpy(e.address, "New Street City");
    e.contact_no = 9876543210;
    strcpy(e.email_id, "new@company.com");
    strcpy(e.position, "Engineer");
    e.experience = 1;
    return e;
}

//Insert data for a new employee at last position
void insertAtLast(Emp e) {
    employees[currentSize++] = e;
    shiftCounter = 0;
}

//Insert data for a new employee at first position
void insertAtFirst(Emp e) {
    shiftCounter = 0;
    for (int i = currentSize; i > 0; i--) {
        employees[i] = employees[i - 1];
        shiftCounter++;
    }
    employees[0] = e;
    currentSize++;
}

//Insert data for a new employee at second position
void insertAtSecond(Emp e) {
    shiftCounter = 0;
    for (int i = currentSize; i > 1; i--) {
        employees[i] = employees[i - 1];
        shiftCounter++;
    }
    employees[1] = e;
    currentSize++;
}


int main() {
    
    generateRandEmp("employee_data.txt");

    
    loadEmp("employee_data.txt");

    cout << "\n--- Operation Outputs ---\n";

    
    if (currentSize >= 4) {
        cout << "a. Search 4th by ID: ";
        searchByID(employees[3].id);
    }

    
    cout << "\nb. First Employee:\n";
    printEmp (employees[0]);

    
    cout << "\nc. Last Employee:\n";
    printEmp(employees[currentSize - 1]);

    
    deleteLast();
    cout << "\nd. Deleted last | Shifts: " << shiftCounter << endl;

    
    deleteFirst();
    cout << "e. Deleted first | Shifts: " << shiftCounter << endl;

    
    deleteThird();
    cout << "f. Deleted third | Shifts: " << shiftCounter << endl;

    
    insertAtLast(createNewEmployee(9991));
    cout << "g. Inserted at last | Shifts: " << shiftCounter << endl;

    
    insertAtFirst(createNewEmployee(9992));
    cout << "h. Inserted at first | Shifts: " << shiftCounter << endl;

    
    insertAtSecond(createNewEmployee(9993));
    cout << "i. Inserted at second | Shifts: " << shiftCounter << endl;

    return 0;
}
