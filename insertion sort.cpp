// C++ program for insertion sort  
//#include <bits/stdc++.h> 
#include <boost/python.hpp>
#include <iostream>

using namespace std; 
//using namespace py = boost::python;
namespace py = boost::python;
  
/* Function to sort an array using insertion sort*/


template<typename T>
void insertionSort(boost::python::list arr)  
{  
    int n = boost::python::len(arr);
    //boost::python::list s_list;
    int j;  
    T key;
    for (int i = 1; i < n; i++) 
    {  
        key = boost::python::extract<T>(arr[i]);  
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
void printarray(boost::python::list arr)  
{  
    for (int i = 0; i < boost::python::len(arr); i++)  
        cout << py::extract<int>(arr[i])<< " ";  
    cout << endl; 
}  
 /*** 
// Driver code 
int run()  
{  
    int arr[] = { 12, 11, 13, 5, 6 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
  
    insertionSort(arr, n);  
    printArray(arr, n);  
  
    return 0;  
}  
  
*/

BOOST_PYTHON_MODULE(iso)
{
	boost::python::def("insertionsort", &insertionSort<int>,
                           py::args("arr"), 
                           "Insertion sort algorithm");
        boost::python::def("printarray", &printarray);
	//boost::python::def("run", &run);
}
