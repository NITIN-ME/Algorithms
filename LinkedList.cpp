#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

class LinkedList{
	public:
	Node* start;
	int count = 0;
	
	LinkedList(){
		//start = new Node();
		start = NULL;
		cout<<"Constructor called"<<endl;
	}
	
	void insert_start(int num){
		if(start == NULL){
			Node* node = new Node();
			node->data = num;
			node->next = NULL;
			start = node;
		}
		else{
			Node* node = new Node();
			node->data = num;
			node->next = start;
			start = node;
		}
		count++;
		cout<<"Inserting "<<num<<" at the beginning."<<" Count: "<<count<<endl;
	}
	
	void insert_end(int num){
		if(count == 0){
			Node* node = new Node();
			node->data = num;
			node->next = NULL;
			start = node;
		}
		else{
			Node* temp = start;
			while(temp->next!= NULL){
				temp = temp->next;
			}
			Node* node = new Node();
			node->data = num;
			temp->next = node;
			node->next = NULL;
		}
		count++;
		cout<<"Inserting "<<num<<" at the end."<<" Count: "<<count<<endl;
	}
	
	void pop_start(){
		if(count == 0){
			cout<<"No element to pop!"<<endl;
		}
		else{
			Node* temp = start;
			start = temp->next;
			delete temp;
			count--;
			cout<<"DELETED FROM START. Count: "<<count<<endl;
		}
	}
	
	void pop_end(){
		if(count == 0){
			cout<<"No element to pop!"<<endl;
		}
		else if(count == 1){
			start = NULL;
			count--;
			cout<<"DELETED FROM END. Count: "<<count<<endl;
		}
		else{
			Node* temp = start;
			while(temp->next->next != NULL){
				temp = temp->next;
			}
			Node* temp1 = temp->next;
			temp->next = temp->next->next;
			delete temp1;
			count--;
			cout<<"DELETED FROM END. Count: "<<count<<endl;
		}
	}
	
	void pop_index(int index){
		if(index > count-1){
			cout<<"No element found at index: "<<index<<endl;
		}
		else{
			if(index == 0){
				pop_start();
				cout<<"ELEMENT DELETED FROM INDEX: "<<index<<endl;
			}
			else if(index == count - 1){
				pop_end();
				cout<<"ELEMENT DELETED FROM INDEX: "<<index<<endl;
			}
			else{
				Node* temp = start;
				for(int i = 0 ; i < index - 1; i ++){
					temp = temp->next;
				}
				Node* temp1 = temp->next;
				temp->next = temp1->next;
				delete temp1;
				count--;
				cout<<"ELEMENT DELETED FROM INDEX: "<<index<<" Count: "<<count<<endl;
			}
		}
	}
	
	void pop_value(int val){
		int ind = 0;
		Node* temp = start;
		while(temp != NULL){
			if(temp->data == val){
				pop_index(ind);
				cout<<"ELEMENT DELETED VALUE: "<<val<<endl;
				break;
			}
			else{
				temp = temp->next;
				ind++;
			}
		}
	}
	
	void show(){
		Node* node = start;
		while(node != NULL){
			cout<<node->data<<" ";
			node = node->next;
		}
		cout<<endl;
	}
	
	
};

int main(){
	LinkedList l;
	l.pop_start();
	l.show();
	l.pop_end();
	l.show();
	l.insert_end(100);
	l.show();
	l.pop_end();
	l.show();
	l.insert_start(5);
	l.show();
	l.insert_start(8);
	l.show();
	l.insert_start(9);
	l.show();
	l.insert_end(27);
	l.show();
	l.insert_start(1);
	l.show();
	l.insert_start(0);
	l.show();
	l.insert_start(11);
	l.show();
	l.insert_end(16);
	l.show();
	l.insert_end(99);
	l.show();
	l.pop_end();
	l.show();
	l.pop_start();
	l.show();
	l.pop_start();
	l.show();
	l.pop_start();
	l.show();
	l.pop_end();
	l.show();
	l.pop_index(0);
	l.show();
	l.pop_index(2);
	l.show();
	l.insert_end(7);
	l.show();
	l.insert_end(9);
	l.show();
	l.insert_start(12);
	l.show();
	l.pop_index(2);
	l.show();
	l.pop_value(7);
	l.show();
	l.pop_value(9);
	l.show();
	l.pop_value(12);
	l.show();
	l.pop_value(8);
	l.show();
	l.pop_start();
	l.show();
	return 0;
}
