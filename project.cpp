#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User
{
protected:
    int id;
    string name;
    string password;

public:
    User();
    User(int, string, string);
    User(const User&);
    User& operator=(const User&);

    void setId(int);
    void setName(string);
    void setPassword(string);

    int getId() const;
    string getName() const;
    string getPassword() const;

    virtual void display() = 0;
    virtual ~User();
};

#endif

#include "User.h"

User::User()
{
    id = 0;
    name = "";
    password = "";
}

User::User(int i, string n, string p)
{
    id = i;
    name = n;
    password = p;
}

User::User(const User& obj)
{
    id = obj.id;
    name = obj.name;
    password = obj.password;
}

User& User::operator=(const User& obj)
{
    if (this != &obj)
    {
        id = obj.id;
        name = obj.name;
        password = obj.password;
    }
    return *this;
}

void User::setId(int i) { id = i; }
void User::setName(string n) { name = n; }
void User::setPassword(string p) { password = p; }

int User::getId() const { return id; }
string User::getName() const { return name; }
string User::getPassword() const { return password; }

User::~User() {}

#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User
{
private:
    string designation;

public:
    Admin();
    Admin(int, string, string, string);
    Admin(const Admin&);
    Admin& operator=(const Admin&);

    void setDesignation(string);
    string getDesignation() const;

    void display() override;
    ~Admin();
};

#endif

#include "Admin.h"

Admin::Admin() : User()
{
    designation = "";
}

Admin::Admin(int i, string n, string p, string d)
    : User(i, n, p)
{
    designation = d;
}

Admin::Admin(const Admin& obj) : User(obj)
{
    designation = obj.designation;
}

Admin& Admin::operator=(const Admin& obj)
{
    if (this != &obj)
    {
        User::operator=(obj);
        designation = obj.designation;
    }
    return *this;
}

void Admin::setDesignation(string d) { designation = d; }
string Admin::getDesignation() const { return designation; }

void Admin::display()
{
    cout << "\n========== ADMIN DETAILS ==========\n";
    cout << "ID          : " << id << endl;
    cout << "Name        : " << name << endl;
    cout << "Designation : " << designation << endl;
}

Admin::~Admin() {}

#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"

class Student : public User
{
private:
    string department;
    bool transportApproved;

public:
    Student();
    Student(int, string, string, string, bool);
    Student(const Student&);
    Student& operator=(const Student&);

    void setDepartment(string);
    void setTransportStatus(bool);

    string getDepartment() const;
    bool getTransportStatus() const;

    void applyTransport();
    void cancelRegistration();

    void display() override;
    ~Student();
};

#endif

#include "Student.h"

Student::Student() : User()
{
    department = "";
    transportApproved = false;
}

Student::Student(int i, string n, string p, string d, bool status)
    : User(i, n, p)
{
    department = d;
    transportApproved = status;
}

Student::Student(const Student& obj) : User(obj)
{
    department = obj.department;
    transportApproved = obj.transportApproved;
}

Student& Student::operator=(const Student& obj)
{
    if (this != &obj)
    {
        User::operator=(obj);
        department = obj.department;
        transportApproved = obj.transportApproved;
    }
    return *this;
}

void Student::setDepartment(string d) { department = d; }
void Student::setTransportStatus(bool s) { transportApproved = s; }
string Student::getDepartment() const { return department; }
bool Student::getTransportStatus() const { return transportApproved; }

void Student::applyTransport()
{
    cout << "\nTransport application submitted successfully.\n";
}

void Student::cancelRegistration()
{
    transportApproved = false;
    cout << "\nTransport registration cancelled.\n";
}

void Student::display()
{
    cout << "\n========== STUDENT DETAILS ==========\n";
    cout << "ID         : " << id << endl;
    cout << "Name       : " << name << endl;
    cout << "Department : " << department << endl;
    cout << "Transport  : " << (transportApproved ? "Approved" : "Not Approved") << endl;
}

Student::~Student() {}

#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
using namespace std;

class Route;

class Vehicle
{
protected:
    int vehicleId;
    string model;
    int capacity;
    int occupiedSeats;
    Route* routeAssigned;

public:
    Vehicle();
    Vehicle(int, string, int);
    Vehicle(const Vehicle&);
    Vehicle& operator=(const Vehicle&);

    int getVehicleId() const;
    string getModel() const;
    int getCapacity() const;
    int getOccupiedSeats() const;

    void setVehicleId(int);
    void setModel(string);
    void setCapacity(int);

    void assignRoute(Route*);
    bool hasSpace() const;
    void occupySeat();
    void freeSeat();

    virtual void displayVehicle() = 0;
    virtual ~Vehicle();
};

#endif

#include "Vehicle.h"

Vehicle::Vehicle()
{
    vehicleId = 0;
    model = "";
    capacity = 0;
    occupiedSeats = 0;
    routeAssigned = nullptr;
}

Vehicle::Vehicle(int id, string m, int cap)
{
    vehicleId = id;
    model = m;
    capacity = cap;
    occupiedSeats = 0;
    routeAssigned = nullptr;
}

Vehicle::Vehicle(const Vehicle& obj)
{
    vehicleId = obj.vehicleId;
    model = obj.model;
    capacity = obj.capacity;
    occupiedSeats = obj.occupiedSeats;
    routeAssigned = obj.routeAssigned;
}

