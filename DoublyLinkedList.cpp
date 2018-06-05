#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* prev;
		Node* next;
};

class DoublyLinkedList{
	public:
		Node* end;
		Node* start;
		int count;
	
	DoublyLinkedList(){
		end = NULL;
		start = NULL;
		count = 0;
	}
	
	void insert_start(int num){
		if(count == 0){
			Node* node = new Node();
			node->data = num;
			node->next = NULL;
			node->prev = NULL;
			start = node;
			end = node;
		}
		else{
			Node* node = new Node();
			node->data = num;
			node->next = start;
			start->prev = node;
			node->prev = NULL;
			start = node;
		}
		count++;
		cout<<"INSERTED "<<num<<" AT THE BEGINNING. COUNT: "<<count<<endl;
	}
	
	void insert_end(int num){
		if(count == 0){
			Node* node =  new Node();
			node->data = num;
			node->next = NULL;
			node->prev = NULL;
			start = node;
			end = node;
		}
		
		else{
			Node* temp = start;
			while(temp->next != NULL){
				temp = temp->next;
			}
			Node* node = new Node();
			node->data = num;
			node->prev = temp;
			temp->next = node;
			node->next = NULL;
			end = node;
		}
		count++;
		cout<<"INSERTED "<<num<<" AT THE END. COUNT: "<<count<<endl;
	}
	
	void pop_start(){
		if(count == 0){
			cout<<"Nothing to pop!"<<endl;
			return;
		}
		else if(count == 1){
			Node* temp = start;
			delete temp;
			start = NULL;
			end = NULL;
			count--;
		}
		else{
			Node* temp = start;
			Node* temp1 = start->next;
			temp1->prev = NULL;
			start = temp1;
			delete temp;
			count--;
		}
		cout<<"DELETED FROM THE START. Count: "<<count<<endl;
	}
	
	void pop_end(){
		if(count == 0){
			cout<<"nothing to pop!"<<endl;
			return;
		}
		else if(count == 1){
			Node* temp = start;
			delete temp;
			start= NULL;
			end = NULL;
			count--;
		}
		else{
			Node* temp = start;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->prev->next = temp->next;
			end = temp->prev;
			delete temp;
			count--;
		}
		cout<<"DELETED FROM THE END. Count: "<<count<<endl;
	}
	
	void pop_index(int index){
		if(index > count - 1){
			cout<<"NO ELEMENT FOUND AT INDEX "<<index<<endl;
			return;
		}
		else if(index == 0){
			pop_start();
		}
		else if(index == count - 1){
			pop_end();
		}
		else{
			Node* temp = start;
			for(int i = 0 ; i  <index ; i++){
				temp = temp->next;
			}
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			count--;
		}		
		cout<<"DELETED FROM THE INDEX:"<<index<<" Count: "<<count<<endl;		
	}
	
	void pop_value(int num){
		int ind = 0;
		Node* temp = start;
		while(temp != NULL){
			if(temp->data == num){
				pop_index(ind);
				cout<<"DELETED VALUE: "<<num<<endl;
				return;
			}
			temp = temp->next;
			ind++;
		}
		cout<<num<<" NOT FOUND!"<<endl;
	}
	
	void show(){
		Node* temp = start;
		while(temp !=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
	
};

int main(){
	DoublyLinkedList d;
	d.pop_start();
	d.show();
	d.insert_start(5);
	d.show();
	d.insert_end(21);
	d.show();
	d.insert_start(7);
	d.show();
	d.insert_start(1);
	d.show();
	d.insert_end(18);
	d.show();
	d.pop_start();
	d.show();
	d.pop_start();
	d.show();
	d.insert_start(9);
	d.show();
	d.insert_start(12);
	d.show();
	d.insert_start(241);
	d.show();
	d.pop_end();
	d.show();
	d.pop_end();
	d.show();
	d.pop_index(0);
	d.show();
	d.pop_index(2);
	d.show();
	d.insert_start(14);
	d.show();
	d.insert_end(62);
	d.show();
	d.pop_index(1);
	d.show();
	d.insert_start(91);
	d.show();
	d.insert_start(83);
	d.show();
	d.insert_end(41);
	d.show();
	d.insert_end(75);
	d.show();
	d.pop_value(83);
	d.show();
	d.pop_value(75);
	d.show();
	d.pop_value(9);
	d.show();
	d.pop_value(17);
	d.show();
	return 0;
}
