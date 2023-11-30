#include<iostream>
#include<vector>
#include<string>
#include <iostream>
#include <chrono>
#include <list>
#include <iomanip>
typedef std::chrono::high_resolution_clock Clock;

using namespace std;

vector<vector<int>> CreateDatasets();

void Bubblesort(vector<int>& vect);

void Insertionsort(vector<int>& vect);

void Mergesort(vector<int>& vect, int left, int right);

void Merge(vector<int>& vect, int left, int middle, int right);

void Quicksort(vector<int>& vect, int left, int right);

int Partition(vector<int>& vect, int left, int right);

int Findmax(vector<int>& vect);

void Radixsort(vector<int>& vect);

void Countingsort(vector<int>& vect, int exp);

void PrintVector(vector<int> vect);