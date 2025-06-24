#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Doctor; 
class Patient {
public:
    string name, ailment;
    int age, patient_id;
    Doctor* doctor_assigned;
    vector<string> treatment_plan;
    Patient(string n, string a, int ag, int id) {
        name = n;
        ailment = a;
        age = ag;
        patient_id = id;
        doctor_assigned = nullptr;
    }
    void add_treatment(string treatment) {
        treatment_plan.push_back(treatment);
        cout << "Treatment added: " << treatment << endl;
    }
    void assign_doctor(Doctor* doctor) {
        doctor_assigned = doctor;
        cout << "Doctor assigned: " << doctor->name << endl;
    }
    void view_details() const {
        cout << "Patient ID: " << patient_id 
             << " | Name: " << name 
             << " | Ailment: " << ailment 
             << " | Doctor: " 
             << (doctor_assigned ? doctor_assigned->name : "None") 
             << " | Treatments: ";
        for (const string& t : treatment_plan) {
            cout << t << " ";
        }
        cout << endl;
    }
};
class Doctor {
public:
    string name, specialization;
    int doctor_id;
    vector<Patient*> patient_list;
    Doctor(string n, string s, int id) {
        name = n;
        specialization = s;
        doctor_id = id;
    }
    void assign_patient(Patient* patient) {
        patient_list.push_back(patient);
        cout << "Patient assigned: " << patient->name << endl;
    }
    void view_details() const {
        cout << "Doctor ID: " << doctor_id 
             << " | Name: " << name 
             << " | Specialization: " << specialization << endl;
    }
};
class Hospital {
public:
    vector<Doctor> doctors;
    vector<Patient> patients;
    void add_doctor(Doctor doc) {
        doctors.push_back(doc);
        cout << "Doctor added: " << doc.name << endl;
    }
    void add_patient(Patient pat) {
        patients.push_back(pat);
        cout << "Patient added: " << pat.name << endl;
    }
    void assign_doctor_to_patient(int patient_id, int doctor_id) {
        Doctor* doctor = nullptr;
        Patient* patient = nullptr;

        for (Doctor& d : doctors) {
            if (d.doctor_id == doctor_id) {
                doctor = &d;
                break;
            }
        }
        for (Patient& p : patients) {
            if (p.patient_id == patient_id) {
                patient = &p;
                break;
            }
        }
        if (doctor && patient) {
            patient->assign_doctor(doctor);
            doctor->assign_patient(patient);
        } else {
            cout << "Doctor or patient not found." << endl;
        }
    }
    void view_all_patients() const {
        for (const Patient& p : patients) {
            p.view_details();
        }
    }
    void view_all_doctors() const {
        for (const Doctor& d : doctors) {
            d.view_details();
        }
    }
};
int main() {
    Hospital hospital;
    Doctor doctor1("Dr.Aimal", "Cardiology", 1);
    Doctor doctor2("Dr.Maryam", "Neurologist", 2);
    Patient patient1("Umair", "Loving Heart", 20, 111);
    Patient patient2("Ali", "Loving Heart", 21, 112);
    patient1.add_treatment("Love");
    patient2.add_treatment("Love");
    hospital.add_doctor(doctor1);
    hospital.add_doctor(doctor2);
    hospital.add_patient(patient1);
    hospital.add_patient(patient2);
    hospital.assign_doctor_to_patient(111, 1);
    hospital.assign_doctor_to_patient(112, 2);
    patient1.add_treatment("Love");
    patient2.add_treatment("Love");
    cout << "\nAll patient details:\n";
    hospital.view_all_patients();
    cout << "\nAll doctor details:\n";
    hospital.view_all_doctors();
}