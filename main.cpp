#include "single_linked_list.hpp" // Include the single_linked_list.hpp file

using namespace std;

int main() {
    Single_Linked_List<int> my_stack; // Create a stack object
    int choice, value; // Variables to store user input

    do {
        // Display the menu
        cout << "\nChoose an operation:\n";
        cout << "1. Check if the stack is empty\n";
        cout << "2. Push a value onto the stack\n";
        cout << "3. Pop a value from the stack\n";
        cout << "4. Find the top value of the stack\n";
        cout << "5. Find the average of the stack\n";
        cout << "6. Display the stack\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Get user input

        // Perform the operation based on the user's choice
        switch (choice) {
            case 1:
                // Check if the stack is empty
                if (my_stack.is_empty()) {
                    cout << "The stack is empty.\n";
                } else {
                    cout << "The stack is not empty.\n";
                }
                break;

            case 2:
                // Push a value onto the stack
                cout << "Enter a value to push onto the stack: ";
                cin >> value;
                my_stack.push(value);
                cout << "Value " << value << " pushed onto the stack.\n";
                break;

            case 3:
                // Pop a value from the stack
                my_stack.pop();
                break;

            case 4:
                // Find the top value of the stack
                try {
                    cout << "The top value of stack elements is: " <<my_stack.top() << endl;
                } catch(const std::exception& e) {
                    cout << e.what() << '\n';
                }
                break;

            case 5:
                // Find the average of the stack
                try {
                    cout << "The average value of stack elements is: " << my_stack.average() << endl;
                } catch(const std::exception& e)
                {
                    cout << e.what() << '\n';
                }
                break;

            case 6:
                // Display the stack 
                my_stack.display();
                break;
                

            case 0:
                // Exit the program
                cout << "Exiting program. \n";
                break;
            
            default:
                // Invalid choice
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0); // Continue the loop until the user chooses to exit

    return 0;
}