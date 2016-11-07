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
			Node<T>* newNode = new Node<T>(value,NULL);
			if(front->next==NULL){ // only for the first node
				front->next = newNode;
			}
			rear->next = newNode;
			rear = newNode;
		}

		T getFront(){
			if(!isEmpty()){
				return front->next->value;	
			}
		}

		void pop(){
			if(!isEmpty()){
				// when q is not empty
				Node<T>* t = front->next;
				front->next = t->next;
				delete t;
			}
		}

		bool isEmpty(){
			return (front->next==NULL);
		}
};

int main(){
	//Queue of integers
	Queue<int> q;
	for(int i=1;i<=5;i++) q.push(i);
	while(!q.isEmpty()){
		cout<<q.getFront()<<" ";
		q.pop();
	}
	return 0;
}
