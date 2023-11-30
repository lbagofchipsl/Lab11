#include<iostream>
#include<vector>
#include<string>
#include <iostream>
#include <chrono>
#include <iomanip>
#include "SortingFunctions.h"

typedef std::chrono::high_resolution_clock Clock;

using namespace std;

int main()
{
    // Declare a vector in order to store all values for each iteration
    vector<vector<long>> storedValues(5, vector<long>(5, 0));

    for (int i = 0; i < 10; i++)
    {
        // Creates the required datasets with correctly generated data
        auto baseDataset = CreateDatasets();

        cout << "Sorting for iteration " << i + 1 << "...\n";
        
        for (int j = 0; j < 5; j++)
        {
            // Ensures that each sorting algorithm is given the same unsorted datasets
            auto dataSets = baseDataset;
            
            for (int k = 0; k < dataSets.size(); k++)
            {

                // We declare t1 here in order to ensure that the following if statement has no affect
                // on the time
                chrono::_V2::system_clock::time_point t1;

                // chooses required algorithm based off of current iteration
                if (j == 0)
                {
                    t1 = Clock::now();
                    Bubblesort(dataSets[k]);
                }
                else if (j == 1)
                {
                    t1 = Clock::now();
                    Insertionsort(dataSets[k]);
                }
                else if (j == 2)
                {
                    t1 = Clock::now();
                    Mergesort(dataSets[k], 0, dataSets[k].size() - 1);
                }
                else if (j == 3)
                {
                    t1 = Clock::now();
                    Quicksort(dataSets[k], 0, dataSets[k].size() - 1);
                }
                else
                {
                    t1 = Clock::now();
                    Radixsort(dataSets[k]);
                }

                // Takes time right after sorting algorithm finishes
                auto t2 = Clock::now();

                // Calculates time passed in nanoseconds
                auto timeDiff = chrono::duration_cast<chrono::nanoseconds>(t2 - t1);

                // 2d Vector stores value at that place in the table
                storedValues[j][k] = storedValues[j][k]+ (long)timeDiff.count();
            }
        }
    }

    // The following prints out the average values in the table format requested in line 40 of README
    cout << "The averages for the 10 iterations is shown below... \n";
    cout << "--------------------------------------------------------------------------------------------";
    cout << "\n                         10             100             500          5000             25000";
    
    for (int i = 0; i < storedValues.size(); i++)
    {   
        if(i == 0)
            cout << "\nBubble Sort   ";
        else if(i == 1)
            cout << "\nInsertion Sort";
        else if(i == 2)
            cout << "\nMerge Sort    ";
        else if(i == 3)
            cout << "\nQuick Sort    ";
        else 
            cout << "\nRadix Sort    ";

        // Prints average values with certain formatting
        for (int j = 0; j < storedValues[i].size(); j++)
        {
            auto length = (to_string(storedValues[i][j] / 10)).length();
            auto print_output = 13 - length;
            cout << setw(print_output) << "   " << storedValues[i][j] / 10 << " ns";
        }
    }

    cout << "\n --------------------------------------------------------------------------------------------\n";

    return 0;
}
