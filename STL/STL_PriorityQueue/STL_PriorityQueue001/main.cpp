/*
Author: Don Spickler
Creation Date: 2/10/2024
Last Update: 2/10/2024
Description: Simple example of the STL priority queue structure.
User Interface: None
*/

#include <iostream>
#include <queue>

using namespace std;

// Very quick and dirty queue node.
class QueueNode {
protected:
  int Priority;
  string message;

public:
  QueueNode(int priority, string mes) : Priority(priority), message(mes) {}
  int getPriority() const { return Priority; }
  string getMessage() const { return message; }

  bool operator<(const QueueNode &rhs) const {
    return (Priority < rhs.Priority);
  }

  friend ostream &operator<<(ostream &str, const QueueNode &node) {
    return str << node.Priority << "  -  " << node.message;
  }
};

int main() {
  priority_queue<QueueNode> messages;

  messages.push(QueueNode(2, "Important."));
  messages.push(QueueNode(1, "Okay."));
  messages.push(QueueNode(5, "Really important."));
  messages.push(QueueNode(3, "More important."));
  messages.push(QueueNode(2, "Also important."));
  messages.push(QueueNode(5, "Another really important message."));
  messages.push(QueueNode(0, "Don't care."));
  messages.push(QueueNode(1, "Should probably think about this."));

  // Note the output order on the run.
  while (!messages.empty()) {
    QueueNode next = messages.top();
    cout << next << endl;
    messages.pop();
  }

  return 0;
}
