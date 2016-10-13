#include <iostream>

using namespace std;

struct Term{
	int co;
	int deg;
	Term* next;
	Term(){		
		co = 0; deg = 0; next = NULL;
	}
	Term(int _co, int _deg, Term* _next){
		co = _co;
		deg = _deg;
		next = _next;
	}
};

class Equation{
	private:
		Term* head;
	public:
		Equation(){
			head = new Term();
			head->next = NULL;
		}	
		/*void insert(int co, int deg){
			Term* t = head;
			while(t->next!=NULL){
				t = t->next;
			}
			t->next = new Term(co,deg,NULL);
		}*/
		void insert(int co, int deg){
			Term* t = head;
			while(t->next!=NULL){
				if(deg>t->next->deg){ // higher degree always goes before smaller degree
					Term* newTerm = new Term(co,deg,t->next);
					t->next = newTerm;
					return;
				}else if(deg==t->next->deg){ // when degree is same, add the coefficients
					t->next->co += co;
					return;
				}
				t = t->next;
			}
			if(t->next==NULL) t->next = new Term(co,deg,NULL);
		}

		void display(){
			Term* t = head;
			while(t->next!=NULL){
				
				if(t->next->co<0) cout<<"- ";
				else if(t!=head) cout<<"+ ";

				cout<<abs(t->next->co);

				if(t->next->deg==1) cout<<"x ";
				else if(t->next->deg>1) cout<<"x^"<<t->next->deg<<" ";

				t = t->next;
			}
			cout<<endl;
		}

		Equation convertStringToEquation(string str){
			Equation eq;

			return eq;
		}
};

int main(){
	Equation eq1;
	
	//Comment out the following lines to take input from console
	
	int c,d;
	while(cin>>c>>d){
		eq1.insert(c,d);
	}
	eq1.display();
	
	
	//Uncomment the following lines for console input//
	
	/*int n,c,d;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c>>d;
		eq1.insert(c,d);
	}	
	eq1.display();
	*/
}
