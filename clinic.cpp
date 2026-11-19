#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class Patient {
private:
    int id;
    string name, phone;

public:
    Patient(int i, const string& n, const string& p)
        : id(i), name(n), phone(p) {}

    int getId() const { return id; }
    string getName() const { return name; }

    void display() const {
        cout << "ID: " << id << " | Name: " << name
             << " | Phone: " << phone << '\n';
    }

    void save(ofstream& file) const {
        file << id << '\n' << name << '\n' << phone << '\n';
    }
};

class Clinic {
private:
    vector<Patient> patients;
    queue<int> waitingQueue;
    int nextId = 1;
    int nextToken = 1;

    Patient* findById(int id) {
        for (Patient& p : patients)
            if (p.getId() == id) return &p;
        return nullptr;
    }

    void loadRecords() {
        ifstream file("patients.txt");
        int id;
        string name, phone;

        while (file >> id) {
            file.ignore();
            getline(file, name);
            getline(file, phone);

            patients.emplace_back(id, name, phone);
            waitingQueue.push(id);

            if (id >= nextId) nextId = id + 1;
            nextToken++;
        }
    }

public:
    Clinic() {
        loadRecords();
    }

    void registerPatient() {
        string name, phone;

        cout << "Patient name: ";
        getline(cin >> ws, name);

        cout << "Phone number: ";
        getline(cin, phone);

        Patient p(nextId++, name, phone);
        patients.push_back(p);
        waitingQueue.push(p.getId());

        cout << "Registered! Patient ID: " << p.getId()
             << " | Token: " << nextToken++ << '\n';
    }

    void showPatients() const {
        if (patients.empty()) {
            cout << "No patient records found.\n";
            return;
        }

        for (const Patient& p : patients)
            p.display();
    }

    void searchPatient() {
        int id;

        cout << "Enter patient ID: ";
        cin >> id;

        Patient* p = findById(id);

        if (p)
            p->display();
        else
            cout << "Patient not found.\n";
    }

    void showQueue() const {
        if (waitingQueue.empty()) {
            cout << "Waiting queue is empty.\n";
            return;
        }

        queue<int> temp = waitingQueue;

        cout << "Waiting patient IDs: ";

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << '\n';
    }

    void callNextPatient() {
        if (waitingQueue.empty()) {
            cout << "No patients are waiting.\n";
            return;
        }

        int id = waitingQueue.front();
        waitingQueue.pop();

        Patient* p = findById(id);

        if (p) {
            cout << "Now calling: ";
            p->display();
        }
    }

    void saveRecords() const {
        ofstream file("patients.txt");

        for (const Patient& p : patients)
            p.save(file);

        cout << "Patient records saved.\n";
    }
};

int main() {
    Clinic clinic;
    int choice;

    do {
        cout << "\n=== CLINIC MANAGEMENT SYSTEM ===\n"
             << "1. Register patient / Book appointment\n"
             << "2. View all patients\n"
             << "3. Search patient\n"
             << "4. Display waiting queue\n"
             << "5. Call next patient\n"
             << "6. Save records\n"
             << "0. Save and Exit\n"
             << "Enter choice: ";

        cin >> choice;

        switch (choice) {
        case 1:
            clinic.registerPatient();
            break;
        case 2:
            clinic.showPatients();
            break;
        case 3:
            clinic.searchPatient();
            break;
        case 4:
            clinic.showQueue();
            break;
        case 5:
            clinic.callNextPatient();
            break;
        case 6:
            clinic.saveRecords();
            break;
        case 0:
            clinic.saveRecords();
            cout << "Thank you for using the system.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}