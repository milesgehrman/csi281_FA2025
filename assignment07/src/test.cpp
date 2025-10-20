//
//  test.cpp
//
//  Tests to prove your code works.
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

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#define SECTION(name) DOCTEST_SUBCASE(name)
#undef TEST_CASE
#define TEST_CASE(name, tags) DOCTEST_TEST_CASE(tags " " name)
using doctest::Approx;

#include <string>

#include "Queue.h"
#include "Stack.h"

using namespace std;
using namespace csi281;

TEST_CASE("Queue Tests", "[queue]") {
  SECTION("Queue w/ int tests") {
    Queue<int> q1 = Queue<int>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    // YOUR CODE HERE
    q1.push(7);
    CHECK(q1.peek() == 7); //make sure push and peek work
    q1.push(13);
    q1.push(17);
    CHECK(q1.getCount() == 3);
    CHECK(q1.peek() == 7); // ensure the top of the queue is still the same
    CHECK(q1.pop() == 7);
    CHECK(q1.pop() == 13);
    CHECK(q1.pop() == 17); //make sure popping happens in the correct order
    CHECK(q1.pop() == NULL); //
    CHECK(q1.peek() == NULL); // check popping and peeking an empty queue

    // check remove()
    q1.push(2);
    q1.push(2);
    q1.push(2);
    q1.push(2);
    q1.remove(2);
    CHECK(q1.peek() == NULL);
  }

  SECTION("Queue w/ string tests") {
    Queue<string> q2 = Queue<string>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    // YOUR CODE HERE
  }
}

TEST_CASE("Stack Tests", "[stack]") {
  SECTION("Stack w/ int tests") {
    Stack<int> s1 = Stack<int>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    // YOUR CODE HERE
  }

  SECTION("Stack w/ string tests") {
    Stack<string> s2 = Stack<string>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    // YOUR CODE HERE
  }
}
