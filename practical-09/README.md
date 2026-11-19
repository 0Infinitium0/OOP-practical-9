# Practical 09: Generic Stack Using Templates

- **Student Name:** Satinderpal Singh Chaney
- **Roll Number:** E26B00S2034

## Aim
To understand generic programming and how one class can work with multiple data types.

## Question
Write a generic `Stack` or `Queue` class using templates and test it with `int`, `float`, and `std::string` values.

## How Templates Avoid Writing Three Separate Implementations
By parameterizing the class over a type parameter (`template <typename T> class Stack`), the push, pop, top, and empty-check logic is written once against `T` using `std::vector<T>`. When `Stack<int>`, `Stack<float>`, and `Stack<std::string>` are instantiated, the C++ compiler automatically generates type-safe specializations for each concrete type at compile time—eliminating code duplication (`IntStack`, `FloatStack`, `StringStack`) and centralizing bug fixes and edge-case handling.

## Test Cases Covered
1. **Normal LIFO Operations (`Stack<int>`, `Stack<float>`, `Stack<std::string>`):** Pushes three elements onto each stack, inspects the top element via `top()`, and removes/returns the most recently inserted element via `pop()`.
2. **Empty-Container Handling (`Stack<int>` empty test):** Attempts to `pop()` from an empty stack; `isEmpty()` detects the empty state safely, reports an error message, and returns `std::nullopt` instead of triggering undefined behavior.

## Compilation & Execution

### Windows (PowerShell / MinGW `g++`)
```powershell
g++ -std=c++17 -Wall -Wextra practical9.cpp -o practical9.exe
.\practical9.exe
```

### Linux / macOS (`g++` / `clang++`)
```bash
g++ -std=c++17 -Wall -Wextra practical9.cpp -o practical9
./practical9
```

## Memory-Checking Instructions

### Option 1: AddressSanitizer & UndefinedBehaviorSanitizer (GCC / Clang — Linux, macOS, WSL)
```bash
g++ -std=c++17 -g -O1 -fsanitize=address,undefined practical9.cpp -o practical9_asan
./practical9_asan
```

### Option 2: Valgrind (Linux / WSL)
```bash
g++ -std=c++17 -g practical9.cpp -o practical9_dbg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./practical9_dbg
```
Expected summary: `All heap blocks were freed -- no leaks are possible` and `0 errors from 0 contexts`.

## Uploading to GitHub
1. Create a new repository on GitHub (for example, `practical-09-generic-stack-templates` or `practical 9`).
2. Extract the ZIP archive into a local folder and push:
   ```bash
   git init
   git add .
   git commit -m "Add Practical 09: Generic Stack Using Templates"
   git branch -M main
   git remote add origin <YOUR_GITHUB_REPOSITORY_URL>
   git push -u origin main
   ```
