#include <iostream>
#include <vector>
#include <string>
#include <optional>
#include <initializer_list>

/**
 * Generic Stack Class Template (`Stack<T>`)
 *
 * Uses `std::vector<T>` internally to store elements in LIFO (Last-In, First-Out) order.
 * A single template definition enables type-safe compilation for `int`, `float`,
 * `std::string`, or any copyable/movable type without duplicating class logic.
 */
template <typename T>
class Stack {
private:
    std::vector<T> elements_;

public:
    Stack() = default;

    // Pushes a single element onto the top of the stack
    void push(const T& value) {
        elements_.push_back(value);
    }

    // Convenience helper to push a sequence of items and display them
    void pushBatch(std::initializer_list<T> items) {
        std::cout << "Pushing:";
        for (const auto& item : items) {
            std::cout << " " << item;
            push(item);
        }
        std::cout << "\n";
    }

    // Checks whether the stack has no elements
    bool isEmpty() const {
        return elements_.empty();
    }

    // Safely accesses the top element without removing it (`std::nullopt` if empty)
    std::optional<T> top() const {
        if (isEmpty()) {
            return std::nullopt;
        }
        return elements_.back();
    }

    // Safely pops and returns the top element (`std::nullopt` if empty)
    std::optional<T> pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty!\n";
            std::cout << "Cannot pop from an empty stack. ";
            return std::nullopt;
        }
        T topValue = std::move(elements_.back());
        elements_.pop_back();
        return topValue;
    }
};

int main() {
    std::cout << "----- GENERIC STACK USING TEMPLATES -----\n";
    std::cout << "Student Name: Satinderpal Singh Chaney\n";
    std::cout << "Roll Number: E26B00S2034 ";

    // 1. Integer Stack
    std::cout << "----- INTEGER STACK -----\n";
    Stack<int> intStack;
    intStack.pushBatch({10, 20, 30});
    if (auto topVal = intStack.top()) {
        std::cout << "Top Element: " << *topVal << "\n";
    }
    if (auto poppedVal = intStack.pop()) {
        std::cout << "Popped Element: " << *poppedVal << "\n";
    }

    // 2. Float Stack
    std::cout << "----- FLOAT STACK -----\n";
    Stack<float> floatStack;
    floatStack.pushBatch({10.5f, 20.5f, 30.5f});
    if (auto topVal = floatStack.top()) {
        std::cout << "Top Element: " << *topVal << "\n";
    }
    if (auto poppedVal = floatStack.pop()) {
        std::cout << "Popped Element: " << *poppedVal << "\n";
    }

    // 3. String Stack
    std::cout << "----- STRING STACK -----\n";
    Stack<std::string> stringStack;
    stringStack.pushBatch({"C++", "Programming", "Practical"});
    if (auto topVal = stringStack.top()) {
        std::cout << "Top Element: " << *topVal << "\n";
    }
    if (auto poppedVal = stringStack.pop()) {
        std::cout << "Popped Element: " << *poppedVal << "\n";
    }

    // 4. Empty Stack Edge-Case Test
    std::cout << "----- EMPTY STACK TEST -----\n";
    Stack<int> emptyStack;
    emptyStack.pop();

    std::cout << "Template Stack Demonstrated Successfully!\n";
    std::cout << "Program executed successfully.\n";

    return 0;
}
