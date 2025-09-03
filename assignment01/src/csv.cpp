//
//  csv.cpp
//
//  Functions for reading CSV files.
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

#include "csv.h"

#include <algorithm>  // for remove_if()
#include <iostream>
#include <sstream>

using namespace std;

namespace csi281 {

  // Remove extraneous characters from string so it can
  // be converted into a number
  void clean(string &str) {
    string unwanted = "\"\' \t\n";
    str.erase(
        remove_if(str.begin(), str.end(), [&](char &c) { return !unwanted.find_first_of(c); }));
  }

  // Read from a input string stream we hit the next comma, or the end
  // and try to convert it into the float we seek.
  float readFloatCell(istringstream &iss) {
    string holder;
    getline(iss, holder, ',');
    clean(holder);
    return stof(holder);
  }

  // Read from a input string stream we hit the next comma, or the end
  // and try to convert it into the int we seek.
  int readIntCell(istringstream &iss) {
    string holder;
    getline(iss, holder, ',');
    clean(holder);
    return stoi(holder);
  }

  // Read from a input string stream we hit the next comma, or the end
  // and try to convert it into the string we seek.
  string readStringCell(istringstream &iss) {
    string holder;
    getline(iss, holder, ',');
    return holder;
  }

  // Read a single line from a file stream and turn it into a CityYear
  // You'll want to use the standard library function getline()
  // and the readCell() functions above
  // You'll also want to construct a CityYear from what you have read from the file
  CityYear readLine(ifstream &file) {
    
    string temp;

    //put it into a string stream
    getline(file, temp);
    // I was having trouble figuring out how to get data into an istringstream,
    // and found a solution at https://cboard.cprogramming.com/cplusplus-programming/79024-initializing-istringstream.html
    istringstream reader(temp);
    
    CityYear tempCityYear;

    // Assuming the data read will be in the same format as "tempdata.csv",
    // I'll need to ignore the station and name
    reader.ignore(INT_MAX, ',');
    reader.ignore(INT_MAX, ',');

    tempCityYear.year = readIntCell(reader);
    tempCityYear.numDaysBelow32 = readIntCell(reader);
    tempCityYear.numDaysAbove90 = readIntCell(reader);
    tempCityYear.averageTemperature = readFloatCell(reader);
    tempCityYear.averageMax = readFloatCell(reader);
    tempCityYear.averageMin = readFloatCell(reader);

    // It feels like I'm doing something wrong by not returning a reference,
    // but I can't see any other way to do it.
    return tempCityYear;
  }

  // Read city by looking at the specified lines in the CSV
  // You'll need to open an ifstream to fileName
  // You'll need to read CityYears from the file using readLine() until there
  // is nothing left to read
  // The ifstream method good() may be useful
  // Make sure to just read between startLine and endLine (inclusive of endLine) INCLUSIVE OF STARTLINE TOO (?)
  // Construct a CityTemperatureData and return it
  // create an array of CityYear instances to pass to the CityTemperatureData constructor
  // when the CityTemperatureData is created, it will take ownership of the array
  CityTemperatureData* readCity(string cityName, string fileName, int startLine, int endLine) {

      CityTemperatureData *result = nullptr;
      CityYear* dataListPtr = nullptr;
    dataListPtr = new CityYear[(endLine - startLine + 1)];

      ifstream dataFile;
    dataFile.open(fileName);

    if (dataFile.good())
    {

        dataFile.ignore(INT_MAX, '\n'); // ignores the header information in the data

      int lineCounter = 1;
      //traverses to the start of the given range
      while (lineCounter < startLine) {
        dataFile.ignore(INT_MAX, '\n');
        lineCounter++;
      }
      // creates a list of CityYears in the rang
      int i = 0; // iterator to handle putting things in the array
      while ((lineCounter <= endLine) && !dataFile.eof()) {

          dataListPtr[i] = readLine(dataFile);

        lineCounter++;
        i++;
      }

      // create the CityTemperatureData object to return
      result = new CityTemperatureData(cityName, dataListPtr, (endLine - startLine + 1));

    } else {
      cout << "Error opening file!";
      delete[] dataListPtr;
      dataListPtr = nullptr;
    }
    dataFile.close();



    //Pretty sure I need to bank on the deconstructor handling deleting the list I give to _data
    return result;
  }
}  // namespace csi281
