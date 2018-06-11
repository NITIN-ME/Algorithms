#include<bits/stdc++.h>
using namespace std;

class Vector{
	private:
		int thesize;
		int thecapacity;
		int* arr;
	public:
		explicit Vector(int initsize = 0):thesize{initsize}, thecapacity{initsize + 5}{
			arr = new int[thecapacity];
		}
		
		
		Vector(const Vector& rhs):thesize{rhs.thesize}, thecapacity{rhs.thecapacity}, arr{nullptr}{
			arr = new int[thecapacity];
			for(int i = 0; i < thesize; i++){
				arr[i] = rhs.arr[i];
			}
		}
		
		Vector& operator=(const Vector& rhs){
			Vector copy = rhs;
			swap(*this, copy);
			return *this;
		}
		
		~Vector(){
			delete[] arr;
		}
		
		Vector(Vector&& rhs):thesize{rhs.thesize}, thecapacity{rhs.thecapacity}, arr{rhs.arr}{
			rhs.arr = nullptr;
			rhs.thesize = 0;
			rhs.thecapacity = 0;
		}
		
		Vector& operator=(Vector&& rhs){
			swap(thesize, rhs.thesize);
			swap(thecapacity, rhs.thecapacity);
			swap(arr, rhs.arr);
			return *this;
		}
		
		void resize(int newsize){
			if(newsize > thecapacity){
				reserve(newsize*2);
			}
			thesize = newsize;
		}
		
		void reserve(int newcapacity){
			if(newcapacity < thesize) return;
			int* newarray = new int[newcapacity];
			for(int k =0 ; k < thesize; k++){
				newarray[k] = move(arr[k]);
			}
			thecapacity = newcapacity;
			swap(arr, newarray);
			delete[] newarray;
		}
		
		int& operator[](int index){
			return arr[index];
		}
		
		const int& operator[](int index) const{
			return arr[index];
		}
		
		bool empty() const{
				return size() == 0;
		}
		
		int size() const{
				return thesize;
		}
		
		int capacity() const{
				return thecapacity;
		}
		
		void push_back(const int& x){
			if(thesize == thecapacity){
				reserve(2*thecapacity+1);
			}
			arr[thesize++] = x;
		}
		
		void push_back(int&& x){
			if(thesize == thecapacity){
				reserve(2*thecapacity+1);
			}
			arr[thesize++] = move(x);
		}
		
		void pop_back(){
			--thesize;
		}
		
		const int& back() const{
				return arr[thesize - 1];
		}
		
		typedef int* iterator;
		typedef const int* const_iterator;
		
		iterator begin(){
			return &arr[0];
		}
		
		const_iterator begin() const{
				return &arr[0];
		}
		
		iterator end(){
			return &arr[size()];
		}
		
		const_iterator end() const{
				return &arr[0];
		}
		
		void show(){
			cout<<"[ ";
			/*for(int i = 0 ; i < thesize; i++){
				cout<<arr[i]<<"  ";
			}*/
			for(Vector::iterator i = begin(); i != end(); i++){
				cout<<*i<<"  ";
			}
			cout<<"]"<<endl;
		}
};


int main(){
	Vector v(0);
	v.push_back(5);
	v.push_back(10);
	v.push_back(15);
	v.push_back(20);
	v.push_back(25);
	v.push_back(30);
	v.push_back(35);
	v.push_back(40);
	v.push_back(45);
	v.push_back(50);
	v.push_back(55);
	v.push_back(60);
	cout<<v.size()<<endl;
	cout<<v.capacity()<<endl;
	v.show();
	return 0;
}
