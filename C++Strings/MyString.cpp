
// CS251 Data Structures
// String Implementation
// IMPORTANT: Do not use any of the functions in the string C runtime library
// Example. Do not use strcpy, strcmp, etc. Implement your own

// IMPORTANT: See the MyString.h file for a description of
// what each method needs to do.

#include <stdio.h>
#include <string.h>
#include "MyString.h"
#include <map>
#include <sstream>
using namespace std;
// My own implementation of strlen
int MyString::slength(const char *s) const
{
  //TODO
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}

// Initialize _s. Allocate memory for _s and copy s into _s
void MyString::initialize(const char * s)
{
  //TODO
	_s = new char[slength(s) + 1];
	/*int i = 0;
	while (1) {
		_s[i] = s[i];
		if (_s[i] == '\0') break;
		i++; 
	}*/
	unsigned i;
	for (i = 0; s[i] != '\0'; ++i) {
		_s[i] = s[i];
	}
	_s[i] = '\0';
}

// Create a MyString from a C string
MyString::MyString(const char * s)
{
  //TODO
	initialize(s);
}

// Create a MyString from a copy of another string
MyString::MyString(const MyString &s)
{
  //TODO
	initialize(s._s);
}

// Create a MyString with an empty string
MyString::MyString()
{
  //TODO
	initialize("");
}

// Assignment operator. Without this operator the assignment is
// just a shallow copy that will copy the pointer _s. If the original _s
// goes away then the assigned _s will be a dangling reference.
MyString & MyString::operator = (const MyString & other) {
  //TODO
	if (other.length() != 0) {
		delete [] _s;
	}
	initialize(other._s);
	return *this;

}

// Obtain a substring of at most n chars starting at location i
// if i is larger than the length of the string return an empty string.
MyString MyString::substring(int i, int n)
{
  //TODO
	if (i > slength(_s)) {
		MyString result("");
		return result;
	}
	char * stringFromIndex = new char[n + 1];
	
	int j;
	for (j = 0; j < n; j++) {
		stringFromIndex[j] = _s[i + j];
	}
	stringFromIndex[j] = '\0';
	const char * res = stringFromIndex;
	MyString result(stringFromIndex);
	return result;
}

// Remove at most n chars starting at location i
void MyString::remove(int i, int n)
{
  //TODO
	for (int j = i; j < slength(_s); j++) {
		_s[j] = _s[j + n];
	}
}

// Return true if strings "this" and s are equal
bool MyString::operator == (const MyString & s)
{
  //TODO
    if (slength(this->_s) != slength(s._s)) {
    	return false;
    }

    for (int i = 0; i < slength(this->_s); i++) {
    	if (this->_s[i] == s._s[i]) continue;
    	else return false;
    }
    return true;
}


// Return true if strings "this" and s are not equal
bool MyString::operator != (const MyString &s)
{
  //TODO
    if (slength(this->_s) != slength(s._s)) {
    	return true;
    }

    for (int i = 0; i < slength(this->_s); i++) {
    	if (this->_s[i] == s._s[i]) continue;
    	else return true;
    }
    return false;
}

// Return true if string "this" and s is less or equal
int helper(char *s1, char *s2) {
	int i = 0;
	while ((s1[i]!='\0' || s2[i]!= '\0')) {
	    if (s1[i] > s2[i])
	        return 1;
	    if (s1[i] < s2[i])
	        return -1;
	    i++;
	}
	return 0;
}

bool MyString::operator <= (const MyString &s)
{
  //TODO
	int n = helper(_s, s._s);
	if (n == 0) {
		return true;
	}
	if (n == -1) {
		return true;
	}
	return false;
}

// Return true if string "this" and s is less or equal
bool MyString::operator > (const MyString &s)
{
  //TODO
	int n = helper(_s, s._s);
	if (n == 1) {
		return true;
	}
	return false;
}

// Return character at position i
char MyString::operator [] (int i)
{
  //TODO
	return this->_s[i];
}

// Return C representation of string
const char * MyString::cStr()
{
  //TODO
	return _s;
}

// Get string length of this string.
int MyString::length() const
{
  //TODO
	return slength(this->_s);
}

// Destructor. Deallocate the space used by _s
MyString::~MyString()
{
  //TODO
	delete [] _s;
}

// Concatanate two strings (non member method)
MyString operator + (const MyString &s1, const MyString &s2)
{
  //TODO
	int len1 = s1.length();
	int len2 = s2.length();
	char * combination = new char[len1+len2];
	int i = 0;
	for (; i < len1; i++) {
		combination[i] = s1._s[i]; 
	}
	for (int j = 0; j < len2; j++, i++) {
		combination[i] = s2._s[j];
	}
	combination[i]='\0';
	MyString resultstring(combination);
	return resultstring;
	
}

/* Break a string into substrings of letters, e.g "A dog and a hyper-sphere"
breaks into <"A", "dog", "and", "a", "hyper", "sphere">.  The input is a string
and the output is a vector of strings. */
std::vector<MyString> words (MyString s) {
  //TODO
	vector<MyString> vec;
	const char * str = s.cStr();

	for (int i = 0, j = 0; i <= s.length(); i++) {
		if (str[i] == ' ' || str[i] == '-' || str[i] == '\0') {
			int count = i - j;
			//printf("i = %d, j = %d\n", i, j);
			char * tmp = new char[count + 1];
			for (int k = j, p = 0; p < count; k++, p++) {
				tmp[p] = str[k];
			}
			//printf("count = %d\n", count);
			
			tmp[count] = '\0';
			
			//printf("vec = %s\n", tmp);
			MyString vecString(tmp);
			vec.push_back(vecString);
			j = i + 1;
			delete [] tmp;
		}
	}
	return vec;
}

/*
Convert a roman numberal into a number, e.g. "CLXIV" converts to 164.  The
input is a roman numeral expressed as a string whose characters are "I", "V",
"X", "L", and "C".  The output is a positive integer.
*/
unsigned int roman (MyString s) {
  //TODO

	unsigned int result = 0;
	map <char, int> number;

	number['C'] = 100;
	number['L'] = 50;
	number['X'] = 10;
	number['V'] = 5;
	number['I'] = 1;

	const char * str = s.cStr();
	for (int i = 0; i < s.length() - 1; i++) {
		if (number[str[i]] < number[str[i + 1]]) {
            result -= number[str[i]];
        }
        else {
            result += number[str[i]];
        }
    }
    result += number[str[s.length() - 1]];
  	return result;
}

