/*
 Trang Hoang
 CS110B
 Dave Harden
 11/17/20
 mystring.hpp
 
 Assignment 12.1
 
 Write a string class. To avoid conflicts with other similarly named classes, we will call
 our version MyString. This object is designed to make working with sequences of characters
 a little more convenient and less error-prone than handling raw c-strings, (although it
 will be implemented as a c-string behind the scenes). The MyString class will handle
 constructing strings, reading/printing, and accessing characters. In addition, the
 MyString object will have the ability to make a full deep-copy of itself when copied.
 
 Created by nyccowgirl on 11/17/20.
 Copyright © 2020 nyccowgirl. All rights reserved.
*/

#ifndef mystring_hpp
#define mystring_hpp

#include <iostream>

namespace cs_mystring {

/*
 
 The MyString class can be used to create objects that store a cstring. The following
 functions are available:

 MyString();
  post: The calling object has been created and initialized to empty MyString object.
 
 MyString(const char *inCstring);
  post: The calling object has been created and initialized so that the cstring is the
        inCstring parameter.
 
 MyString(const MyString &str);
  post: The calling object has been created and initialized so that the cstring is the value
        of MyString str parameter.
 
 ~MyString();
  post: Destructor for the class.
 
 int length() const;
  post: Returns the length of MyString object.
 
 char operator[](int index) const;
  pre: Paramenter must be 0 or positive value.
  post: Returns the character at the index specified of the calling object. If index is not
        between 0 and one less than the length of the calling object, the program is
        aborted.
 
 char& operator[](int index);
  pre: Parameter must be 0 or positive value.
  post: Returns reference to a variable at the index specified of the calling object. If the
        index is not between 0 and one less than the length of the calling object, the
        program is aborted.
 
 MyString operator=(const char *inCstring);
  post: Returns the value of inCstring that was assigned to the calling object.
 
 MyString operator=(const MyString &right);
  post: Returns the value of the MyString object that was assigned to the calling object.
 
 MyString operator+=(const char *inCstring);
  post: Returns the value of the calling object combined with the value of inCstring that
        was assigned to the calling object.
 
 MyString operator+=(const MyString &right);
  post: Returns the value of the calling object combined with the MyString object that was
        assigned to the calling object.
 
 void read(istream &in, char deliminator);
  pre: Client programmer specifies appropriate deliminating character.
  post: Uses in.getline() function to read input into non-dynamic array and copies it to
        data member of a MyString object.
 
 friend MyString operator+(const MyString &left, const MyString &right);
  post: The calling object is created and initialized to combine the MyString of the
        parameter "left" with the MyString of the parameter "right".
 
 friend bool operator<(const MyString &left, const MyString &right);
  post: Returns true if the MyString of the parameter "left" is less than the MyString of
        the parameter "right" based on ASCII values. Otherwise, returns false.
 
 friend bool operator<=(const MyString &left, const MyString &right);
  post: Returns true if the MyString of the parameter "left" is less than or equal to the
        MyString of the parameter "right" based on ASCII values. Otherwise, returns false.
 
 friend bool operator>(const MyString &left, const MyString &right);
  post: Returns true if the MyString of the parameter "left" is greater than the MyString of
        the parameter "right" based on ASCII values. Otherwise, returns false.
 
 friend bool operator>=(const MyString &left, const MyString &right);
  post: Returns true if the MyString of the parameter "left" is greater than or equal to the
        MyString of the parameter "right" based on ASCII values. Otherwise, returns false.

 friend bool operator==(const MyString &left, const MyString &right);
  post: Returns true if the MyString of the parameter "left" is equal to the MyString of
        the parameter "right" based on ASCII values. Otherwise, returns false.

 friend bool operator!=(const MyString &left, const MyString &right);
  post: Returns true if the MyString of the parameter "left" is not equal to the MyString
        of the parameter "right". Otherwise, returns false.
 
 friend std::istream &operator>>(std::istream &in, MyString &right);
  post: Reads a line from file, and converts each line into a MyString object.

 friend std::ostream &operator<<(std::ostream &out, const MyString &right);
  post: The calling object has been printed to the console window in the formats of string.
         
*/

    class MyString {
        public:
            static const int MAX_SIZE = 127;
            MyString();
            MyString(const char *inCstring);
            MyString(const MyString &str);
            ~MyString();
            int length() const;
            char operator[](int index) const;
            char& operator[](int index);
            MyString operator=(const char *inCstring);
            MyString operator=(const MyString &right);
            MyString operator+=(const char *inCstring);
            MyString operator+=(const MyString &right);
            void read(std::istream &in, char deliminator);
            friend MyString operator+(const MyString &left, const MyString &right);
            friend bool operator<(const MyString &left, const MyString &right);
            friend bool operator<=(const MyString &left, const MyString &right);
            friend bool operator>(const MyString &left, const MyString &right);
            friend bool operator>=(const MyString &left, const MyString &right);
            friend bool operator==(const MyString &left, const MyString &right);
            friend bool operator!=(const MyString &left, const MyString &right);
            friend std::istream &operator>>(std::istream &in, MyString &right);
            friend std::ostream &operator<<(std::ostream &out, const MyString &right);

        private:
            char *cstring;
    };
}



#endif /* mystring_hpp */


/*
 ----- Testing basic String creation & printing
 string [0] = Wow
 string [1] = C++ is neat!
 string [2] =
 string [3] = a-z

 ----- Now reading MyStrings from file

 ----- first, word by word
 Read string = The
 Read string = first
 Read string = time
 Read string = we
 Read string = will

 Read string = read
 Read string = individual
 Read string = words,
 Read string = next
 Read string = we
 Read string = read
 Read string = whole
 Read string = lines

 ----- now, line by line
 Read string = The  first  time  we  will
 Read string =     read individual words, next
 Read string = we read whole lines

 ----- Testing access to characters (using const)
 Whole string is abcdefghijklmnopqsrtuvwxyz
 now char by char: abcdefghijklmnopqsrtuvwxyz
 ----- Testing access to characters (using non-const)
 Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

 ----- Testing relational operators between MyStrings
 Comparing app to apple
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true
 Comparing apple to
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true
 Comparing  to Banana
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true
 Comparing Banana to Banana
     Is left < right? false
     Is left <= right? true
     Is left > right? false
     Is left >= right? true
     Does left == right? true
     Does left != right ? false

 ----- Testing relations between MyStrings and char *
 Comparing he to hello
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true
 Comparing why to wackity
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true

 ----- Testing concatentation on MyStrings
 outrageous + milk = outrageousmilk
 milk +  = milk
  + cow = cow
 cow + bell = cowbell

 ----- Testing concatentation between MyString and char *
 abcde + XYZ = abcdeXYZ
 XYZ + abcde = XYZabcde

 ----- Testing shorthand concat/assign on MyStrings
 who += what = whowhatandwhowhat
 what += WHEN = whatWHENandwhatWHEN
 WHEN += Where = WHENWhereandWHENWhere
 Where += why = WherewhyandWherewhy

 ----- Testing shorthand concat/assign using char *
 I love  += programming = I love programming

 ----- Testing copy constructor and operator= on MyStrings
 original is cake, copy is fake
 original is cake, copy is fake
 after self assignment, copy is Copy Cat
 Testing pass & return MyStrings by value and ref
 after calling Append, sum is BinkyBoo
 val is winky
 after assign,  val is BinkyBoo
 Program ended with exit code: 0
 */
