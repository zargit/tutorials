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
class List{
	private:
		Node<T>* head = NULL;
	public:
		List(){
			head = new Node<T>();
		}
		void insert(T value){
			Node<T>* t = head;
			while(t->next!=NULL){
				t = t->next;
			}
			t->next = new Node<T>(value, NULL);
		}

		bool find(T value){
			Node<T>* t = head;
			while(t->next!=NULL){
				if(t->next->value==value) return true;
				t = t->next;
			}
			return false;
		}

		bool update(T oldValue, T newValue){
			Node<T>* t = head;
			while(t->next!=NULL){
				if(t->next->value==oldValue){
					t->next->value = newValue;
					return true;
				}
			}
			return false;
		}

		bool remove(T value){
			Node<T> *t = head, *prev;
			while(t->next!=NULL){
				prev = t->next;
				if(t->next->value==value){
					t->next = t->next->next;
					delete prev;
					return true;
				}
				t = t->next;
			}
			return false;
		}

		void display(){
			Node<T>* t = head;
			while(t->next!=NULL){
				cout<<t->next->value<<" -> ";
				t = t->next;
			}
			cout<<"end"<<endl;
		}
};

int main(){
	//List of integers
	List<int> list;
	list.display();
	for(int i=0;i<5;i++){
		list.insert(i);
		list.display();
	}
	for(int i=4;i>=0;i--){
		list.remove(i);
		list.display();
	}
	//List of characters
	List<char> slist;
	for(char a='a';a<='z';a++){
		slist.insert(a);
		slist.display();
	}
	for(char z='z';z>='a';z--){
		slist.remove(z);
		slist.display();
	}
	return 0;
}
