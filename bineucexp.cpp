#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& v,int num){
	int high = v.size() - 1;
	int low = 0;
	for(int i = 0 ; i < v.size() ;i++){
		int center = (high + low) /2;
		if(v[center] > num){
			high = center - 1;
		}
		else if(v[center] < num){
			low = center + 1;
		}
		else return center;
	}
	return -1;
}


int gcd(int a, int b){
	int num = 0;
	while(b != 0){
		num = a % b;
		a = b;
		b = num;
	}
	return a;
}

int pow(int x, int n){
	if(n == 0) return 1;
	if( n == 1) return x;
	if(n % 2 == 0) return pow(x*x,n/2);
	else return pow(x*x,n/2)*x;
}

int main(){
	vector<int> v{11,22,33,44,55};
	cout<<binarySearch(v,33)<<endl;
	cout<<gcd(70,28)<<endl;
	cout<<gcd(12,18)<<endl;
	cout<<pow(3,5)<<endl;
	cout<<pow(10,3)<<endl;
	return 0;
}
