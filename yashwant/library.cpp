#include <iostream>
#include <vector>

using namespace std;

// To-do list
vector<string> tasks;

// Add a task to the list
void addTask() {
  string task;
  cout << "Enter a task to add: ";
  cin >> task;
  tasks.push_back(task);
}

// View the list of tasks
void viewTasks() {
  cout << "To-do list:" << endl;
  for (int i = 0; i < tasks.size(); i++) {
    cout << i + 1 << ". " << tasks[i] << endl;
  }
}

// Mark a task as completed
void markTaskAsCompleted() {
  int taskNumber;
  cout << "Enter the number of the task to mark as completed: ";
  cin >> taskNumber;
  while (taskNumber < 1 || taskNumber > tasks.size()) {
    cout << "Invalid task number. Please try again." << endl;
    cout << "Enter the number of the task to mark as completed: ";
    cin >> taskNumber;
  }
  tasks[taskNumber - 1] += " (completed)";
}

// Remove a task from the list
void removeTask() {
  int taskNumber;
  cout << "Enter the number of the task to remove: ";
  cin >> taskNumber;
  while (taskNumber < 1 || taskNumber > tasks.size()) {
    cout << "Invalid task number. Please try again." << endl;
    cout << "Enter the number of the task to remove: ";
    cin >> taskNumber;
  }
  tasks.erase(tasks.begin() + taskNumber - 1);
}

// Main menu
int mainMenu() {
  int option;
  cout << "To-do list manager" << endl;
  cout << "1. Add task" << endl;
  cout << "2. View tasks" << endl;
  cout << "3. Mark task as completed" << endl;
  cout << "4. Remove task" << endl;
  cout << "5. Exit" << endl;
  cout << "Enter your choice: ";
  cin >> option;
  return option;
}

int main() {
  int option;
  do {
    option = mainMenu();
    switch (option) {
      case 1:
        addTask();
        break;
      case 2:
        viewTasks();
        break;
      case 3:
        markTaskAsCompleted();
        break;
      case 4:
        removeTask();
        break;
      case 5:
        exit(0);
        break;
      default:
        cout << "Invalid option. Please try again." << endl;
    }
  } while (option != 5);
  return 0;
}
