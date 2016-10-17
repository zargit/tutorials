#include <iostream>

using namespace std;

template<class T>
class Node{
	public:
		T value;
		Node<T>* next;
		Node(){}
		Node(T _value, Node<T>* _next){
			value = _value;
			next = _next;
		}
};

template<class T>
class Stack{
	private:
		Node<T>* head;
	public:
		Stack(){
			head = new Node<T>();
			head->next = NULL;
		}
		void push(T value){
			Node<T>* newNode = new Node<T>(value, head->next);
			head->next = newNode;
		}
		
		T top(){
			if(!isEmpty()){
				return head->next->value;
			}
		}

		void pop(){
			if(!isEmpty()){
				Node<T>* t = head->next;
				head->next = t->next; // t->next is equivalent to head->next->next
			}
		}

		bool isEmpty(){
			return (head->next==NULL);
		}
};

int main(){
	//Stack of integers
	Stack<int> stack;
	for(int i=1;i<=5;i++) stack.push(i);
	while(!stack.isEmpty()){
		cout<<stack.top()<<" ";
		stack.pop();
	}
	return 0;
}
