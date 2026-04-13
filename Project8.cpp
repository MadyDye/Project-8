#include <iostream>
#include "PeopleDB.h"
using namespace std;

void toScreen(People& p);

int main() {
    string filename;
    cout << "Enter input file: ";
    cin >> filename;

    PeopleDB db(filename);

    int choice;
    do {
        cout << "\n1. Add\n2. Remove\n3. Modify\n4. Search\n5. Display\n6. Display Sorted\n7. Quit\n";
        cin >> choice;

        People p, newP;

        switch(choice) {
        case 1:
            cin >> p;
            db.addPerson(p);
            break;

        case 2:
            cin >> p;
            db.removePerson(p);
            break;

        case 3:
            cin >> p;
            cin >> newP;
            db.modifyPerson(p, newP);
            break;

        case 4:
            cin >> p;
            if (db.searchPerson(p))
                cout << "Found\n";
            else
                cout << "Not Found\n";
            break;

        case 5:
            db.displayPreorder(toScreen);
            break;

        case 6:
            db.displayInorder(toScreen);
            break;

        }
    } while(choice != 7);

    return 0;
}
