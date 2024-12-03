/*
Author: Don Spickler
Creation Date: 2/10/2024
Last Update: 2/10/2024
Description: Simple example of the STL priority queue structure.
User Interface: None
Notes: This version uses a pair datatype for the queue elements.
This is very convenient since the pair is templated we can easily
choose the key and value datatypes from any ordered built-in type
or from our own construction.
*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
  priority_queue<pair<int, string>> messages;

  messages.push({2, "Important."});
  messages.push({1, "Okay."});
  messages.push({5, "Really important."});
  messages.push({3, "More important."});
  messages.push({2, "Also important."});
  messages.push({5, "Another really important message."});
  messages.push({0, "Don't care."});
  messages.push({1, "Should probably think about this."});

  // Note the output order on the run.
  while (!messages.empty()) {
    auto next = messages.top();
    cout << next.first << "  " << next.second << endl;
    messages.pop();
  }

  return 0;
}
