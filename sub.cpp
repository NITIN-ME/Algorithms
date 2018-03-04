#include<iostream>
#include<vector>
using namespace std;


int max(int a, int b, int c){
	int m1 = (a > b)?a:b;
	int m2 = (m1 > c)?m1:c;
	return m2;
}

/* If atleast one number is positive. */


/* O(n^3) */
int maxfind1(vector<int>& v){
	int maxsum = 0;
	for(int i = 0; i < v.size(); i++){
		for(int j = 0 ; j < v.size() ; j++){
			int sum = 0;
			for(int z = i ; z <= j ; z++){
				sum += v[z];
			}
			if(sum > maxsum) maxsum = sum;
		}
	}
	return maxsum;
}


/* O(n^2) */
int maxfind2(vector<int>& v){
	int maxsum = 0;
	for(int i = 0 ;i < v.size() ; i++){
		int sum = 0;
		for(int j = i ; j < v.size() ; j++){
			sum += v[j];
			if(sum > maxsum) maxsum = sum;
		}
	}
	return maxsum;
}

/*  O(N*log(N)) */
int maxfindthreealgo(vector<int>& v,int low, int high){
	if(low == high){
		if(v[low] > 0) return v[low];
		else return 0;
	}
	
	//cout<<"Here"<<endl;
	
	int center = (low + high) / 2;
	int maxleft = maxfindthreealgo(v,low,center);
	int maxright = maxfindthreealgo(v,center+1,high);
	
	int maxleftsum = 0;
	int a = 0;
	for(int i = center; i >= low; --i){
		a += v[i];
		if(a > maxleftsum) maxleftsum = a;
	}
	
	
	int maxrightsum = 0;
	int b = 0;
	for(int j = center + 1; j <= high; j++){
		b += v[j];
		if(b > maxrightsum) maxrightsum = b;
	}
	//cout<<"max is : "<<max(maxleft, maxright, maxrightsum + maxleftsum)<<endl;
	cout<<"Maxleft: "<<maxleft<<" Maxright: "<<maxright<<" Sum: "<<maxrightsum<<" + "<< maxleftsum<<endl;
	return max(maxleft, maxright, maxrightsum + maxleftsum);
	
}

int maxfind3(vector<int>& v){
	//cout<<"v -> "<<v.size()<<endl;
	return maxfindthreealgo(v,0,v.size() - 1);	
}


/*  O(N) */
int maxfind4(vector<int>& v){
	int maxsum = 0 ;
	int tempsum = 0;
	for(int i = 0 ; i <v.size() ; i++){
		tempsum += v[i];
		if(maxsum < tempsum) maxsum = tempsum;
		if(tempsum < 0 ) tempsum = 0;
	}
	return maxsum;
}


int main(){
	vector<int> v{-2,11,-4,13,-5,-2};
	cout<<maxfind1(v)<<endl;
	cout<<maxfind2(v)<<endl;
	cout<<maxfind3(v)<<endl;
	cout<<maxfind4(v)<<endl;
	cout<<max(598,70,9)<<endl;
	return 0;
}
