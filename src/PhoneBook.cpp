//
// Created by User on 30.09.2021.
//

#include "PhoneBook.h"
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/map.hpp>

using namespace std;

void PhoneBook::add(const std::tuple<std::string, std::string, std::string> &t) {
    book[get<0>(t)] = get<1>(t) + ' ' + get<2>(t);
}

void PhoneBook::erase(const std::string &name) {
    if (book.find(name) != book.end())
        book.erase(book.find(name));
}

std::string PhoneBook::find(const std::string &name) {
    return book.at(name);
}

void PhoneBook::load(const std::string &filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        throw 42;
    }
    string line;
    while (!in.eof()) {
        getline(in, line);
        auto position = line.find(':');
        if (position == string::npos) continue;
        string name = line.substr(0, position);
        auto position2 = line.find_last_of(':');
        string phone = line.substr(position + 1, position2);
        string age = line.substr(position2 + 1, line.size());
        add(make_tuple(name, phone, age));
    }

}

void PhoneBook::save(const string &filename) {
    ofstream out(filename);
    if (!out.is_open()) {
        throw 42;
    }
    for (auto &item: book) {
        out << item.first << ":" << item.second << endl;
    }
}

void PhoneBook::saveBin(const string &filename) {
    ofstream f(filename.c_str(), ios::binary);

    boost::archive::binary_oarchive oa(f);
    oa << book;
}


