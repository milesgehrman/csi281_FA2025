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
    q1.push(7);
    CHECK(q1.peek() == 7); //make sure push and peek work
    q1.push(13);
    q1.push(17);
    CHECK(q1.getCount() == 3);
    CHECK(q1.peek() == 7); // ensure the top of the queue is still the same
    CHECK(q1.pop() == 7);
    CHECK(q1.pop() == 13);
    CHECK(q1.pop() == 17); //make sure popping happens in the correct order

    // check remove()
    q1.push(2);
    q1.push(2);
    q1.push(5);
    q1.push(2);
    q1.remove(2);
    CHECK(q1.peek() == 5);
  }

  SECTION("Queue w/ string tests") {
    Queue<string> q2 = Queue<string>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    q2.push("Seven");
    CHECK(q2.peek() == "Seven");  // make sure push and peek work
    q2.push("Thirteen");
    q2.push("Seventeen");
    CHECK(q2.getCount() == 3);
    CHECK(q2.peek() == "Seven");  // ensure the top of the queue is still the same
    CHECK(q2.pop() == "Seven");
    CHECK(q2.pop() == "Thirteen");
    CHECK(q2.pop() == "Seventeen");  // make sure popping happens in the correct order

    // check remove()
    q2.push("Two");
    q2.push("Two");
    q2.push("Five");
    q2.push("Two");
    q2.remove("Two");
    CHECK(q2.peek() == "Five");
  }
}

TEST_CASE("Stack Tests", "[stack]") {
  SECTION("Stack w/ int tests") {
    Stack<int> s1 = Stack<int>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    s1.push(7);
    CHECK(s1.peek() == 7);  // make sure push and peek work
    s1.push(13);
    s1.push(17);
    CHECK(s1.getCount() == 3);
    CHECK(s1.peek() == 17);  // ensure the top of the queue is still the same
    CHECK(s1.pop() == 17);
    CHECK(s1.pop() == 13);
    CHECK(s1.pop() == 7);  // make sure popping happens in the correct order

    // check remove()
    s1.push(2);
    s1.push(2);
    s1.push(5);
    s1.push(2);
    s1.remove(2);
    CHECK(s1.peek() == 5);
  }

  SECTION("Stack w/ string tests") {
    Stack<string> s2 = Stack<string>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    s2.push("Seven");
    CHECK(s2.peek() == "Seven");  // make sure push and peek work
    s2.push("Thirteen");
    s2.push("Seventeen");
    CHECK(s2.getCount() == 3);
    CHECK(s2.peek() == "Seventeen");  // ensure the top of the queue is still the same
    CHECK(s2.pop() == "Seventeen");
    CHECK(s2.pop() == "Thirteen");
    CHECK(s2.pop() == "Seven");  // make sure popping happens in the correct order

    // check remove()
    s2.push("Two");
    s2.push("Two");
    s2.push("Five");
    s2.push("Two");
    s2.remove("Two");
    CHECK(s2.peek() == "Five");
  }
}
