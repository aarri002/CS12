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

/*Takes desired mean and variance values and calculates range a to b
then generates a random value from range using randFloat(a,b);*/
double rand_mv(double mean, double var)
{
    double x = 0.0;
    double y = 0.0;
    
    double a = 1.0;
    double b = -(2.0*mean);
    double c = ((mean*mean)-(3.0*(var*var)));
    
    x = ((-b) + (sqrt((b*b)-(4.0*a*c))))/2.0;
    y = -x + (2.0*mean);
    
    
    cout << setprecision(1);
    cout << fixed;
    cout << x << " " << y << endl;
    
    return randFloat(x, y);
}

int main()
{
    srand(time(0));
    
    double mean = 0.0;
    double variance = 0.0;
    double randomNum = 0.0;
   
    cout << "Enter Mean: ";
    cin >> mean;
    cout << "Enter Variance:";
    cin >> variance;
    
    randomNum = rand_mv(4.0, 2.0);
    cout << setprecision(1);
    cout << fixed;
    cout << "Random number: " << randomNum << endl;
    
    return 0;
}