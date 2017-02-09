// Chris Duhan
// CS 2433 - Wuthrich
// Assignment 2
// 10/26/2016
// The purpose of this program is to read integer values into 2D dynamically
// allocated arrays, check if these 2D arrays can have matrix multiplication 
// applied to them and if so perform matrix multiplication to them and write
// the product matrix to the outfile.
// Using the array "matrixSize" to hold the dimensions of the array got a 
// little confusing as I traced through the code, so I had set up an int 
// variable for each: row1, col1, etc. Then I went back to using the matrixSize
// array once I got it working, I think it's a little neater this way.

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int** matrix1;			// First matrix
	int** matrix2;			// Second matrix
	int** multMatrix;		// The multiplied matrix
	int matrixSize[4];		// Keeping track of the dimensions

	ifstream inf("mult.dat");
	ofstream outf("Duhan_Max_mult.txt");

	outf << "Max Duhan\n\n";

	while (inf >> matrixSize[0])
	{
		for (int i = 1; i < 4; i++)
			inf >> matrixSize[i];

		// Create first matrix
		matrix1 = new int*[matrixSize[0]];
		for (int i = 0; i < matrixSize[0]; i++)
			matrix1[i] = new int[matrixSize[1]];

		// Populate first matrix
		for (int r = 0; r < matrixSize[0]; r++)
			for (int c = 0; c < matrixSize[1]; c++)
				inf >> matrix1[r][c];

		// Create second matrix
		matrix2 = new int*[matrixSize[2]];
		for (int j = 0; j < matrixSize[2]; j++)
			matrix2[j] = new int[matrixSize[3]];

		// Populate second matrix
		for (int r_2 = 0; r_2 < matrixSize[2]; r_2++)
			for (int c_2 = 0; c_2 < matrixSize[3]; c_2++)
				inf >> matrix2[r_2][c_2];

		// Only continue if the matrices can be multiplied.
		if (matrixSize[1] == matrixSize[2])
		{
			// Create third matrix
			multMatrix = new int*[matrixSize[0]];
			for (int k = 0; k < matrixSize[0]; k++)
				multMatrix[k] = new int[matrixSize[3]];

			// Populate third matrix by performing multipication.
			for (int r_3 = 0; r_3 < matrixSize[0]; r_3++)
				for (int c_3 = 0; c_3 < matrixSize[3]; c_3++)
				{
					multMatrix[r_3][c_3] = 0;
					for (int a = 0; a < matrixSize[1]; a++)
						multMatrix[r_3][c_3] += (matrix1[r_3][a] * matrix2[a][c_3]);
				}

			// Write multipled matrix to outfile
			for (int r_3 = 0; r_3 < matrixSize[0]; r_3++)
			{
				for (int c_3 = 0; c_3 < matrixSize[3]; c_3++)
					outf << multMatrix[r_3][c_3] << " ";
				outf << endl;
			}

			// Free up memory after writing
			for (int k = 0; k < matrixSize[0]; k++)
				delete[] multMatrix[k];
			delete[] multMatrix;
		}

		else
			outf << "\nMultiplcation of these arrays is undefined.\n\n";

		// Free up memory reguardless of the two read-in matrices
		// reguadless if multiplication was performed or not.
		for (int i = 0; i < matrixSize[0]; i++)
			delete[] matrix1[i];
		delete[] matrix1;

		for (int j = 0; j < matrixSize[2]; j++)
			delete[] matrix2[j];
		delete[] matrix2;
	}

	// After all reading in is done and multiplication
	// has been performed set all pointers to NULL.
	matrix1 = NULL;
	matrix2 = NULL;
	multMatrix = NULL;
	return 0;
}