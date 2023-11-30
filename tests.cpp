#include<vector>
#include <iostream>
#include <chrono>
#include "SortingFunctions.h"
typedef std::chrono::high_resolution_clock Clock;

#include <gtest/gtest.h>
    using namespace std;

        TEST(BubbleSort, FunctionalityTest)
        {
            vector<int> vect = {13, 19, 7, 3, 11, 1, 5, 2, 10, 16};
            vector<int> sortedVect = {1, 2, 3, 5, 7, 10, 11, 13, 16, 19};

            cout << "\nVector before Bubble sorting:" << endl;
            PrintVector(vect);

            auto t1 = Clock::now();

            Bubblesort(vect);

            auto t2 = Clock::now();

            cout << "Vector after Bubble sorting:" << endl;
            PrintVector(vect);

            cout << "Delta t2-t1: " 
	        << chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
	        << " nanoseconds" << std::endl;

            EXPECT_TRUE(vect == sortedVect);
        }

        TEST(InsertionSort, FunctionalityTest)
        {
            vector<int> vect = {13, 19, 7, 3, 11, 1, 5, 2, 10, 16};
            vector<int> sortedVect = {1, 2, 3, 5, 7, 10, 11, 13, 16, 19};

            cout << "\nVector before Insertion sorting:" << endl;
            PrintVector(vect);

            auto t1 = Clock::now();

            Insertionsort(vect);

            auto t2 = Clock::now();

            cout << "Vector after Insertion sorting:" << endl;
            PrintVector(vect);
            
            cout << "Delta t2-t1: " 
	        << chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
	        << " nanoseconds" << std::endl;

            EXPECT_TRUE(vect == sortedVect);
        }

        TEST(MergeSort, FunctionalityTest)
        {
            vector<int> vect = {13, 19, 7, 3, 11, 1, 5, 2, 10, 16};
            vector<int> sortedVect = {1, 2, 3, 5, 7, 10, 11, 13, 16, 19};

            cout << "\nVector before Merge sorting:" << endl;
            PrintVector(vect);

            auto t1 = Clock::now();

            Mergesort(vect, 0, vect.size() - 1);

            auto t2 = Clock::now();

            cout << "Vector after Merge sorting:" << endl;
            PrintVector(vect);

            cout << "Delta t2-t1: " 
	        << chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
	        << " nanoseconds" << std::endl;

            EXPECT_TRUE(vect == sortedVect);
        }

        TEST(QuickSort, FunctionalityTest)
        {
            vector<int> vect = {13, 19, 7, 3, 11, 1, 5, 2, 10, 16};
            vector<int> sortedVect = {1, 2, 3, 5, 7, 10, 11, 13, 16, 19};

            cout << "\nVector before Quick sorting:" << endl;
            PrintVector(vect);

            auto t1 = Clock::now();

            Quicksort(vect, 0, vect.size() - 1);

            auto t2 = Clock::now();

            cout << "Vector after Quick sorting:" << endl;
            PrintVector(vect);

            cout << "Delta t2-t1: " 
	        << chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
	        << " nanoseconds" << std::endl;

            EXPECT_TRUE(vect == sortedVect);
        }

        TEST(RadixSort, FunctionalityTest)
        {
            vector<int> vect = {13, 19, 7, 3, 11, 1, 5, 2, 10, 16};
            vector<int> sortedVect = {1, 2, 3, 5, 7, 10, 11, 13, 16, 19};

            cout << "\nVector before Radix sorting:" << endl;
            PrintVector(vect);

            auto t1 = Clock::now();

            Radixsort(vect);

            auto t2 = Clock::now();

            cout << "Vector after Radix sorting:" << endl;
            PrintVector(vect);

            cout << "Delta t2-t1: " 
	        << chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
	        << " nanoseconds" << std::endl;

            EXPECT_TRUE(vect == sortedVect);
        }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}