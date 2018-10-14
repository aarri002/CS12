#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ios>
#include <iomanip>
#include <math.h> 

using namespace std;

/*This function generates a random double value between a and b*/
double randFloat (double a, double b)
{
   return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

/*Fills a float array with random float numbers ussing randFloat function. 
With given size, and min to max range. */
void fillSequence(float sequence[], int size, double min, double max)
{
    for (int i = 0; i < size; ++i)
    {
        sequence[i] = randFloat(min,max);
    }
    return;
}

/*Displays a float array*/
void display(const float sequence[], int size)
{
        for (int i = 0;  i < size; ++i)
    {
        cout << sequence[i] << " ";
    }
}

/*Computes practical mean out of a float array with given size*/
double computeMean(const float sequence[], int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; ++i)
    {
        sum = sum + sequence[i];
    }
    
    return (sum)/static_cast<double>(size);
    
}
/*Computes theoretical mean out of a range*/
double computeMean(double a, double b)
{

    return ((a+b)/static_cast<float>(2));
}

/*Computes practical variance out of a float array with given size*/
double computeVariance(const float sequence[], int size)
{
    int i = 0;
    double sum = 0.0;
    double sumSqr = 0.0;
    
    for (i = 0; i < size; ++i)
    {
        sum = sum + sequence[i];
        sumSqr = sumSqr + (sequence[i] * sequence[i]);
    }
    
    return sqrt((sumSqr - (sum*sum)/static_cast<double>(size))/static_cast<double>(size-1));
}
/*Computes theoretical variance out of a range*/
double computeVariance(double a, double b)
{
    return sqrt(((b-a)*(b-a))/(static_cast<float>(12)));
}


int main()
{
    const int SIZE = 500;
    const float MIN1 = -5.20;
    const float MAX1 = 5.20;
    const float MIN2 = -9.20;
    const float MAX2 = 1.20;
    srand(time(0));
    
    float sequenceOne[SIZE];
    float sequenceTwo[SIZE];
    
    fillSequence(sequenceOne, SIZE, MIN1, MAX1);
    fillSequence(sequenceTwo, SIZE, MIN2, MAX2);
    
    
    cout << setprecision(2);
    cout << fixed;
    cout << computeMean(MIN1,MAX1) << " " << computeMean(sequenceOne, SIZE) << " "; 
    cout << computeVariance(MIN1,MAX1) << " ";
    cout << computeVariance(sequenceOne, SIZE) << endl;
    cout << computeMean(MIN2,MAX2) << " " << computeMean(sequenceTwo, SIZE) << " "; 
    cout << computeVariance(MIN2,MAX2) << " "; 
    cout << computeVariance(sequenceTwo, SIZE) << endl;
    
    return 0;
}