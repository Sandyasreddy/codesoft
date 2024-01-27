import json

def load_tasks():
    try:
        with open('tasks.json', 'r') as file:
            tasks = json.load(file)
    except FileNotFoundError:
        tasks = []
    return tasks

def save_tasks(tasks):
    with open('tasks.json', 'w') as file:
        json.dump(tasks, file)

def show_tasks(tasks):
    if not tasks:
        print("No tasks found. Start by adding some!")
    else:
        print("Your To-Do List:")
        for i, task in enumerate(tasks, 1):
            print(f"{i}. {task}")

def add_task(tasks, new_task):
    tasks.append(new_task)
    save_tasks(tasks)
    print(f"Task '{new_task}' added successfully!")

def update_task(tasks, task_index, updated_task):
    tasks[task_index] = updated_task
    save_tasks(tasks)
    print(f"Task {task_index + 1} updated successfully!")

def delete_task(tasks, task_index):
    removed_task = tasks.pop(task_index)
    save_tasks(tasks)
    print(f"Task {task_index + 1} ('{removed_task}') deleted successfully!")

def main():
    tasks = load_tasks()

    while True:
        print("\n1. Show Tasks\n2. Add Task\n3. Update Task\n4. Delete Task\n5. Exit")
        choice = input("Choose an option (1-5): ")

        if choice == '1':
            show_tasks(tasks)
        elif choice == '2':
            new_task = input("Enter the new task: ")
            add_task(tasks, new_task)
        elif choice == '3':
            show_tasks(tasks)
            task_index = int(input("Enter the task number to update: ")) - 1
            updated_task = input("Enter the updated task: ")
            update_task(tasks, task_index, updated_task)
        elif choice == '4':
            show_tasks(tasks)
            task_index = int(input("Enter the task number to delete: ")) - 1
            delete_task(tasks, task_index)
        elif choice == '5':
            print("Exiting the To-Do List Application. Goodbye!")
            break
        else:
            print("Invalid choice. Please choose a number between 1 and 5.")

if _name_ == "_main_":
    main()
