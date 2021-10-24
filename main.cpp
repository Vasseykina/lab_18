#include <iostream>
#include <fstream>
#include "src/PhoneBook.h"


using namespace std;

int main() {
    PhoneBook b;    b.load("../phonebook.txt");
    b.erase("Harry Potter");
    b.add(make_tuple("James Potter", "783997232", "16"));
    b.save("../phonebook.txt");
    b.saveBin("../phonebin");
    return 0;
}