Vehicle& Vehicle::operator=(const Vehicle& obj)
{
    if (this != &obj)
    {
        vehicleId = obj.vehicleId;
        model = obj.model;
        capacity = obj.capacity;
        occupiedSeats = obj.occupiedSeats;
        routeAssigned = obj.routeAssigned;
    }
    return *this;
}

int Vehicle::getVehicleId() const { return vehicleId; }
string Vehicle::getModel() const { return model; }
int Vehicle::getCapacity() const { return capacity; }
int Vehicle::getOccupiedSeats() const { return occupiedSeats; }

void Vehicle::setVehicleId(int id) { vehicleId = id; }
void Vehicle::setModel(string m) { model = m; }
void Vehicle::setCapacity(int c) { capacity = c; }

void Vehicle::assignRoute(Route* r) { routeAssigned = r; }

bool Vehicle::hasSpace() const { return occupiedSeats < capacity; }

void Vehicle::occupySeat()
{
    if (occupiedSeats < capacity)
        occupiedSeats++;
}

void Vehicle::freeSeat()
{
    if (occupiedSeats > 0)
        occupiedSeats--;
}

Vehicle::~Vehicle() {}

#ifndef VAN_H
#define VAN_H

#include "Vehicle.h"

class Van : public Vehicle
{
private:
    bool acAvailable;

public:
    Van();
    Van(int, string, int, bool);
    Van(const Van&);
    Van& operator=(const Van&);

    void setAC(bool);
    bool getAC() const;

    void displayVehicle() override;
    ~Van();
};

#endif
#include "Van.h"

Van::Van() : Vehicle() { acAvailable = false; }

Van::Van(int id, string model, int cap, bool ac)
    : Vehicle(id, model, cap) { acAvailable = ac; }

Van::Van(const Van& obj) : Vehicle(obj) { acAvailable = obj.acAvailable; }

Van& Van::operator=(const Van& obj)
{
    if (this != &obj)
    {
        Vehicle::operator=(obj);
        acAvailable = obj.acAvailable;
    }
    return *this;
}

void Van::setAC(bool a) { acAvailable = a; }
bool Van::getAC() const { return acAvailable; }

void Van::displayVehicle()
{
    cout << "\n========== VAN DETAILS ==========\n";
    cout << "Vehicle ID     : " << vehicleId << endl;
    cout << "Model          : " << model << endl;
    cout << "Capacity       : " << capacity << endl;
    cout << "Occupied Seats : " << occupiedSeats << endl;
    cout << "Available Seats: " << (capacity - occupiedSeats) << endl;
    cout << "AC             : " << (acAvailable ? "Available" : "Not Available") << endl;
}

Van::~Van() {}

#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"

class Bus : public Vehicle
{
private:
    string busType;

public:
    Bus();
    Bus(int, string, int, string);
    Bus(const Bus&);
    Bus& operator=(const Bus&);

    void setBusType(string);
    string getBusType() const;

    void displayVehicle() override;
    ~Bus();
};

#endif
#include "Bus.h"

Bus::Bus() : Vehicle() { busType = ""; }

Bus::Bus(int id, string model, int cap, string type)
    : Vehicle(id, model, cap) { busType = type; }

Bus::Bus(const Bus& obj) : Vehicle(obj) { busType = obj.busType; }

Bus& Bus::operator=(const Bus& obj)
{
    if (this != &obj)
    {
        Vehicle::operator=(obj);
        busType = obj.busType;
    }
    return *this;
}

void Bus::setBusType(string t) { busType = t; }
string Bus::getBusType() const { return busType; }

void Bus::displayVehicle()
{
    cout << "\n========== BUS DETAILS ==========\n";
    cout << "Vehicle ID     : " << vehicleId << endl;
    cout << "Model          : " << model << endl;
    cout << "Type           : " << busType << endl;
    cout << "Capacity       : " << capacity << endl;
    cout << "Occupied Seats : " << occupiedSeats << endl;
    cout << "Available Seats: " << (capacity - occupiedSeats) << endl;
}

Bus::~Bus() {}

#ifndef BILL_H
#define BILL_H

#include <iostream>
using namespace std;

class Bill
{
private:
    int billId;
    double baseFee;
    double lateFine;
    bool isPaid;

public:
    Bill();
    Bill(int, double);
    Bill(const Bill&);
    Bill& operator=(const Bill&);

    void setBillId(int);
    void setBaseFee(double);
    void setLateFine(double);
    void setPaymentStatus(bool);

    int getBillId() const;
    double getBaseFee() const;
    double getLateFine() const;
    bool getPaymentStatus() const;

    void applyLateFine(double);
    double calculateTotal() const;
    void markAsPaid();

    void displayBill() const;
    ~Bill();
};

#endif
#include "Bill.h"

Bill::Bill()
{
    billId = 0;
    baseFee = 0;
    lateFine = 0;
    isPaid = false;
}

Bill::Bill(int id, double fee)
{
    billId = id;
    baseFee = fee;
    lateFine = 0;
    isPaid = false;
}

Bill::Bill(const Bill& obj)
{
    billId = obj.billId;
    baseFee = obj.baseFee;
    lateFine = obj.lateFine;
    isPaid = obj.isPaid;
}

