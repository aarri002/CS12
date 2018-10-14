//____________________________________________________________________________//
// FileName: Main.cpp
// Author: Alberto Arriaga Felix
// Date: 10/21/14
// Assignment #2
// Class: Computer Science 12
// Instructor: Kris Miller
// College: University of California Riverside
//____________________________________________________________________________//
//
// Functions:	findEquilibrium(), display(), main()
//____________________________________________________________________________//


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;
const int ROWS = 6;
const int COLS = 8;

//This function displays the array
void display(const double a[][COLS])
{
    cout << setprecision(2);
    cout << fixed;
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

void findEquilibrium (double grid[][COLS], double equilibrium)
{
    bool foundEquilibrium = false;
    double maxDiff = 0.0;
    double Diff = 0.0;
    double temp = 0.0;
    
    while (!foundEquilibrium)
    {
    
         for(int i = 1; i < ROWS-1; ++i)
        {
            for(int j = 1; j < COLS-1; ++j)
            {
                temp = grid[i][j];
                grid[i][j] = (grid[i-1][j] + grid[i][j+1] + grid[i+1][j] + grid[i][j-1])/4.0;
                Diff = abs(temp - grid[i][j]);
                if (Diff > maxDiff)
                {
                    maxDiff = Diff;
                }
            }
        }

        
        if (maxDiff < equilibrium)
        {
            foundEquilibrium = true;
        }
        //Resetting maxDiff for next cell update
        maxDiff = 0.0;
    }
    return;
}

int main()
{
    //------------------------------------------------------------
    //Declaring variables
    double grid[ROWS][COLS] = {0};
    double tempT = 0.0;
    double tempR = 0.0;
    double tempB = 0.0;
    double tempL = 0.0;
    double equilibrium = 0.0;
    
    //------------------------------------------------------------
    //Getting input and output file names
    string iFileName;
    string oFileName;
    
    cout << "Enter input file name: ";
    cin >> iFileName;
    
    cout << "Etner output file name: ";
    cin >> oFileName;

    //------------------------------------------------------------
    //opening input file for reading values    
    ifstream fin;
    fin.open(iFileName.c_str());
    if(!fin.is_open()) // is_open() returns true if file is open
    {
        cout << "Error, in.dat did not open correctly"<<endl;
        exit(0); //if inside a function and want to break out of program, you use exit(0); from cstdlib
    }
    
    //------------------------------------------------------------
    //Reading in initial temps and equlibrium point from file
    fin >> tempT;
    fin >> tempR;
    fin >> tempB;
    fin >> tempL;
    fin >> equilibrium;
    
    //------------------------------------------------------------
    //Initializing array with starting temps
    for(int i = 0; i < ROWS; ++i)
    {
        for(int j = 0; j < COLS; ++j)
        {
            grid[i][j] = 0.0;
        }
    }
    //------------------------------------------------------------
    //initializing Top Right Bottom Left starting temps
    for(int i = 0; i < 1; ++i)
    {
        for(int j = 0; j < COLS; ++j)
        {
            grid[i][j] = tempT;
        }
    }
    
    for(int i = 1; i < ROWS-1; ++i)
    {
        for(int j = 0; j < 1; ++j)
        {
            grid[i][j] = tempL;
        }
    }
    
    for(int i = 1; i < ROWS-1; ++i)
    {
        for(int j = COLS-1; j < COLS; ++j)
        {
            grid[i][j] = tempR;
        }
    }
    
    for(int i = ROWS -1; i < ROWS; ++i)
    {
        for(int j = 0; j < COLS; ++j)
        {
            grid[i][j] = tempB;
        }
    }
    
    //------------------------------------------------------------
    //calling findEquilibrium to Update cells of grid until equilibrium
    //is reached
    findEquilibrium(grid, equilibrium);
    
    //------------------------------------------------------------
    //opening out file for writing resuts
    ofstream fout;
    fout.open(oFileName.c_str());
    if (!fout.is_open())
    {
        cout << "Error, in.dat did not open correctly"<<endl;
        exit(0); 
    }
    
    //writing matrix to output file only inner cells
    for(int i = 1; i < ROWS-1; ++i)
    {
        for(int j = 1; j < COLS-1; ++j)
        {
            fout << grid[i][j] << " ";
        }
        fout << endl;
    }
    //------------------------------------------------------------
    //Closing fin and cout file handlers
    fin.close();
    fout.close();
    
    return 0;
}