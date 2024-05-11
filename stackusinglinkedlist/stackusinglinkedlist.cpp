
#include <iostream>
using namespace std;

// Node class representing a single node in the linked list
class Node {
public:
	int data;
	Node* next;

	Node() {
		next = NULL;
	}
};
// stack class
class Stack {
private:
	Node* top; // pointer to the node of the stack
public:
	Stack() {
		top = NULL; //initialize the stack with a null top pointer
	}

	// push opertation : insert an element onto the top of the stack
	int push(int value) {
		Node* newNode = new Node(); //1. allocate memory for the new node
		newNode->data = value; // 2. assign value
		newNode->next = top; // 3. set the next pointer of the new node to the current to node
		top = newNode; // 4. update the top pointer to the new node
		cout << "push value: " << value << endl;
		return value;

	}
	//pop operation : remove the topmost element from the stack
	void pop() {
		if (isEmpty()) {
			cout << "stack is empty." << endl;

		}
		cout << "Popped value: " << top->data << endl;
		top = top->next; // update the top pointer to the next node
	}
	//peek/top operation: retrieve the value of the topmost element without removing it
	void peek() {
		if (top == NULL) {
			cout << "List is empty." << endl;
		}
		else {
			Node* current = top;
			while (current != NULL) {
				cout << current->data << " " << endl;
				current = current->next;
			}
			cout << endl;
		}// return the value of the top node
	}
	// IsEmpty operation: check if the stack is empty
	bool isEmpty() {
		return top == NULL; //Return true if top pointr is NULL, indicating an empty stack

	}
};
int main() {
	Stack stack;
	int choice = 0;
	int value;

	while (choice != 4) {
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Peek\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter the value to push: ";
			cin >> value;
			stack.push(value);
			break;

		case 2:
			if (!stack.isEmpty()) {
				stack.pop();
			}
			else {
				cout << "Stack is empty. Cannot pop.\n";
			}
			break;
		case 3:
			if (!stack.isEmpty()) {
				stack.peek();
			}
			else {
				cout << "Stack is empty. No top value.\n";
			}
			break;
		case 4:
			cout << "Exiting program.\n";
			break;
		default:
			cout << "Invalid choice. Please enter a number from 1 to 4.\n";
			break;
		}
	}
	return 0;
}