Bill& Bill::operator=(const Bill& obj)
{
    if (this != &obj)
    {
        billId = obj.billId;
        baseFee = obj.baseFee;
        lateFine = obj.lateFine;
        isPaid = obj.isPaid;
    }
    return *this;
}

void Bill::setBillId(int id) { billId = id; }
void Bill::setBaseFee(double fee) { baseFee = fee; }
void Bill::setLateFine(double fine) { lateFine = fine; }
void Bill::setPaymentStatus(bool s) { isPaid = s; }

int Bill::getBillId() const { return billId; }
double Bill::getBaseFee() const { return baseFee; }
double Bill::getLateFine() const { return lateFine; }
bool Bill::getPaymentStatus() const { return isPaid; }

void Bill::applyLateFine(double fine) { lateFine += fine; }
double Bill::calculateTotal() const { return baseFee + lateFine; }
void Bill::markAsPaid() { isPaid = true; }

void Bill::displayBill() const
{
    cout << "\n--- BILL ---\n";
    cout << "Bill ID   : " << billId << endl;
    cout << "Base Fee  : Rs. " << baseFee << endl;
    cout << "Late Fine : Rs. " << lateFine << endl;
    cout << "Total     : Rs. " << calculateTotal() << endl;
    cout << "Status    : " << (isPaid ? "PAID" : "UNPAID") << endl;
}

Bill::~Bill() {}

#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
using namespace std;

class Vehicle;

class Route
{
private:
    int routeId;
    string startPoint;
    string endPoint;
    double distance;
    Vehicle* assignedVehicle;

public:

    Route();
    Route(int, string, string, double);
    Route(const Route&);
    Route& operator=(const Route&);

    int getRouteId() const;
    string getStartPoint() const;
    string getEndPoint() const;
    double getDistance() const;

    void setRouteId(int);
    void setStartPoint(string);
    void setEndPoint(string);
    void setDistance(double);

    void assignVehicle(Vehicle*);

    void displayRoute() const;
    ~Route();
};

#endif
#include "Route.h"
#include "Vehicle.h"

Route::Route()
{
    routeId = 0;
    startPoint = "";
    endPoint = "";
    distance = 0;
    assignedVehicle = nullptr;
}

Route::Route(int id, string s, string e, double d)
{
    routeId = id;
    startPoint = s;
    endPoint = e;
    distance = d;
    assignedVehicle = nullptr;
}

Route::Route(const Route& obj)
{
    routeId = obj.routeId;
    startPoint = obj.startPoint;
    endPoint = obj.endPoint;
    distance = obj.distance;
    assignedVehicle = obj.assignedVehicle;
}

Route& Route::operator=(const Route& obj)
{
    if (this != &obj)
    {
        routeId = obj.routeId;
        startPoint = obj.startPoint;
        endPoint = obj.endPoint;
        distance = obj.distance;
        assignedVehicle = obj.assignedVehicle;
    }
    return *this;
}

int Route::getRouteId() const { return routeId; }
string Route::getStartPoint() const { return startPoint; }
string Route::getEndPoint() const { return endPoint; }
double Route::getDistance()  const{ return distance; }

void Route::setRouteId(int id) { routeId = id; }
void Route::setStartPoint(string s) { startPoint = s; }
void Route::setEndPoint(string e) { endPoint = e; }
void Route::setDistance(double d) { distance = d; }

void Route::assignVehicle(Vehicle* v) { assignedVehicle = v; }

void Route::displayRoute() const
{
    cout << "\n========== ROUTE DETAILS ==========\n";
    cout << "Route ID   : " << routeId << endl;
    cout << "Start      : " << startPoint << endl;
    cout << "End        : " << endPoint << endl;
    cout << "Distance   : " << distance << " km" << endl;
    cout << "Vehicle    : " << (assignedVehicle ? "Assigned" : "Not Assigned") << endl;
}

Route::~Route() {}

#ifndef TRANSPORTPASS_H
#define TRANSPORTPASS_H

#include <iostream>
#include "Bill.h"
using namespace std;

class Student;
class Vehicle;
class Route;

class TransportPass
{
private:
    int passId;
    int studentId;  
    int vehicleId;
    int routeId;
    Bill bill;
    bool approved;

public:
    TransportPass();
    TransportPass(int, int, int, int, double);
    TransportPass(const TransportPass&);
    TransportPass& operator=(const TransportPass&);

    int getPassId() const;
    int getStudentId() const;
    int getVehicleId() const;
    int getRouteId() const;
    bool isApproved() const;

    void setApproval(bool);
    void approve();
    void reject();

    void generateBill(double);
    void applyLateFine(double);
    void payBill();
    bool isBillPaid() const;

    void displayPass() const;
    ~TransportPass();
};

#endif
#include "TransportPass.h"

TransportPass::TransportPass()
{
    passId = 0;
    studentId = 0;
    vehicleId = 0;
    routeId = 0;
    approved = false;
}

TransportPass::TransportPass(int pid, int sid, int vid, int rid, double fee)
{
    passId = pid;
    studentId = sid;
    vehicleId = vid;
    routeId = rid;
    approved = false;
    bill = Bill(pid, fee);
}

