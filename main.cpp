//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "LinkedQueue.h" // ADT Queue operations

using namespace std;

void CopyConstructorAndAssignmentTester() {
  LinkedQueue<string> queue;
  string items[] = {"zero", "one", "two", "three", "four", "five"};
  for (int i = 0; i < 6; i++) {
    cout << "Adding " << items[i] << endl;
    bool success = queue.Enqueue(items[i]);
    if (!success)
      cout << "Failed to add " << items[i] << " to the queue." << endl;
  }
  cout << "Queue contains, from front to back, zero one two three four five." << endl;
  
  cout << "Checking Copy Constructor tester " << endl;
  
  LinkedQueue<string> copy_of_queue(queue);
  cout << "Copy of queue contains, from front to back,";
  for (int i = 0; i < 6; i++)
    {
      cout << " " << copy_of_queue.PeekFront();
      copy_of_queue.Dequeue();
    }
  cout << "." << endl;
  
  cout << "Checking Assignment Operator tester " << endl;
  LinkedQueue<string> assigned_queue;
  assigned_queue.Enqueue("ha");
  assigned_queue.Enqueue("ba");
  assigned_queue = queue;
  cout << assigned_queue << endl;

  cout << "Assigned queue contains, from front to back, ";
  for (int i = 0; i < 6; i++)
    {
      cout << " " << assigned_queue.PeekFront();
      assigned_queue.Dequeue();
    }
  cout << "." << endl;
  
  cout << "Original queue contains, from front to back,";
  for (int i = 0; i < 6; i++) {
    cout << " " << queue.PeekFront();
    queue.Dequeue();
  }
  cout << "." << endl << endl;
}  // end copyConstructorTester

void ConcatenateTester() {
  LinkedQueue<string> queue_1;
  const string items_1[] = {"zero", "one", "two", "three", "four", "five"};

  for (int i = 0; i < 6; i++) {
    queue_1.Enqueue(items_1[i]);
  }
  cout << "Queue 1 is " << queue_1 << endl;


  LinkedQueue<string> queue_2;
  const string items_2[] = {"a", "b", "c", "d"};
  for (int i = 0; i < 4; i++) {
    queue_2.Enqueue(items_2[i]);
  }
  cout << "Queue 2 is " << queue_2 << endl;

  LinkedQueue<string> queue_3 = queue_1 + queue_2;
  cout << "Concatenated queue is " << queue_3 << endl;
}

int main()
{
   CopyConstructorAndAssignmentTester();
   ConcatenateTester();
   return 0;
}  // end main

/*
 Adding zero
 Adding one
 Adding two
 Adding three
 Adding four
 Adding five
 Queue contains, from front to back, zero one two three four five.
 Copy of queue contains, from front to back,  zero one two three four five.
 Original queue contains, from front to back, zero one two three four five.
 
 Testing the Link-based queue:
 Empty: 1
 Adding one
 Adding two
 Adding three
 Adding four
 Adding five
 Adding six
 Empty?: 0
 Loop 0
 PeekFront: one
 Empty: 0
 Dequeue: 1
 Loop 1
 PeekFront: two
 Empty: 0
 Dequeue: 1
 Loop 2
 PeekFront: three
 Empty: 0
 Dequeue: 1
 Loop 3
 PeekFront: four
 Empty: 0
 Dequeue: 1
 Loop 4
 PeekFront: five
 Empty: 0
 Dequeue: 1
 Loop 5
 PeekFront: six
 Empty: 0
 Dequeue: 1
 Dequeue with an empty queue:
 Empty: 1
 Dequeue: 0
 PeekFront with an empty queue:
 PeekFront: Precondition Violated Exception: getFront() called with empty queue.
*/
