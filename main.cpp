//Morgan Sansone
//CS303
//Assignment 2

#include <iostream>
#include "Employee.h"

int main() {
    // Create instances of Professional and Nonprofessional employees
    Professional profEmployee(10000.0, 20);  // Monthly salary of $10,000, 20 vacation days
    Nonprofessional nonProfEmployee(15.0, 45);  // Hourly rate of $15, worked 45 hours

    // Calculate and display weekly salary, health care contributions, and vacation days
    cout << "Professional Employee: Weekly Salary $" << profEmployee.calculateWeeklySalary()
              << ", Health Care Contributions $" << profEmployee.computeHealthCareContributions()
              << ", Vacation Days Earned " << profEmployee.computeVacationDays() << endl;

    cout << "Nonprofessional Employee: Weekly Salary $" << nonProfEmployee.calculateWeeklySalary()
              << ", Health Care Contributions $" << nonProfEmployee.computeHealthCareContributions()
              << ", Vacation Days Earned " << nonProfEmployee.computeVacationDays() << endl;

    return 0;
}