TransportPass::TransportPass(const TransportPass& obj) : bill(obj.bill)
{
    passId = obj.passId;
    studentId = obj.studentId;
    vehicleId = obj.vehicleId;
    routeId = obj.routeId;
    approved = obj.approved;
}

TransportPass& TransportPass::operator=(const TransportPass& obj)
{
    if (this != &obj)
    {
        passId = obj.passId;
        studentId = obj.studentId;
        vehicleId = obj.vehicleId;
        routeId = obj.routeId;
        approved = obj.approved;
        bill = obj.bill;
    }
    return *this;
}

int TransportPass::getPassId() const { return passId; }
int TransportPass::getStudentId() const { return studentId; }
int TransportPass::getVehicleId() const { return vehicleId; }
int TransportPass::getRouteId() const { return routeId; }
bool TransportPass::isApproved() const { return approved; }

void TransportPass::setApproval(bool s) { approved = s; }

void TransportPass::approve()
{
    approved = true;
    cout << "\nTransport Pass Approved!\n";
}

void TransportPass::reject()
{
    approved = false;
    cout << "\nTransport Pass Rejected.\n";
}

void TransportPass::generateBill(double fee)
{
    bill.setBaseFee(fee);
}

void TransportPass::applyLateFine(double fine)
{
    bill.applyLateFine(fine);
}

void TransportPass::payBill()
{
    bill.markAsPaid();
    cout << "\nBill paid successfully!\n";
}

bool TransportPass::isBillPaid() const
{
    return bill.getPaymentStatus();
}

void TransportPass::displayPass() const
{
    cout << "\n========== TRANSPORT PASS ==========\n";
    cout << "Pass ID    : " << passId << endl;
    cout << "Student ID : " << studentId << endl;
    cout << "Vehicle ID : " << vehicleId << endl;
    cout << "Route ID   : " << routeId << endl;
    cout << "Status     : " << (approved ? "Approved" : "Pending") << endl;
    bill.displayBill();
}

TransportPass::~TransportPass() {}

#ifndef TRANSPORTMANAGER_H
#define TRANSPORTMANAGER_H

#include <iostream>
#include <fstream>

#include "Student.h"
#include "Admin.h"
#include "Bus.h"
#include "Van.h"
#include "Route.h"
#include "TransportPass.h"

using namespace std;

class TransportManager
{
private:
    Student**       students;
    Admin**         admins;
    Vehicle**       vehicles;
    Route**         routes;
    TransportPass** passes;

    int studentCount;
    int adminCount;
    int vehicleCount;
    int routeCount;
    int passCount;

public:
    TransportManager();
    ~TransportManager();

    // ---- Authentication ----
    Student* loginStudent(int id, string password);
    Admin*   loginAdmin(int id, string password);

    // ---- Student Management ----
    void addStudent(Student*);
    bool studentIdExists(int id);

    // ---- Admin Management ----
    void addAdmin(Admin*);

    // ---- Vehicle Management ----
    void addVehicle(Vehicle*);
    void removeVehicle(int id);
    bool vehicleIdExists(int id);

    // ---- Route Management ----
    void addRoute(Route*);
    bool routeIdExists(int id);

    // ---- Assignment ----
    void assignVehicleToRoute(int routeId, int vehicleId);

    // ---- Transport Application ----
    void applyTransport(int studentId, int routeId, int vehicleId, double fee);
    void cancelTransport(int studentId);

    // ---- Pass Management ----
    void approveRequest(int passId);
    void rejectRequest(int passId);
    void payBill(int passId);
    void applyLateFine(int passId, double fine);

    // ---- Display ----
    void displayAllStudents();
    void displayAllVehicles();
    void displayAllRoutes();
    void displayAllPasses();
    void displayStudentPass(int studentId);
    void generateReports();

    // ---- File I/O ----
    void saveData();
    void saveStudents();
    void loadStudents();
    void saveVehicles();
    void loadVehicles();
    void saveRoutes();
    void loadRoutes();
    void savePasses();
    void loadPasses();
};

#endif
#include "TransportManager.h"

TransportManager::TransportManager()
{
    students = new Student*[100];
    admins   = new Admin*[10];
    vehicles = new Vehicle*[100];
    routes   = new Route*[100];
    passes   = new TransportPass*[100];

    studentCount = 0;
    adminCount   = 0;
    vehicleCount = 0;
    routeCount   = 0;
    passCount    = 0;

    admins[adminCount++] = new Admin(1, "admin", "admin123", "Transport Head");

    loadStudents();
    loadVehicles();
    loadRoutes();
    loadPasses();
}

// ======================== AUTHENTICATION ========================

Student* TransportManager::loginStudent(int id, string password)
{
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i]->getId() == id &&
            students[i]->getPassword() == password)
        {
            return students[i];
        }
    }
    return nullptr;
}

Admin* TransportManager::loginAdmin(int id, string password)
{
    for (int i = 0; i < adminCount; i++)
    {
        if (admins[i]->getId() == id &&
            admins[i]->getPassword() == password)
        {
            return admins[i];
        }
    }
    return nullptr;
}

// ======================== STUDENT ========================

bool TransportManager::studentIdExists(int id)
{
    for (int i = 0; i < studentCount; i++)
        if (students[i]->getId() == id) return true;
    return false;
}

void TransportManager::addStudent(Student* s)
{
    students[studentCount++] = s;
    cout << "\nStudent registered successfully!\n";
}

