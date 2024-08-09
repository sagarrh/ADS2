#include <iostream>
#include <stack>
using namespace std;

void displayStack(stack<int> a) {
    if (a.empty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    stack<int> temp;
    while (!a.empty()) {
        temp.push(a.top());
        a.pop();
    }
    while (!temp.empty()) {
        cout << temp.top() << ' ';
        a.push(temp.top());
        temp.pop();
    }
    cout << endl;
}

int main() {
    stack<int> a;
    int input;
    while (true) {
        cout << "Enter your choice: 1.push 2.pop 3.multipop 4.display 5.exit: ";
        cin >> input;
        switch (input) {
            case 1: {
                int val;
                cout << "Enter value: ";
                cin >> val;
                a.push(val);
                break;
            }
            case 2: {
                if (a.empty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    a.pop();
                    cout << "Popped one element." << endl;
                }
                break;
            }
            case 3: {
                int val2;
                cout << "How many elements to pop? ";
                cin >> val2;
                for (int i = 0; i < val2; i++) {
                    if (a.empty()) {
                        cout << "Stack is empty. Stopping multipop." << endl;
                        break;
                    } else {
                        a.pop();
                    }
                }
                break;
            }
            case 4: {
                displayStack(a);
                break;
            }
            case 5: {
                cout << "Exiting program." << endl;
                return 0;
            }
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}
