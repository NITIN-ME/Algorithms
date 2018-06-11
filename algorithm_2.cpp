#include<iostream>
#include<vector>
using namespace std;

int max(int a, int b, int c){
	int max = a>b?a:b;
	max = max>c?max:c;
	return max;
}

void show(vector<int> &a){
	for(int i = 0 ; i  < a.size(); i++){
		cout<<a[i]<<"  ";
	}
	cout<<endl;
}

int Algorithm1(vector<int> &a){
	int max = 0;
	for(int i = 0 ; i < a.size(); i++){
		for(int j = 0 ; j < a.size(); j++){
			int thissum = 0;
			for(int z = i; z <= j; z++){
				thissum += a[z];
			}
			if(thissum > max){
				max = thissum;
			}
		}
	}
	return max;
}

int Algorithm2(vector<int>& a){
	int max = 0;
	for(int i = 0  ; i < a.size(); i++){
		int thissum = 0;
		for(int j = i; j < a.size(); j++){
			thissum += a[j];
			if(thissum > max){
				max = thissum;
			}
		}
	}
	return max;
}


int Algorithm3(vector<int> &a, int low, int high){
	if(low == high){
		if(a[high] >0){
			return a[high];
		}
		else{
			return 0;
		}
	}
	int mid = (low+high)/2;
	int l = Algorithm3(a, low, mid);
	int r = Algorithm3(a, mid+1, high);
	
	int lmax = 0, lbordermax = 0;
	for(int i = mid; i >= low; i--){
		lmax += a[i];
		if(lmax > lbordermax){
			lbordermax = lmax;
		}
	}
	
	int rmax = 0, rbordermax = 0;
	for(int i = mid + 1; i <= high; i++){
		rmax += a[i];
		if(rmax > rbordermax){
			rbordermax = rmax;
		}
	}
	
	return max(l, r, lbordermax + rbordermax);
}





int Algorithm4(vector<int> &a){
	int thissum = 0, maxsum = 0;
	for(int i =0 ; i < a.size(); i++){
		thissum += a[i];
		if(thissum > maxsum){
			maxsum = thissum;
		}
		if(thissum < 0){
			thissum = 0;
		}
	}
	return maxsum;
}

int pow(int m, int n){
	if(n == 0) return 1;
	else if(n == 1) return m;
	else if(n % 2 == 0) return pow(m*m, n/2);
	else return pow(m*m, n/2) * m;
}

int main(){
	vector<int> arr = {1,-3,2,-5,7,6,-1,-4,11,-23};
	show(arr);
	cout<<Algorithm1(arr)<<endl;
	cout<<Algorithm2(arr)<<endl;
	cout<<Algorithm3(arr, 0, arr.size() - 1)<<endl;
	cout<<Algorithm4(arr)<<endl;
	cout<<pow(3,5)<<endl;
	return 0;
}
