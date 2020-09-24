// BOOST::PYTHON C++ program for insertion sort  
#include <boost/python.hpp>
#include <iostream>

using namespace std; 
namespace BP = boost::python;
  
/* Function to sort an array using insertion sort*/


namespace merge
{
void merge(BP::list arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = BP::extract<int>(arr[l+i]);
    for(j=0; j<n2; j++)
        R[j] = BP::extract<int>(arr[m+1+j]);

    i = 0; j = 0; k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j])
        {
            arr[k] = BP::object(L[i]);
            i++;
        }
        else
        {
            arr[k] = BP::object(R[j]);
            j++;
        }
        k++;
    }

    // Adding remaining elements of L array into the list
    while( i < n1 )
    {
        arr[k] = BP::object(L[i]);
        i++;
        k++;
    }

    // Adding remaining elements of R array into the list
    while( j < n2)
    {
        arr[k] = BP::object(R[j]);
        j++;
        k++;
    }

}

void mergesort(BP::list arr, int l, int r)
{
    if (l < r){
	int m = (l+r)/2;
	mergesort(arr, l, m);
	mergesort(arr, m + 1, r);
	merge(arr, l, m, r);
	}
}

}


template<typename T>
void insertionsort(BP::list arr) 
{  
    int n = BP::len(arr);
    int j;  
    T key;
    for (int i = 1; i < n; i++) 
    {  
        key = BP::extract<T>(arr[i]);  
        j = i - 1;  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  
  
// A utility function to print an array of size n  
void printarray(BP::list arr)  
{  
    for (int i = 0; i < BP::len(arr); i++)  
        cout << BP::extract<int>(arr[i])<< " ";  
    cout << endl; 
}  


// A utility function to swap two elements  
//void swap(int* elem_1, int* elem_2)  

void swap(auto elem_1, auto elem_2)  
{  
   //cout<<BP::extract<int>(elem_1)<< "---"<< BP::extract<int>(elem_2)<<endl;
    BP::object tmp = elem_1;  //BP::extract<int>(elem_1);  
    elem_1 = elem_2;  
    elem_2 = tmp; //BP::object(tmp);  
    //cout<<BP::extract<int>(elem_1)<< "---"<< BP::extract<int>(elem_2)<<endl;
}  
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition(BP::list arr, int low, int high)  
{  
    int pivot = BP::extract<int>(arr[high]); // pivot element
    int i = (low - 1); // Index of smaller element  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(arr[i], arr[j]);  
        }  
    }  
    swap(arr[i + 1], arr[high]);  
    return (i + 1);  
}  
  
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(BP::list arr, int low, int high)  
{  
    if (low < high)  
    {  
        int mid_i = partition(arr, low, high);  
        quickSort(arr, low, mid_i - 1);  
        quickSort(arr, mid_i + 1, high);  
    }  
}  

void quicksort(BP::list arr)
{
	quickSort(arr, 0, BP::len(arr) - 1);
}
  
// This code is contributed by rathbhupendra 

BOOST_PYTHON_MODULE(iso)
{
	BP::def("insertionsort", &insertionsort<int>, BP::args("arr"), "Insertion sort algorithm");
	BP::def("qsort", &quicksort);
	BP::def("msort", &merge::mergesort);
    BP::def("printarray", &printarray);
}