// ======================== ADMIN ========================

void TransportManager::addAdmin(Admin* a)
{
    admins[adminCount++] = a;
}

// ======================== VEHICLE ========================

bool TransportManager::vehicleIdExists(int id)
{
    for (int i = 0; i < vehicleCount; i++)
        if (vehicles[i]->getVehicleId() == id) return true;
    return false;
}

void TransportManager::addVehicle(Vehicle* v)
{
    vehicles[vehicleCount++] = v;
    cout << "\nVehicle added successfully!\n";
}

void TransportManager::removeVehicle(int id)
{
    for (int i = 0; i < vehicleCount; i++)
    {
        if (vehicles[i]->getVehicleId() == id)
        {
            delete vehicles[i];
            for (int j = i; j < vehicleCount - 1; j++)
                vehicles[j] = vehicles[j + 1];
            vehicleCount--;
            cout << "\nVehicle removed successfully!\n";
            return;
        }
    }
    cout << "\nVehicle ID not found!\n";
}

// ======================== ROUTE ========================

bool TransportManager::routeIdExists(int id)
{
    for (int i = 0; i < routeCount; i++)
        if (routes[i]->getRouteId() == id) return true;
    return false;
}

void TransportManager::addRoute(Route* r)
{
    routes[routeCount++] = r;
    cout << "\nRoute added successfully!\n";
}

// ======================== ASSIGN ========================

void TransportManager::assignVehicleToRoute(int rid, int vid)
{
    Route*   r = nullptr;
    Vehicle* v = nullptr;

    for (int i = 0; i < routeCount; i++)
        if (routes[i]->getRouteId() == rid) r = routes[i];

    for (int i = 0; i < vehicleCount; i++)
        if (vehicles[i]->getVehicleId() == vid) v = vehicles[i];

    if (!r) { cout << "\nRoute not found!\n"; return; }
    if (!v) { cout << "\nVehicle not found!\n"; return; }

    r->assignVehicle(v);
    v->assignRoute(r);
    cout << "\nVehicle assigned to route successfully!\n";
}

// ======================== TRANSPORT APPLICATION ========================

void TransportManager::applyTransport(int sid, int rid, int vid, double fee)
{
    Student* s = nullptr;
    Route*   r = nullptr;
    Vehicle* v = nullptr;

    for (int i = 0; i < studentCount; i++)
        if (students[i]->getId() == sid) s = students[i];

    for (int i = 0; i < routeCount; i++)
        if (routes[i]->getRouteId() == rid) r = routes[i];

    for (int i = 0; i < vehicleCount; i++)
        if (vehicles[i]->getVehicleId() == vid) v = vehicles[i];

    if (!s) { cout << "\nStudent not found!\n"; return; }
    if (!r) { cout << "\nRoute not found!\n"; return; }
    if (!v) { cout << "\nVehicle not found!\n"; return; }

    // Check if student already applied
    for (int i = 0; i < passCount; i++)
    {
        if (passes[i]->getStudentId() == sid)
        {
            cout << "\nYou already have a transport application!\n";
            return;
        }
    }

    if (!v->hasSpace())
    {
        cout << "\nVehicle is full! No seats available.\n";
        return;
    }

    v->occupySeat();
    passes[passCount] = new TransportPass(passCount + 1, sid, vid, rid, fee);
    passCount++;

    cout << "\nTransport application submitted! Pass ID: " << passCount << endl;
}

void TransportManager::cancelTransport(int sid)
{
    for (int i = 0; i < passCount; i++)
    {
        if (passes[i]->getStudentId() == sid)
        {
            // Free the seat
            int vid = passes[i]->getVehicleId();
            for (int j = 0; j < vehicleCount; j++)
            {
                if (vehicles[j]->getVehicleId() == vid)
                {
                    vehicles[j]->freeSeat();
                    break;
                }
            }

            delete passes[i];
            for (int j = i; j < passCount - 1; j++)
                passes[j] = passes[j + 1];
            passCount--;

            cout << "\nTransport registration cancelled successfully!\n";
            return;
        }
    }
    cout << "\nNo transport application found for this student.\n";
}

// ======================== PASS MANAGEMENT ========================

void TransportManager::approveRequest(int pid)
{
    for (int i = 0; i < passCount; i++)
    {
        if (passes[i]->getPassId() == pid)
        {
            passes[i]->approve();
            return;
        }
    }
    cout << "\nPass ID not found!\n";
}

void TransportManager::rejectRequest(int pid)
{
    for (int i = 0; i < passCount; i++)
    {
        if (passes[i]->getPassId() == pid)
        {
            passes[i]->reject();
            return;
        }
    }
    cout << "\nPass ID not found!\n";
}

void TransportManager::payBill(int pid)
{
    for (int i = 0; i < passCount; i++)
    {
        if (passes[i]->getPassId() == pid)
        {
            if (passes[i]->isBillPaid())
                cout << "\nBill is already paid!\n";
            else
                passes[i]->payBill();
            return;
        }
    }
    cout << "\nPass ID not found!\n";
}

void TransportManager::applyLateFine(int pid, double fine)
{
    for (int i = 0; i < passCount; i++)
    {
        if (passes[i]->getPassId() == pid)
        {
            passes[i]->applyLateFine(fine);
            cout << "\nLate fine of Rs. " << fine << " applied!\n";
            return;
        }
    }
    cout << "\nPass ID not found!\n";
}

