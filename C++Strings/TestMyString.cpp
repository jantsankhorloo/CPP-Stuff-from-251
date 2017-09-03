
//
// CS251 Data Structures
// test for MyString class
//

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>

#include "MyString.h"

void
test1() {
  const char *s1 = "John Purdue";
  char * s2 = strdup(s1);
  MyString ms1(s2);
  *s2 = '\0';
  assert( !strcmp(ms1.cStr(),s1 ));
  printf("s1=\"%s\"\n", ms1.cStr());
  printf("Test 1 passed\n");
}

void
test2() {
  const char *s1 = "John Purdue";
  char * s2 = strdup(s1);
  MyString ms1(s2);
  MyString ms2(ms1);
  *s2 = '\0';
  assert( !strcmp(ms2.cStr(),s1 ));
  printf("s1=\"%s\"\n", ms2.cStr());
  printf("Test 2 passed\n");
}

void
test3() {
  const char *s1 = "John Purdue";
  char * s2 = strdup(s1);
  MyString ms1(s2);
  MyString ms2(ms1);
  *s2 = '\0';
  assert( ms2.length() == strlen(s1) );
  printf("len=%d\n", ms2.length());
  printf("Test 3 passed\n");
}

void
test4() {
  MyString ms1;
  assert( ms1.cStr()[0] == 0 );
  printf("str=\"%s\"\n", ms1.cStr());
  printf("Test 4 passed\n");
}

void
test5() {
  const char *s1 = "John Purdue";
  char * s2 = strdup(s1);
  MyString ms1(s2);
  *s2 = '\0';
  MyString ms2;
  ms2 = ms1.substring(2,3);
  printf("substr(2,3) of \"%s\"=\"%s\"\n", ms1.cStr(), ms2.cStr());
  assert(!strcmp(ms2.cStr(),"hn "));
  printf("Test 5 passed\n");
}

void
test6() {
  const char *s1 = "John Purdue";
  char * s2 = strdup(s1);
  MyString ms1(s2);
  *s2 = '\0';
  MyString ms2;
  ms2 = ms1.substring(7,8);
  printf("substr(7,8) of \"%s\"=\"%s\"\n", ms1.cStr(), ms2.cStr());
  assert(!strcmp(ms2.cStr(),"rdue")); 
  printf("Test 6 passed\n");
}

void
test7() {
  const char *s1 = "John Purdue";
  char * s2 = strdup(s1);
  MyString ms1(s2);
  *s2 = '\0';
  ms1.remove(2,3);
  printf("remove(2,3) of \"%s\"=\"%s\"\n", s1, ms1.cStr());
  assert(!strcmp(ms1.cStr(),"JoPurdue"));
  printf("Test 7 passed\n");
}

void
test8() {
  MyString ms1("John ");
  MyString ms2("Purdue");
  MyString ms3("John ");
  
  assert(ms1!=ms2);
  assert(ms1==ms3);
  printf("Test 8 passed\n");
}

void
test9() {
  MyString ms1("John ");
  MyString ms2("Purdue");
  MyString ms3("Jo");
  
  assert(ms1<=ms2);
  assert(!(ms2<=ms1));
  assert(ms3<=ms2);
  assert(!(ms2<=ms3));
  assert(ms1<=ms1);
  printf("Test 9 passed\n");
}

void
test10() {
  MyString ms1("John ");
  MyString ms2(" needs");
  MyString ms3;

  ms3 = ms1 + "Purdue" + ms2 + " you.";

  printf("ms3=%s\n", ms3.cStr());
  assert(!strcmp(ms3.cStr(), "John Purdue needs you."));
  
  printf("Test 10 passed\n");
}

void
test11() {
  MyString ms1("John Purdue");
  assert(ms1[6]=='u');
  printf("Test 11 passed\n");
}

void
test12() {
	MyString ms1("A dog and a hyper-sphere");
	std::vector<MyString> ret = words(ms1);
	MyString ms2;
	for(int i = 0; i < ret.size(); i++) {
		MyString ms3(ret[i].cStr());
		ms2 = ms2 + ms3;
    //printf("ms2 = %s\n", ms2.cStr());
	
  }
  
  //printf("final = %s\n", ms2.cStr());
  //MyString ms4("Adogandahypersphere");
  //printf("ms2 = %d, ms4 = %d\n", ms2.length(), ms4.length());

  //for (int i = 0; i < ret.size(); i++) {
    //printf("vector element = %s, size = %d\n", ret[i].cStr(), ret[i].length());
  //}
	
  assert(!strcmp(ms2.cStr(), "Adogandahypersphere"));
	printf("Test 12 passed\n");
}

void
test13() {
	MyString ms1("VI");
	unsigned int n = roman(ms1);
	assert(n == 6);
	MyString ms2("IX");
	n = roman(ms2);
	assert(n == 9);
	MyString ms3("CLXIV");
	n = roman(ms3);
	assert(n == 164);
	printf("Test 13 passed\n");
}

void
usage()
{
  // Print usage
  fprintf(stderr, "TestMyString test1|test2|....|test11\n");
}

int
main( int argc, char ** argv) {

  if (argc == 1) {
    usage();
    exit(1);
  }

  if ( !strcmp(argv[1], "test1")) {
    test1();
  }
  else if ( !strcmp(argv[1], "test2")) {
    test2();
  }
  else if ( !strcmp(argv[1], "test3")) {
    test3();
  }
  else if ( !strcmp(argv[1], "test4")) {
    test4();
  }
  else if ( !strcmp(argv[1], "test5")) {
    test5();
  }
  else if ( !strcmp(argv[1], "test6")) {
    test6();
  }
  else if ( !strcmp(argv[1], "test7")) {
    test7();
  }
  else if ( !strcmp(argv[1], "test8")) {
    test8();
  }
  else if ( !strcmp(argv[1], "test9")) {
    test9();
  }
  else if ( !strcmp(argv[1], "test10")) {
    test10();
  }
  else if ( !strcmp(argv[1], "test11")) {
    test11();
  }
  else if ( !strcmp(argv[1], "test12")) {
    test12();
  }
  else if ( !strcmp(argv[1], "test13")) {
    test13();
  }
  else {
    usage();
    exit(1);
  }

  exit(0);
}
