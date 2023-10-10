#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee {
public:
    virtual ~Employee() {}

    // Abstract functions to be implemented by derived classes
    virtual double calculateWeeklySalary() const = 0;
    virtual double computeHealthCareContributions() const = 0;
    virtual int computeVacationDays() const = 0;
};

class Professional : public Employee {
private:
    double monthlySalary;
    int vacationDays;

public:
    Professional(double salary, int days);

    double calculateWeeklySalary() const override;
    double computeHealthCareContributions() const override;
    int computeVacationDays() const override;
};

class Nonprofessional : public Employee {
private:
    double hourlyRate;
    int workedHours;

public:
    Nonprofessional(double rate, int hours);

    double calculateWeeklySalary() const override;
    double computeHealthCareContributions() const override;
    int computeVacationDays() const override;
};

#endif // EMPLOYEE_H