// ======================== DISPLAY ========================

void TransportManager::displayAllStudents()
{
    if (studentCount == 0)
    {
        cout << "\nNo students registered.\n";
        return;
    }
    for (int i = 0; i < studentCount; i++)
        students[i]->display();
}

void TransportManager::displayAllVehicles()
{
    if (vehicleCount == 0)
    {
        cout << "\nNo vehicles available.\n";
        return;
    }
    for (int i = 0; i < vehicleCount; i++)
        vehicles[i]->displayVehicle();
}

void TransportManager::displayAllRoutes()
{
    if (routeCount == 0)
    {
        cout << "\nNo routes available.\n";
        return;
    }
    for (int i = 0; i < routeCount; i++)
        routes[i]->displayRoute();
}

void TransportManager::displayAllPasses()
{
    if (passCount == 0)
    {
        cout << "\nNo transport applications found.\n";
        return;
    }
    for (int i = 0; i < passCount; i++)
        passes[i]->displayPass();
}

void TransportManager::displayStudentPass(int sid)
{
    bool found = false;
    for (int i = 0; i < passCount; i++)
    {
        if (passes[i]->getStudentId() == sid)
        {
            passes[i]->displayPass();
            found = true;
        }
    }
    if (!found)
        cout << "\nNo transport application found for your account.\n";
}

void TransportManager::generateReports()
{
    cout << "\n========== SYSTEM REPORT ==========\n";
    cout << "Total Students    : " << studentCount << endl;
    cout << "Total Vehicles    : " << vehicleCount << endl;
    cout << "Total Routes      : " << routeCount << endl;
    cout << "Total Applications: " << passCount << endl;

    int approved = 0, pending = 0;
    for (int i = 0; i < passCount; i++)
    {
        if (passes[i]->isApproved()) approved++;
        else pending++;
    }
    cout << "Approved Passes   : " << approved << endl;
    cout << "Pending Passes    : " << pending << endl;
    cout << "===================================\n";
}

// ======================== FILE I/O ========================

void TransportManager::saveStudents()
{
    ofstream fout("students.txt");
    for (int i = 0; i < studentCount; i++)
    {
        fout << students[i]->getId()             << " "
             << students[i]->getName()           << " "
             << students[i]->getPassword()       << " "
             << students[i]->getDepartment()     << " "
             << students[i]->getTransportStatus()<< "\n";
    }
    fout.close();
}

void TransportManager::loadStudents()
{
    ifstream fin("students.txt");
    if (!fin) return;

    int id; string name, pass, dept; bool status;
    while (fin >> id >> name >> pass >> dept >> status)
    {
        students[studentCount++] = new Student(id, name, pass, dept, status);
    }
    fin.close();
}

void TransportManager::saveVehicles()
{
    ofstream fout("vehicles.txt");
    for (int i = 0; i < vehicleCount; i++)
    {
        Bus* b = dynamic_cast<Bus*>(vehicles[i]);
        if (b)
            fout << "BUS " << b->getVehicleId() << " "
                 << b->getModel() << " "
                 << b->getCapacity() << " "
                 << b->getBusType() << "\n";

        Van* v = dynamic_cast<Van*>(vehicles[i]);
        if (v)
            fout << "VAN " << v->getVehicleId() << " "
                 << v->getModel() << " "
                 << v->getCapacity() << " "
                 << v->getAC() << "\n";
    }
    fout.close();
}

void TransportManager::loadVehicles()
{
    ifstream fin("vehicles.txt");
    if (!fin) return;

    string type;
    while (fin >> type)
    {
        if (type == "BUS")
        {
            int id, cap; string model, busType;
            fin >> id >> model >> cap >> busType;
            vehicles[vehicleCount++] = new Bus(id, model, cap, busType);
        }
        else if (type == "VAN")
        {
            int id, cap; string model; bool ac;
            fin >> id >> model >> cap >> ac;
            vehicles[vehicleCount++] = new Van(id, model, cap, ac);
        }
    }
    fin.close();
}

void TransportManager::saveRoutes()
{
    ofstream fout("routes.txt");
    for (int i = 0; i < routeCount; i++)
    {
        fout << routes[i]->getRouteId()    << " "
             << routes[i]->getStartPoint() << " "
             << routes[i]->getEndPoint()   << " "
             << routes[i]->getDistance()   << "\n";
                }
    fout.close();
}

void TransportManager::loadRoutes()
{
    ifstream fin("routes.txt");
    if (!fin) return;

    int id; string s, e; double d;
    while (fin >> id >> s >> e >> d)
    {
        routes[routeCount++] = new Route(id, s, e, d);
    }
    fin.close();
}

void TransportManager::savePasses()
{
    ofstream fout("passes.txt");
    for (int i = 0; i < passCount; i++)
    {
        fout << passes[i]->getPassId()    << " "
             << passes[i]->getStudentId() << " "
             << passes[i]->getVehicleId() << " "
             << passes[i]->getRouteId()   << " "
             << passes[i]->isApproved()   << " "
             << passes[i]->isBillPaid()   << "\n";
    }
    fout.close();
}

