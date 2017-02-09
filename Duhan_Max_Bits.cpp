// Chris Duhan
// CS 2433 - Wuthrich
// Assignment 1
// 9/25/2016
// The purpose of this program is to use bitwiae operators to avoid
// the use of logical operators with multiple variables.

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream infile("bits.dat");
	ofstream outfile("Duhan_Max_bits.out");

	outfile << "Max Duhan" << endl;

	unsigned short x = 0;	// The value to be compared with bitwise operators
	int i = 1;				// A counter to print the loop iteration to the output file

	while (infile >> x)
	{
		outfile << "\n\nASSIGNMENT #" << i << " OPTIONS \n\n";
		// The value in "x" is now compaired on the bit level
		if (x & 1)
			outfile << "This assignment has a time limit.\n";
		if (x & 2)
			outfile << "The questions in this assignment may be printed.\n";
		if (x & 4)
			outfile << "The questions in this assignment will be scrambled.\n";
		if (x & 8)
			outfile << "This assignment is password protected.\n";
		if (x & 16)
			outfile << "This assignment shows point values.\n";
		if (x & 32)
			outfile << "This assignment shows question titles.\n";
		if (x & 64)
			outfile << "This assignment shows references.\n";
		if (x & 128)
			outfile << "This assignment allows access to external links.\n";
		if (x & 256)
			outfile << "This assignment allows formulas to be shown.\n";
		if (x & 1024)
			outfile << "This assignment has only 1 attempt allowed.\n";
		if (x & 2048)
			outfile << "This assignment requires correct letter case.\n";
		if (x & 4096)
			outfile << "This assignment has late submissions allowed.\n";
		if (x & 8192)
			outfile << "This assignment has access to eBook allowed.\n";
		if (x & 16384)
			outfile << "This assignment has access to \"Check my work\" allowed.\n";
		if (x & 32768)
			outfile << "This assignment requires correct spacing and punctuation.\n";
		if (x & 65536)
			outfile << "This assignment allows the student to  \"Ask the instructor\".\n";
		i++;
	}
	return 0;
}
