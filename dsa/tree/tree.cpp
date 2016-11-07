// Generic Tree Sample
#include <iostream>
#include <vector>

using namespace std;

template<class T>
struct Node{
	T value;
	vector< Node<T>* > brances;	
};

int main(){
	Node<int>* root = new Node<int>();
}
