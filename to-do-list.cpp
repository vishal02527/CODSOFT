#include <iostream>
using namespace std;
#include <vector>
#include <iomanip>
#include <string>

struct Task
{
    string description;
    bool completed;

    Task(const string &desc) : description(desc), completed(false) {}
};

class TodoList
{
private:
    vector<Task> tasks;

public:
    void addTask(const string &desc)
    {
        tasks.push_back(Task(desc));
        cout << "\nTask added successfully!\n";
    }

    void viewTasks()
    {
        if (tasks.empty())
        {
            cout << "\nNo tasks in the list.\n";
        }
        else
        {
            cout << setw(5) << "Index" << setw(20) << "Description" << setw(15) << "Status" << endl;
            cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;
            for (size_t i = 0; i < tasks.size(); ++i)
            {
                cout << setw(5) << i + 1 << setw(20) << tasks[i].description << setw(15)
                     << (tasks[i].completed ? "Completed" : "Pending") << endl;
            }
        }
    }

    void markTaskCompleted(size_t index)
    {
        if (index >= 1 && index <= tasks.size())
        {
            tasks[index - 1].completed = true;
            cout << "\nTask marked as completed.\n";
        }
        else
        {
            cout << "\nInvalid task index.\n";
        }
    }

    void removeTask(size_t index)
    {
        if (index >= 1 && index <= tasks.size())
        {
            tasks.erase(tasks.begin() + index - 1);
            cout << "\nTask removed successfully.\n";
        }
        else
        {
            cout << "\nInvalid task index.\n";
        }
    }
};

int main()
{
    TodoList todoList;

    while (true)
    {
        cout << "\n===== TO-DO LIST MANAGER =====\n\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";

        int choice;
        cout << "\nEnter your choice (1-5): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\n1. Add Task\n";
            string taskDesc;
            cout << "\nEnter task description: ";
            cin.ignore();
            getline(cin, taskDesc);
            todoList.addTask(taskDesc);
            break;
        }
        case 2:
            cout << "\n2. View Tasks\n\n";
            todoList.viewTasks();
            break;
        case 3:
        {
            cout << "\n3. Mark Task as Completed\n";
            size_t index;
            cout << "\nEnter the task number to mark as completed: ";
            cin >> index;
            todoList.markTaskCompleted(index);
            break;
        }
        case 4:
        {
            cout << "\n4. Remove Task\n";
            size_t index;
            cout << "\nEnter the task number to remove: ";
            cin >> index;
            todoList.removeTask(index);
            break;
        }
        case 5:
            cout << "\nExiting the program. Goodbye!\n\n";
            return 0;
        default:
            cout << "\nInvalid choice. Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}
