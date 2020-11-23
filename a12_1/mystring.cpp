/*
 Trang Hoang
 CS110B
 Dave Harden
 11/17/20
 mystring.hpp
 
 Assignment 12.1
 
 Assignment is extension of Assignment 11.1 to write a string class. To avoid conflicts
 with other similarly named classes, we will call our version MyString. This object is
 designed to make working with sequences of characters a little more convenient and less
 error-prone than handling raw c-strings, (although it will be implemented as a c-string
 behind the scenes). The MyString class will handle constructing strings, reading/printing,
 and accessing characters. In addition, the MyString object will have the ability to make a
 full deep-copy of itself when copied.
 
 Created by nyccowgirl on 11/17/20.
 Copyright © 2020 nyccowgirl. All rights reserved.
*/

#include "mystring.hpp"
#include <iostream>
#include <cassert>
using namespace std;

namespace cs_mystring {

/*
  
 Class Invariant: a MyString object has one char data member - cstring, which stores an
 array of characters.
    
*/

    MyString::MyString() {
        cstring = new char(1);
        strcpy(cstring, "");
    }






    MyString::MyString(const char *inCstring) {
        cstring = new char(strlen(inCstring) + 1);
        strcpy(cstring, inCstring);
    }






    MyString::MyString(const MyString &str) {
        cstring = new char(str.length() + 1);
        strcpy(cstring, str.cstring);
    }






    MyString::~MyString() {
        delete [] cstring;
    }






    int MyString::length() const {
        return (int)strlen(cstring);
    }






    char MyString::operator[](int index) const {
        assert(index >= 0 && index < strlen(cstring));
        return cstring[index];
    }






    char& MyString::operator[](int index) {
        assert(index >= 0 && index < strlen(cstring));
        return cstring[index];
    }






    MyString MyString::operator=(const char *inCstring) {
        if (strcmp(cstring, inCstring) != 0) {
            delete [] cstring;
            cstring = new char[strlen(inCstring) + 1];
            strcpy(cstring, inCstring);
        }
        return *this;
    }






    MyString MyString::operator=(const MyString &right) {
        if (this != &right){
            delete [] cstring;
            cstring = new char[strlen(right.cstring) + 1];
            strcpy(cstring, right.cstring);
        }
        return *this;
    }





    MyString MyString::operator+=(const char *inCstring) {
        *this = *this + inCstring;
        return *this;
    }






    MyString MyString::operator+=(const MyString &right) {
        *this = *this + right;
        return *this;
    }






    void MyString::read(std::istream &in, char deliminator) {
        char temp[MyString::MAX_SIZE + 1];
        in.getline(temp, MyString::MAX_SIZE, deliminator);
        delete [] cstring;
        cstring = new char[strlen(temp) + 1];
        strcpy(cstring, temp);
    }






    MyString operator+(const MyString &left, const MyString &right) {
        MyString temp = new char(left.length() + right.length() + 1);
        strcpy(temp.cstring, left.cstring);
        strcat(temp.cstring, right.cstring);
        return temp;
    }






    bool operator<(const MyString &left, const MyString &right) {
        return strcmp(left.cstring, right.cstring) < 0;
    }






    bool operator<=(const MyString &left, const MyString &right) {
        return strcmp(left.cstring, right.cstring) <= 0;
    }






    bool operator>(const MyString &left, const MyString &right) {
        return strcmp(left.cstring, right.cstring) > 0;
    }






    bool operator>=(const MyString &left, const MyString &right) {
        return strcmp(left.cstring, right.cstring) >= 0;
    }






    bool operator==(const MyString &left, const MyString &right) {
        return strcmp(left.cstring, right.cstring) == 0;
    }






    bool operator!=(const MyString &left, const MyString &right) {
        return strcmp(left.cstring, right.cstring) != 0;
    }






    istream &operator>>(istream &in, MyString &right) {
        while (isspace(in.peek())){
            in.ignore();
        }
        
        char temp[MyString::MAX_SIZE + 1];
        in >> temp;
        delete [] right.cstring;
        right.cstring = new char[strlen(temp) + 1];
        strcpy(right.cstring, temp);
        return in;
    }






    ostream &operator<<(ostream &out, const MyString &right) {
        out << right.cstring;
        return out;
    }
}
