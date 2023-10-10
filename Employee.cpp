#include "Employee.h"

// Professional Class Implementation

Professional::Professional(double salary, int days) : monthlySalary(salary), vacationDays(days) {}

double Professional::calculateWeeklySalary() const {
    // Assuming a month has 4 weeks
    return monthlySalary / 4.0;
}

double Professional::computeHealthCareContributions() const {
    // Implement health care contributions logic for professional employees
    return monthlySalary * 0.2; // 20% of monthly salary
}

int Professional::computeVacationDays() const {
    // Implement vacation days calculation logic for professional employees
    return vacationDays / 12; // 1/12th of annual vacation days per month
}


// Nonprofessional Class Implementation

Nonprofessional::Nonprofessional(double rate, int hours) : hourlyRate(rate), workedHours(hours) {}

double Nonprofessional::calculateWeeklySalary() const {
    // Assuming a standard work week has 40 hours
    if (workedHours <= 40) {
        return hourlyRate * workedHours;
    } else {
        // Calculate overtime for hours worked beyond 40 (assuming 1.5x overtime rate)
        return hourlyRate * 40 + hourlyRate * 1.5 * (workedHours - 40);
    }
}

double Nonprofessional::computeHealthCareContributions() const {
    // Implement health care contributions logic for nonprofessional employees
  return hourlyRate * workedHours * 0.10; // 10% of total earnings
}

int Nonprofessional::computeVacationDays() const {
    // Implement vacation days calculation logic for nonprofessional employees
  return workedHours / 40; // 1 day of vacation for every 40 hours worked
}
