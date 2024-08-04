#include <bits/stdc++.h>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

vector<Task> tasks;

void displayMenu() {
    cout << "\nTo-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

void addTask() {
    cout << "Enter task description: ";
    string description;
    cin.ignore();
    getline(cin, description);

    if (description.empty()) {
        cout << "Task description cannot be empty.\n";
        return;
    }

    tasks.emplace_back(description);
    cout << "Task added successfully.\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks to display.\n";
        return;
    }

    cout << "\nTasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description 
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskAsCompleted() {
    if (tasks.empty()) {
        cout << "No tasks to mark as completed.\n";
        return;
    }

    cout << "Enter the task number to mark as completed: ";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    if (tasks[taskNumber - 1].completed) {
        cout << "Task is already marked as completed.\n";
        return;
    }

    tasks[taskNumber - 1].completed = true;
    cout << "Task marked as completed.\n";
}

void removeTask() {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }

    cout << "Enter the task number to remove: ";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks.erase(tasks.begin() + taskNumber - 1);
    cout << "Task removed successfully.\n";
}

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
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
                cout << "Exiting To-Do List Manager. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
