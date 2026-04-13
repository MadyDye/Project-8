#include "PeopleDB.h"
#include <iostream>
using namespace std;

PeopleDB::PeopleDB(string filename) {
    ifstream inFile(filename);
    People p;

    while (inFile >> p) {
        db.insert(p);
    }
}

void PeopleDB::addPerson(const People& p) {
    db.insert(p);
}

void PeopleDB::removePerson(const People& p) {
    db.remove(p);
}

bool PeopleDB::searchPerson(const People& p) {
    return db.contains(p);
}

void PeopleDB::modifyPerson(const People& oldP, const People& newP) {
    if (db.contains(oldP)) {
        db.remove(oldP);
        db.insert(newP);
    }
}

void PeopleDB::displayPreorder(void visit(People&)) {
    db.preorderTraverse(visit);
}

void PeopleDB::displayInorder(void visit(People&)) {
    db.inorderTraverse(visit);
}
