

#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    int n, entry, dashnum1, dashnum2;
    ifstream myfile(argv[1]);
    myfile >> n;
    
    ofstream outfile(argv[2]);

    dashnum1 = 6 * n - 3;
    while (dashnum1 > 0) {
	outfile << "-";
    //cout << "-";
	dashnum1--;
    }
    outfile << '\n';

    while (cin >> entry) {
    
    	for (int i = 0; i < n; i++) {
	    
	    if (entry < 10) {
	       if (i == 0) {
	           outfile << "  " << entry << " ";
	       }
	       if (i > 0 && i < (n - 1)) {
	           outfile << "   " << entry << " "; 
	       }
	       if (i == (n - 1)) {
	           outfile << "   " << entry;
	       }
	       if (i < n - 1) {outfile << "|";}
	    }
	    else if (entry < 100 && entry > 9 ) {
	        if (i == 0) {
		    outfile << " " << entry << " ";
		}
		if (i > 0 && i < (n - 1)) {
		    outfile << "  " << entry << " ";
	    	}
		if (i == (n - 1)) {
		    outfile << "  " << entry;
		}
		if (i < n - 1) {outfile << "|";}
	    }
	    else {
	        if (i == 0) {
		    outfile << entry << " ";
		}
		if (i > 0 && i < (n - 1)) {
		    outfile << " " << entry << " ";
		}
		if (i == (n - 1)) {
		    outfile << " " << entry; 
		}
		if (i < n - 1) {outfile << "|";}
	    }
	}
	outfile << '\n';
    }

    dashnum2 = 6 * n - 3;
    while (dashnum2 > 0) {
    	outfile << "-";
	dashnum2--;
    }
    outfile << '\n';
   
    /* Exit the program */
    return 0;
}
