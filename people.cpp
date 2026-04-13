#include "People.h"

People::People(string n, Date d) : name(n), birthday(d) {}

void People::setName(string n) { name = n; }
void People::setBirthday(Date d) { birthday = d; }

string People::getName() const { return name; }
Date People::getBirthday() const { return birthday; }

bool People::operator==(const People& other) const {
    return name == other.name;
}

bool People::operator<(const People& other) const {
    return name < other.name;
}

istream& operator>>(istream& in, People& p) {
    in >> p.name >> p.birthday;
    return in;
}

ostream& operator<<(ostream& out, const People& p) {
    out << p.name << " " << p.birthday;
    return out;
}
