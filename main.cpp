#include <iostream>
#include <cmath>
using namespace std;

// MADE BY TAUFIQ
// All of the formula below were taken from slide notes PSDA. I use sample formula, not population
// Happy assignmenting :D

int main()
{
    // int const n = 30;
    int n; // Better to use constant for array size... But in this case, i use normal int because we can change how many elements do we want
    cout << "Enter how many elements in the dataset: ";
    cin >> n;
    double kurtos = 0, skew = 0, mean = 0, stddev = 0;
    double number[n];

    cout << "Enter the number= ";
    for (int i = 1; i <= n; i++)
    {
        cin >> number[i - 1];
    }

    // Find Mean
    for (int j = 1; j <= n; j++)
    {
        mean = mean + number[j - 1];
    }
    mean = mean / n;
    cout << "\nMean= " << mean << endl;

    // Find Variance and Std Deviation
    for (int j = 1; j <= n; j++)
    {
        stddev = stddev + pow((number[j - 1] - mean), 2);
    }
    stddev = stddev / (n - 1);
    cout << "Variance= " << stddev << endl;
    stddev = pow(stddev, 0.5);
    cout << "Standard Deviation= " << stddev << endl;

    // Find skewness
    for (int j = 1; j <= n; j++)
    {
        skew = skew + (pow((number[j - 1] - mean), 3) / ((n - 1) * (pow(stddev, 3))));
    }
    cout << "Skewness= " << skew << endl;

    // Find kurtosis
    for (int j = 1; j <= n; j++)
    {
        kurtos = kurtos + (pow((number[j - 1] - mean), 4) / ((n - 1) * (pow(stddev, 4))));
    }
    cout << "Kurtosis= " << kurtos << endl;

    if (skew == 0)
        cout << "Normal distribution, ";
    else if (skew < 0)
        cout << "Distribution is assymetrical, points in negative direction (left skewed), ";
    else if (skew > 0)
        cout << "Distribution is assymetrical, points in positive direction (right skewed), ";
    else
        cout << "Ummm wtf";

    if (kurtos == 3)
        cout << "mesokurtic.";
    else if (kurtos < 3)
        cout << "platykurtic. ";
    else if (kurtos > 3)
        cout << "leptopkurtic.";
    else
        cout << "Ummm wtf";
    cout << endl
         << endl;
    
    system("PAUSE");
    return 0;

    // No mode, median, quartile calculation
}