void TransportManager::loadPasses()
{
    ifstream fin("passes.txt");
    if (!fin) return;

    int pid, sid, vid, rid; bool approved, paid;
    while (fin >> pid >> sid >> vid >> rid >> approved >> paid)
    {
        TransportPass* p = new TransportPass(pid, sid, vid, rid, 0);
        p->setApproval(approved);
        if (paid) p->payBill();
        passes[passCount++] = p;
    }
    fin.close();
}

void TransportManager::saveData()
{
    saveStudents();
    saveVehicles();
    saveRoutes();
    savePasses();
    cout << "\nAll data saved successfully!\n";
}

// ======================== DESTRUCTOR ========================

TransportManager::~TransportManager()
{
    for (int i = 0; i < studentCount; i++) delete students[i];
    for (int i = 0; i < adminCount; i++)   delete admins[i];
    for (int i = 0; i < vehicleCount; i++) delete vehicles[i];
    for (int i = 0; i < routeCount; i++)   delete routes[i];
    for (int i = 0; i < passCount; i++)    delete passes[i];

    delete[] students;
    delete[] admins;
    delete[] vehicles;
    delete[] routes;
    delete[] passes;
}

#include <iostream>
#include "TransportManager.h"
#include <limits>
#include <cctype>
using namespace std;

TransportManager tm;

