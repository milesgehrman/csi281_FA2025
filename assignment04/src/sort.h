//
//  sort.h
//
//  Functions for bubble sort, selection sort, and insertion sort.
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#ifndef sort_hpp
#define sort_hpp

#include <algorithm>  // for swap()
#include <iostream> // for printArray()

#include "MemoryLeakDetector.h"

using namespace std;

namespace csi281 {


    // swaps the data held in val1 and val2
    // I did not realize we had access to swap()
  template <typename T> void mySwap(T& val1, T& val2) {
    T temp = val1;
    val1 = val2;
    val2 = temp;
  }

  // prints all elements in an array for debugging purposes
  template <typename T> void printArray(const T array[], const int length)
  { 
      cout << "Debug: printing array..." << endl;
    for (int i = 0; i < length; i++) {
      cout << array[i] << "     ";
    }
      cout << endl;
  }

  // Performs an in-place ascending sort of *array* of size *length*
  // using the bubble sort algorithm
  template <typename T> void bubbleSort(T array[], const int length) {
    
    bool loopCheck = true; 

    while (loopCheck) {  // repeat until list is sorted
      loopCheck = false;
      for (int i = 0; i < length - 1; i++) {
        if (array[i] > array[i + 1]) { // if two elements are out of order, swaps them
          mySwap(array[i], array[i + 1]);
          loopCheck = true; // let the outer loop know the loop is not sorted
        }
      }
    }
  }

  // Performs an in-place ascending sort of *array* of size *length*
  // using the selection sort algorithm
  template <typename T> void selectionSort(T array[], const int length) {
    // I DON'T KNOW WHY THIS IS SO MUCH FASTER THAN INSERTION SORT
    T minValue = array[0];
    int minValueLocation = 0;

    for (int j = 0; j < length; j++) // outer loop iterates through the array as we sort indivindiual indicies
    {
      minValue = array[j];
      minValueLocation = j;
      for (int i = j; i < length; i++) // searches for the minimum value and saves it's location
      {
        if (array[i] < minValue) { 
          minValue = array[i];
          minValueLocation = i;
        }
      }
      mySwap(array[j], array[minValueLocation]); // places minimum value in the correct location
    }
  }


  // Performs an in-place ascending sort of *array* of size *length*
  // using the insertion sort algorithm
  template <typename T> void insertionSort(T array[], const int length) 
  {
      for (int i = 1; i < length; i++) // increases the minimum index we have to sift through
      {
      for (int j = i; j > 0; j--) // moves a selected element down the sorted list
          {
            if (array[j] < array[j - 1]) 
                swap(array[j], array[j - 1]); //swap until the element is sorted
            else
             break; // end the traversal early when we reach the correct spot
          }
      }
      
      // seriously, I have no idea why insertion sort is slower on my computer than selection sort
      // I even tried copying in the examples in the notes just to test and selection sort was STILL faster
  }
  
}  // namespace csi281

#endif /* sort_hpp */
