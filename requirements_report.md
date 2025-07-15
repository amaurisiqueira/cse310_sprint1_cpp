# Requirements Report – C++ Task Manager

## Basic Requirements

- **Variables:** Used throughout the program (e.g., `int id`, `string description`).
- **Expressions:** Arithmetic and logical expressions are used in loops and conditionals.
- **Conditionals:** Multiple `if` and `switch` statements used to control logic.
- **Loops:** Used `for` and `while` loops for iteration (e.g., listing tasks, reading files).
- **Functions:** The program is fully structured with functions and methods (e.g., `add`, `list`, `complete`).
- **Classes:** Defined `myStructureManager` class with attributes and methods.
- **STL data structures:** Uses `vector` and `string` from the Standard Template Library.

## Additional Requirement Chosen

- **Read and write to a file:**  
  The program reads from and writes to `my_task.txt` using `ifstream` and `ofstream`.

## Optional

- **Dynamic memory:**  
  The class `myStructureManager` and the `vector<Task_t>` are dynamically allocated using `new` and cleaned with `delete`.

## How the program works

- The user interacts via a terminal menu to add, complete, delete, or list tasks.
- Tasks are saved in a file between runs.
- All logic is encapsulated in classes and follows good modular structure.
