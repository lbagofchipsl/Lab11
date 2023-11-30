#include"SortingFunctions.h"

/// @brief Creates the required datasets specified in Requirement 1 of README
/// @return Returns a vector containing vectors of size 10, 100, 500, 5000, 25000
///         with random numbers ranging from 0 to 2n
vector<vector<int>> CreateDatasets()
{
    vector<vector<int>> dataSets = 
    {
        vector<int>(10), 
        vector<int>(100), 
        vector<int>(500), 
        vector<int>(5000),
        vector<int>(25000)
    };
    
    // Generates values to be stored in vectors
    for(int i = 0; i < dataSets.size(); i++)
        for (int j = 0; j < dataSets[i].size(); j++)
            dataSets[i][j] = rand() % (dataSets[i].size() * 2);

    return dataSets;
}

/// @brief Sorts a vector by comparing adjacent values, lefting from the 1st index
/// @param vect Vector to be sorted
/// @return Sorted vector from lowest to highest integer value
void Bubblesort(vector<int>& vect)
{
    bool swap;

    for (int i = 0; i < vect.size(); i++)
    {
        swap = false;
        
        for (int j = 0; j < vect.size(); j++)
        {
            if(vect[j] > vect[j+1])
            {
                auto tempVal = vect[j];
                vect[j] = vect[j+1];
                vect[j+1] = tempVal;
                swap = true;
            }
        }
        
        if (!swap)
            break;
    }
}

/// @brief Sorts a vector lefting from its 2nd index, and comparing it to everything before it.
/// @param vect Vector to be sorted
/// @return Sorted vector from lowest to highest integer value
void Insertionsort(vector<int>& vect)
{
    for (int i = 1; i < vect.size(); i++)
    {
        auto key = vect[i];
        auto j = i - 1;
        while (j >= 0 && vect[j] > key) 
        {
            vect[j+1] = vect[j];
            j--;
        }

        vect[j + 1] = key;
    }
}

/// @brief Vector is split into subvectors to then be sorted. 
//         These sorted subvectors are then merged back into a single vector
/// @param vector Vector to be sorted
/// @param left lefting index of the vector
/// @param right Last index of the vector
void Mergesort(std::vector<int>& vect, int left, int right) 
{
    if (left < right) 
    {
        auto middle = left + (right - left) / 2;

        Mergesort(vect, left, middle);
        Mergesort(vect, middle + 1, right);

        Merge(vect, left, middle, right);
    }
}

/// @brief Combines sorted vectors until a vector with the original size is created
/// @param vect Vector to be combined
/// @param left First index of the vector
/// @param middle Middle index of the vector
/// @param right Final index of the vector
void Merge(vector<int>& vect, int left, int middle, int right) {
    auto n1 = middle - left + 1;
    auto n2 = right - middle;

    vector<int> v1(n1);
    vector<int> v2(n2);

    for (int i = 0; i < n1; i++)
        v1[i] = vect[left + i];
    for (int i = 0; i < n2; i++)
        v2[i] = vect[middle + 1 + i];

    auto i = 0; 
    auto j = 0; 
    auto k = left; 

    while (i < n1 && j < n2) 
    {
        if (v1[i] <= v2[j]) 
        {
            vect[k] = v1[i];
            i++;
        } 
        else 
        {
            vect[k] = v2[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        vect[k] = v1[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        vect[k] = v2[j];
        j++;
        k++;
    }
}

/// @brief Recursive function that picks "pivot" points for vectors 
//         and moves values in the vector to other vectors based on whether
//         they are greater than, or less than, and then choosing pivots in 
//         the new vectors, those pivots are compared and swapped/sorted accordingly
/// @param vect Vector to be sorted
/// @param left First index of the vector
/// @param right Last index of the vector
void Quicksort(vector<int>& vect, int left, int right) 
{
    if (left >= right)
        return;
 
    auto p = Partition(vect, left, right);
 
    Quicksort(vect, left, p - 1);
    Quicksort(vect, p + 1, right);
}

/// @brief Chooses a pivot point in a vector to compare the rest of the vector to
//          moves values to 2 vectors, one for values < pivot, one for values > pivot
/// @param vect Vector to chose a pivot from
/// @param left First index of the vector
/// @param right Last index of the vector
int Partition(vector<int>& vect, int left, int right) 
{
    // Choosing the pivot
    int pivot = vect[right];
 
    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (left - 1);
 
    for (int j = left; j <= right - 1; j++) {
 
        // If current element is smaller than the pivot
        if (vect[j] < pivot) {
 
            // Increment index of smaller element
            i++;
            swap(vect[i], vect[j]);
        }
    }
    swap(vect[i + 1], vect[right]);
    return (i + 1);
}

/// @brief Sorts vector by looking at individual values from right to left and grouping them
///        into buckets based off of those values until everything is sorted
/// @param vect Vector to be sorted
void Radixsort(vector<int>& vect)
{
    auto max = Findmax(vect);

    for (int exp = 1; max / exp > 0; exp *= 10) 
        Countingsort(vect, exp);
}

/// @brief Find's the max int value in a vector
/// @param vect Vector to find max of
/// @return Max of the vector
int Findmax(vector<int>& vect) 
{
    auto max = vect[0];
    for (int i = 1; i < vect.size(); i++) 
    {
        if (vect[i] > max) 
            max = vect[i];
    }
    return max;
}

/// @brief Used by Radix sorting in order to organize elements by the amount of times a value appears.
///        It then reconstructs the sorted vector by distributing the values based on their cumulative count.
/// @param vect Vector to be sorted by Radix sorting
/// @param exp Counter
void Countingsort(vector<int>& vect, int exp) 
{
    const auto base = 10; 
    auto n = vect.size();

    vector<int> output(n);
    vector<int> count(base, 0);

    for (int i = 0; i < n; i++) 
        count[(vect[i] / exp) % base]++;

    for (int i = 1; i < base; i++) 
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) 
    {
        output[count[(vect[i] / exp) % base] - 1] = vect[i];
        count[(vect[i] / exp) % base]--;
    }

    for (int i = 0; i < n; i++) 
        vect[i] = output[i];
}

/// @brief Prints each element in a vector
/// @param vect Vector to be printed
void PrintVector(vector<int> vect)
{
    for (auto elem : vect) 
        cout << elem << " ";
    cout << endl;
}