#include "Date.h"

Date::Date(int m, int d, int y) : month(m), day(d), year(y) {}

void Date::setDate(int m, int d, int y) {
    month = m; day = d; year = y;
}

int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }

bool Date::operator==(const Date& other) const {
    return (month == other.month && day == other.day && year == other.year);
}

istream& operator>>(istream& in, Date& d) {
    in >> d.month >> d.day >> d.year;
    return in;
}

ostream& operator<<(ostream& out, const Date& d) {
    out << d.month << " " << d.day << " " << d.year;
    return out;
}
