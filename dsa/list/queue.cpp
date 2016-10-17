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
class Queue{
	private:
		Node<T>* front;
		Node<T>* rear;
	public:
		Queue(){
			front = new Node<T>();
			front->next = NULL;

			rear = new Node<T>();
			rear->next = NULL;
		}
		void push(T value){
			Node<T>* newNode = new Node<T>(value, NULL);
			if(front->next==NULL){
				front->next = newNode;
			}
			rear->next = newNode; // maintains the chain
			rear = newNode; // makes the new node the rear node
		}
		
		T getFront(){
			if(!isEmpty()){
				return front->next->value;
			}
		}

		void pop(){
			if(!isEmpty()){
				Node<T>* t = front->next;
				front->next = t->next; // t->next is equivalent to head->next->next
			}
		}

		bool isEmpty(){
			return (front->next==NULL);
		}
};

int main(){
	//Queue of integers
	string arr[3] = {"blah", "another blah", "-_-"};
	Queue<string> q;
	for(int i=0;i<3;i++) q.push(arr[i]);
	while(!q.isEmpty()){
		cout<<q.getFront()<<" ";
		q.pop();
	}
	return 0;
}