int inputInt()
{
    int x;
    while (true)
    {
        cin >> x;

        if (!cin.fail())
            return x;

        cout << "Invalid input! Enter numbers only: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string inputName()
{
    string name;

    while (true)
    {
        cin >> name;

        bool valid = true;

        for (char c : name)
        {
            if (!isalpha(c))
            {
                valid = false;
                break;
            }
        }

        if (valid)
            return name;

        cout << "Only alphabets allowed: ";
    }
}
void studentMenu(Student* s);
void adminMenu(Admin* a);

int main()
{
    system("cls");
    int choice;

    do
    {
        cout <<"\n======================================\n";
        cout << "|   UNIVERSITY TRANSPORT SYSTEM      |\n";    
        cout << "======================================\n";
        cout << "1. Register as Student\n";
        cout << "2. Student Login\n";
        cout << "3. Admin Login\n";
        cout << "4. Exit\n";
        cout << "--------------------------------------\n";
        cout << "Enter choice: ";
         choice=inputInt();

        // ---- REGISTER ----
        if (choice == 1)
        {
            int id;
            string name, pass, dept;

            cout << "\n--- STUDENT REGISTRATION ---\n";
            cout << "Enter Student ID   : ";  id=inputInt();

            if (tm.studentIdExists(id))
            {
                cout << "\nError: Student ID already exists!\n";
                continue;
            }

            cout << "Enter Name         : ";  name=inputName();
            cout << "Enter Password     : "; cin >> pass;
            cout << "Enter Department   : "; cin >> dept;

            Student* s = new Student(id, name, pass, dept, false);
            tm.addStudent(s);
        }

        // ---- STUDENT LOGIN ----
        else if (choice == 2)
        {
            int id; string pass;

            cout << "\n--- STUDENT LOGIN ---\n";
            cout << "Enter Student ID : ";  id=inputInt();
            cout << "Enter Password   : "; cin >> pass;

            Student* s = tm.loginStudent(id, pass);

            if (s == nullptr)
            {
                cout << "\nLogin Failed! Invalid ID or Password.\n";
            }
            else
            {
                cout << "\nLogin Successful! Welcome, " << s->getName() << "!\n";
                studentMenu(s);
            }
        }

        // ---- ADMIN LOGIN ----
        else if (choice == 3)
        {
            int id; string pass;

            cout << "\n--- ADMIN LOGIN ---\n";
            cout << "Enter Admin ID   : ";  id=inputInt();
            cout << "Enter Password   : "; cin >> pass;

            Admin* a = tm.loginAdmin(id, pass);

            if (a == nullptr)
            {
                cout << "\nLogin Failed! Invalid ID or Password.\n";
            }
            else
            {
                cout << "\nLogin Successful! Welcome, " << a->getName() << "!\n";
                adminMenu(a);
            }
        }

        else if (choice == 4)
        {
            tm.saveData();
            cout << "\nGoodbye!\n";
        }
        else
        {
            cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

// ======================== STUDENT MENU ========================

void studentMenu(Student* s)
{
    int choice;

    do
    {
        cout << "\n  ======================================\n";
        cout << "  |            STUDENT MENU            |\n";
        cout << "  ======================================\n";
        cout << "1. View My Profile\n";
        cout << "2. View All Routes\n";
        cout << "3. View All Vehicles\n";
        cout << "4. Apply for Transport\n";
        cout << "5. View My Transport Pass\n";
        cout << "6. Pay My Bill\n";
        cout << "7. Cancel Registration\n";
        cout << "8. Logout\n";
        cout << "--------------------------------------\n";
        cout << "Enter choice: ";
         choice=inputInt();

        if (choice == 1)
        {
            s->display();
        }
        else if (choice == 2)
        {
            tm.displayAllRoutes();
        }
        else if (choice == 3)
        {
            tm.displayAllVehicles();
        }
        else if (choice == 4)
        {
            int rid, vid;
            double fee;

            cout << "\n--- APPLY FOR TRANSPORT ---\n";
            tm.displayAllRoutes();
            cout << "Enter Route ID   : "; cin >> rid;

            tm.displayAllVehicles();
            cout << "Enter Vehicle ID : "; cin >> vid;

            tm.applyTransport(s->getId(), rid, vid, fee);
        }
        else if (choice == 5)
        {
            tm.displayStudentPass(s->getId());
        }
        else if (choice == 6)
        {
            int pid;
            cout << "Enter your Pass ID: "; cin >> pid;
            tm.payBill(pid);
        }
        else if (choice == 7)
        {
            char confirm;
            cout << "\nAre you sure? (y/n): "; cin >> confirm;
            if (confirm == 'y' || confirm == 'Y')
            {
                tm.cancelTransport(s->getId());
            }
        }
        else if (choice == 8)
        {
            cout << "\nLogged out successfully.\n";
        }
        else
        {
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 8);
}

// ======================== ADMIN MENU ========================

void adminMenu(Admin* a)
{
    int choice;

    do
    {
        cout << "\n  ======================================\n";
        cout << "  |             ADMIN MENU             |\n";
        cout << "  ======================================\n";
        cout << "1.  View All Students\n";
        cout << "2.  View All Vehicles\n";
        cout << "3.  View All Routes\n";
        cout << "4.  View All Applications\n";
        cout << "5.  Add Bus\n";
        cout << "6.  Add Van\n";
        cout << "7.  Remove Vehicle\n";
        cout << "8.  Add Route\n";
        cout << "9.  Assign Vehicle to Route\n";
        cout << "10. Approve Transport Request\n";
        cout << "11. Reject Transport Request\n";
        cout << "12. Apply Late Fine\n";
        cout << "13. Generate Report\n";
        cout << "14. Save Data\n";
        cout << "15. Logout\n";
        cout << "--------------------------------------\n";
        cout << "Enter choice: ";
         choice=inputInt();

        if (choice == 1)
        {
            tm.displayAllStudents();
        }
        else if (choice == 2)
        {
            tm.displayAllVehicles();
        }
        else if (choice == 3)
        {
            tm.displayAllRoutes();
        }
        else if (choice == 4)
        {
            tm.displayAllPasses();
        }
        else if (choice == 5)
        {
            int id, cap; string model, type;

            cout << "\n--- ADD BUS ---\n";
            cout << "Vehicle ID  : "; cin >> id;

            if (tm.vehicleIdExists(id))
            {
                cout << "\nError: Vehicle ID already exists!\n";
                continue;
            }

            cout << "Model       : "; cin >> model;
            cout << "Capacity    : "; cin >> cap;
            cout << "Type (AC/NonAC/Mini): "; cin >> type;

            tm.addVehicle(new Bus(id, model, cap, type));
        }
        else if (choice == 6)
        {
            int id, cap; string model; bool ac;
            int acInput;

            cout << "\n--- ADD VAN ---\n";
            cout << "Vehicle ID  : "; cin >> id;

            if (tm.vehicleIdExists(id))
            {
                cout << "\nError: Vehicle ID already exists!\n";
                continue;
            }

            cout << "Model       : "; cin >> model;
            cout << "Capacity    : "; cin >> cap;
            cout << "AC (1=Yes, 0=No): "; cin >> acInput;
            ac = (acInput == 1);

            tm.addVehicle(new Van(id, model, cap, ac));
        }
        else if (choice == 7)
        {
            int id;
            cout << "\nEnter Vehicle ID to remove: "; cin >> id;
            tm.removeVehicle(id);
        }
        else if (choice == 8)
        {
            int id; string s, e; double d;

            cout << "\n--- ADD ROUTE ---\n";
            cout << "Route ID    : "; cin >> id;

            if (tm.routeIdExists(id))
            {
                cout << "\nError: Route ID already exists!\n";
                continue;
            }

            cout << "Start Point : "; cin >> s;
            cout << "End Point   : "; cin >> e;
            cout << "Distance(km): "; d=inputInt();
 

            tm.addRoute(new Route(id, s, e, d));
        }
        else if (choice == 9)
        {
            int rid, vid;
            cout << "\n--- ASSIGN VEHICLE TO ROUTE ---\n";
            tm.displayAllRoutes();
            cout << "Enter Route ID  : "; cin >> rid;
            tm.displayAllVehicles();
            cout << "Enter Vehicle ID: "; cin >> vid;
            tm.assignVehicleToRoute(rid, vid);
        }
        else if (choice == 10)
        {
            int pid;
            cout << "\nEnter Pass ID to approve: "; cin >> pid;
            tm.approveRequest(pid);
        }
        else if (choice == 11)
        {
            int pid;
            cout << "\nEnter Pass ID to reject: "; cin >> pid;
            tm.rejectRequest(pid);
        }
        else if (choice == 12)
        {
            int pid; double fine;
            cout << "\n--- APPLY LATE FINE ---\n";
            cout << "Enter Pass ID    : "; cin >> pid;
            cout << "Enter Fine Amount: Rs. "; cin >> fine;
            tm.applyLateFine(pid, fine);
        }
        else if (choice == 13)
        {
            tm.generateReports();
        }
        else if (choice == 14)
        {
            tm.saveData();
        }
        else if (choice == 15)
        {
            cout << "\nLogged out successfully.\n";
        }
        else
        {
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 15);
}

