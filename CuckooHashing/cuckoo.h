 #include <iostream>
 
 using namespace std;

 class Cuckoo {
 	public:
 		Cuckoo(int len, int maxIter);
 		int h1(int x);
 		int h2(int x);
 		void rehash();
 		bool lookup(int x);
 		void insert(int x);
 		void remove(int x);
 		int whichtable(int x);
 		int where(int x);
 		int getr();
 	private:
 		int * T1;
 		int * T2;
 		int r; //T1, T2 length
 		int maxLoop;
 };