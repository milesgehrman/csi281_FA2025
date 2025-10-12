//
//  HashTable.h
//
//  This file defines a Hash Table class.
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

#ifndef hashtable_hpp
#define hashtable_hpp

#include <algorithm>   // find_if(), remove_if()
#include <functional>  // for hash()
#include <iostream>
#include <list>
#include <optional>
#include <utility>  // for pair

#include "MemoryLeakDetector.h"

#define DEFAULT_CAPACITY 10
#define MAX_LOAD_FACTOR 0.7

using namespace std;

namespace csi281 {
  template <typename K, typename V> class HashTable {
  public:
    // Initialize the array with a starting capacity
    HashTable(int cap = DEFAULT_CAPACITY) {
      if (cap < 1) {
        cap = 1;
      }  // cannot have < 1 capacity
      resize(cap);
    }

    // Erase the array
    ~HashTable() { delete[] backingStore; }

    // Put the key value pair in the hash table
    // If *key* is already present, change its
    // associated value to *value*
    // If the load factor exceeds the MAX_LOAD_FACTOR
    // then resize the table
    // TIP: Be careful to get a reference to the list at each
    // location in the backing store, so you're modifying
    // the original and not a copy
    void put(const K key, const V value) {
     
        list<pair<K, V>> *workingList = &backingStore[(hashKey(key) % capacity)]; // get a reference to the list we are working with
        pair<K,V> data(key, value); // put key and value into a pair for storage

        for (auto p = workingList->begin(); p != workingList->end(); p++) {  
            
            if ((*p).first == key)
            {
            (*p).second = value;
              //debugPrint();
              return;
          }
        }  
        // if we went through the list and found nothing...
        (backingStore[(hashKey(key) % capacity)]).push_back(data);  // append the new data to the end of the linked list
        count++;
        //debugPrint();
        if (getLoadFactor() > MAX_LOAD_FACTOR)  // resize has table if load factor is too high
        {
          resize(capacity * growthFactor);
        }
        
    }

    // Get the item associated with a particular key
    // return an empty optional (nullopt) if the item is not found
    // and returns an optional with the value associated with key
    // if key is found
    // TIP: read the documentation on optional
    // https://en.cppreference.com/w/cpp/utility/optional
    // TIP: Be careful to get a reference to the list at each
    // location in the backing store, so you're modifying
    // the original and not a copy
    optional<V> get(const K &key) {
      for (auto p : backingStore[(hashKey(key) % capacity)]) {  // iterate through the appropriate bucket
        if (p.first == key) {
          return p.second; // return value that matches the key in the list
        }
      } 
      return nullopt; // returns nullopt if we went through the list where it should be and found nothing
    }

    // Remove a key and any associated value from the hash table
    // TIP: I suggest using remove_if()
    // https://en.cppreference.com/w/cpp/algorithm/remove
    // TIP: Be careful to get a reference to the list at each
    // location in the backing store, so you're modifying
    // the original and not a copy
    void remove(const K &key) {
      optional<V> matchingValue = get(key); // get associated value in order to use the remove function
      if (!bool(matchingValue)) return; // exit the function early if the value wass never there in the first place
        pair<K, V> target(key, matchingValue.value()); // combine key and associated value into a pair to use in remove()
 
      (backingStore[(hashKey(key) % capacity)]).remove(target);  // remove targeted item
      count--;
    }

    // Calculate and return the load factor
    float getLoadFactor() { return ((float)count) / ((float)capacity); }

    // Get the count
    int getCount() { return count; }

    // Get the capacity
    int getCapacity() { return capacity; }

    // Print out the contents of the hash table
    void debugPrint() {
      for (int i = 0; i < capacity; i++) {
        cout << i << ":";
        for (auto p : backingStore[i]) {
          cout << " -> (" << p.first << ", " << p.second << ")";
        }
        cout << endl;
      }
    }

  private:
    int capacity = 0;
    int growthFactor = 2;
    int count = 0;
    hash<K> key_hash;
    list<pair<K, V>> *backingStore = nullptr;

    // Shift all of the items in backingStore into a
    // new backing store of size cap, or create
    // the backingStore for the first time
    void resize(int cap) {
      // copied and modified from the resize function from assignment 3
      
      // generate a new backingStore if we haven't already
        if (backingStore == nullptr)
        {
        backingStore = new list<pair<K, V>>[cap];
          capacity = cap;
          return;
      }

      // don't do anything if we're already correct
      if (cap == capacity) {
        return;
      }

      list<pair<K,V>> *destination = new list<pair<K,V>>[cap];
      for (int i = 0; i < capacity; i++) {
        for (auto p = backingStore[i].begin(); p != backingStore[i].end(); p++) {
          destination[(hashKey((*p).first) % cap)].push_back(*p); // put the element from the old ht in its appropriate place in the new one
        }
      }
      delete[] backingStore;
      backingStore = destination;
      capacity = cap;
      if (capacity < count) {
        count = capacity;
      }
    }

    // hash anything into an integer appropriate for
    // the current capacity
    // TIP: use the std::hash key_hash defined as a private variable
    size_t hashKey(const K &key) { return key_hash(key); }
  };

}  // namespace csi281

#endif /* hashtable_hpp */
