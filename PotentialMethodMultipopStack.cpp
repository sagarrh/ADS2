#include <iostream>
#include <limits.h>

using namespace std;
#define MAX_SIZE 1000

class Stack {
    int items[MAX_SIZE];
    int top;
    int potential;

public:
    Stack() : top(-1), potential(0) {}

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int item) {
        if (isFull()) {
            cout << "Stack overflow\n";
            return;
        }
        items[++top] = item;

        // Amortized analysis
        potential++;
        cout << "Push: Actual cost = 1, Potential change = 1, Amortized cost = 2\n";
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return INT_MIN;
        }

        // Amortized analysis
        potential--;
        cout << "Pop: Actual cost = 1, Potential change = -1, Amortized cost = 0\n";

        return items[top--];
    }

    void multipop(int k) {
        int items_popped = 0;
        while (!isEmpty() && k > 0) {
            pop();
            items_popped++;
            k--;
        }

        // Amortized analysis
        cout << "Multipop: Actual cost = " << items_popped << ", Potential change = -" << items_popped << ", Amortized cost = 0\n";
    }

    void printStack() {
        cout << "Stack: ";
        for (int i = 0; i <= top; i++) {
            cout << items[i] << " ";
        }
        cout << "\nPotential: " << potential << endl;
    }
};

int main() {
    Stack s;
    int choice, value, k;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Multipop\n";
        cout << "4. Print Stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                value = s.pop();
                if (value != INT_MIN) {
                    cout << "Popped value: " << value << endl;
                }
                break;

            case 3:
                cout << "Enter number of items to pop: ";
                cin >> k;
                s.multipop(k);
                break;

            case 4:
                s.printStack();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
