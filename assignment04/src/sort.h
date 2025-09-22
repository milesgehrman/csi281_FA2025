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

#include "MemoryLeakDetector.h"

using namespace std;

namespace csi281 {


    // swaps the data held in val1 and val2
  template <typename T> void mySwap(T& val1, T& val2) {
    T temp = val1;
    val1 = val2;
    val2 = temp;
  }

  // Performs an in-place ascending sort of *array* of size *length*
  // using the bubble sort algorithm
  template <typename T> void bubbleSort(T array[], const int length) {
    
    bool loopCheck = true; 

    while (loopCheck) // repeat until
        loopCheck = false;
      for (int i = 0; i < length - 1; i++)
      {
        if (array[i] > array[i + 1]) {
          mySwap(array[i], array[i + 1]);
          loopCheck = true;
        }
      }
  }

  // Performs an in-place ascending sort of *array* of size *length*
  // using the selection sort algorithm
  template <typename T> void selectionSort(T array[], const int length) {
    // YOUR CODE HERE
    T minValue = array[0];
    int minValueLocation = 0;

    for (int j = 0; j < length; j++)
    {
      minValue = array[j];
      for (int i = j; i < length; i++)
      {
        if (array[i] > minValue) {
          minValue = array[i];
          minValueLocation = i;
        }
      }
      mySwap(array[j], array[minValueLocation]);
    }
  }

  // Performs an in-place ascending sort of *array* of size *length*
  // using the insertion sort algorithm
  template <typename T> void insertionSort(T array[], const int length) {
    // YOUR CODE HERE
  }

  
}  // namespace csi281

#endif /* sort_hpp */
