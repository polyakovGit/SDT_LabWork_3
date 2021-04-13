#include <iostream>

template<typename arrayType>
arrayType maxNeg(arrayType arr[], const int size) {
	int index = -1;
	arrayType min = arr[size - 1];
	for (int i = size - 1; i > 0; --i) {
		if (arr[i]<0 && arr[i]>min) {
			min = arr[i];
			index = i;
		}
	}
	if (index != -1)
		return min;
	else return 0;
}

template <typename T>
class Stack {
	struct Node {
		T value;
		Node* next;
		explicit Node(T value) : value(value), next(nullptr) {}
	};
	Node* head;
	int count;
public:
	Stack(const Stack* stack) {
		count = 0;
		Node* source = stack->head;
		while (source) {
			Node* temp = new Node(source->value);
			temp->next = head;
			head = temp;
			source = source->next;
			temp = source;
			++count;
		}
		Reverse();
	}

	Stack() :head(nullptr), count(0) {};

	void Push(T value) {
		Node* temp = new Node(value);
		temp->next = head;
		head = temp;
		++count;
	}

	~Stack() {
		while (head) {
			Node* temp = head->next;
			delete head;
			head = temp;
		}
	}

	void Pop() {
		if (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
			--count;
		}
	}

	void Print() {
		Node* temp = head;
		while (temp) {
			std::cout << temp->value << ' ';
			temp = temp->next;
		}
		std::cout << '\n';
	}

	void Reverse() {
		if (!head)return;
		Node* curr = head, * next, * prev = nullptr;
		while (curr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}

	void Clear() {
		while (head) {
			Node* temp = head->next;
			delete head;
			head = temp;
		}
	}

	//friend const Stack operator+(const Stack& left, const T right);

	Stack& operator=(const Stack& stack) {
		if (this != &stack) {
			Clear();
			Node* temp = stack.head;
			while (temp) {
				this->Push(temp->value);
				temp = temp->next;
			}
			Reverse();
		}
		return *this;
	}

	const Stack operator+(const T right) {
		this.Push(right);
		return this;
	}
	Stack& operator--()
	{
		this->Pop();
		return *this;
	}
	Stack& operator--(T) {
		Stack* newStack = new Stack(this);
		--* this;
		return *newStack;
	}
	operator bool() {
		if (head)
			return true;
		return false;
	}
	//friend Stack& operator--(Stack& stack);
	//friend Stack operator--(Stack& stack, T);
};



int  main() {
	Stack<int> stack;
	stack.Push(2);
	if (stack)
		std::cout << "y\n";
	stack.Push(3);
	Stack<int> oldStack(stack--);
	stack.Print();
	oldStack.Print();
	oldStack = stack;
	oldStack.Print();
	return 0;
}
