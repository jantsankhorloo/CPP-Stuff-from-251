
// CS251 Data Structures
// String Implementation

#include <vector>

class MyString {
  // Stores the string in C string format
  char * _s;
  
 protected:
  
  // My own implementation of strlen
  int slength(const char *s) const;

  // Initialize _s. Allocate memory for _s and copy s into _s
  void initialize(const char * s);
  
 public:
  // Create a MyString from a C string
  MyString(const char * s);
  
  // Create a MyString from a copy of another string
  MyString(const MyString &s);

  // Create a MyString with an empty string
  MyString();

  // Assignment operator. Without this operator the assignment is
  // just a shallow copy that will copy the pointer _s. If the original _s
  // goes away then the assigned _s will be a dangling reference.
  MyString & operator = (const MyString & other);

  // Obtain a substring of at most n chars starting at location i
  // if i is larger than the length of the string return an empty string.
  MyString substring(int i, int n);

  // Remove at most n chars starting at location i
  void remove(int i, int n);

  // Return true if strings "this" and s are equal
  bool operator == (const MyString &s);

  // Return true if strings "this" and s are not equal
  bool operator != (const MyString &s);

  // Return true if string "this" is less or equal to s
  bool operator <= (const MyString &s);

  // Return true if string "this" is greater than s
  bool operator > (const MyString &s);

  // Return character at position i
  char operator [](int i);

  // Return C representation of string
  const char * cStr();

  // Get string length of this string.
  int length() const;
  
  // Destructor. Deallocate the space used by _s
  ~MyString();

  // Needed to allow the operator + to use the MyString member variables.
  friend MyString operator + (const MyString &s1, const MyString &s2);


};

// Concatanate two strings (non member method)
MyString operator + (const MyString &s1, const MyString &s2);

std::vector<MyString> words (MyString s);

unsigned int roman (MyString s);


