/**
 *  CS 251 - Spring 2016
 *  Project 1 Solution
 */

#include <iostream>

using namespace std;

/**
 *  Method that prints the dashes
 */
void print_dashes(int c) {

    /* Calculate the number of required dashes */
    int n = 6 * c - 3;

    /* Print the dashes */
    for (int i = 0; i < n; ++i) cout << '-';

    /* Move to the next line of the output */
    cout << endl;
}

/**
 *  The main function
 */
int main() {

    /* Read the number of columns */
    int c;
    cin >> c;

    /* Print the initial line of dashes */
    print_dashes(c);

    /* Process the file */
    int i = 0;
    int num;
    while (cin >> num) {

        /* Determine the location of bars and space characters */
        if (i > 0) cout << " | ";
        if (num < 100) cout << ' ';
        if (num < 10) cout << ' ';

        cout << num;

        /* Increment counter by one */
        i += 1;

        /* If we reached the number of columns then restart the
           counter and add a new line character */
        if(i == c) {
            i = 0;
            cout << endl;
        }
    }

    /* Print last line of dashes */
    print_dashes(c);

    /* Exit the program */
    return 0;
}
