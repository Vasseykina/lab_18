//
// Created by User on 30.09.2021.
//

#ifndef LABA_19_PHONEBOOK_H
#define LABA_19_PHONEBOOK_H

#include <map>
#include <iostream>
#include <string>

class PhoneBook {

private:
    std::map<std::string, std::string> book;
public:
    void add(const std::tuple<std::string, std::string, std::string> &t);

    void erase(const std::string &name);

    std::string find(const std::string &name);

    void load(const std::string &filename);

    void save(const std::string &filename);

    void saveBin(const std::string &filename);
};


#endif //LABA_19_PHONEBOOK_H
