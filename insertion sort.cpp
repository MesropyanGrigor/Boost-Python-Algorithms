// BOOST::PYTHON C++ program for insertion sort  
#include <boost/python.hpp>
#include <iostream>

using namespace std; 
namespace BP = boost::python;
  
/* Function to sort an array using insertion sort*/


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

BOOST_PYTHON_MODULE(iso)
{
	BP::def("insertionsort",
                &insertionsort<int>,
                BP::args("arr"), 
                "Insertion sort algorithm");
        BP::def("printarray", &printarray);
}