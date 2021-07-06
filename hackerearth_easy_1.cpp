// Write your code here
#include <iostream>
#include <cmath>
using namespace std;
string determineTprime(int number){
	if(number<=2){
		return "NO";
	}
	int count=0;
	for(int i=2; i<sqrt((double)number); i++){
		if(number%i==0){
			count++;
		}
	}
	if(count==0 && sqrt((double)number)==(int)sqrt((double)number)) {
		return "YES";
	}
	else {
		return "NO";
	}
}
int main() {
	int num;
	cin>>num;
	int arr[num];
	for (int i=0; i<num; i++){
		cin>>arr[i];
	}
	for (int i=0; i<num; i++){
		cout<<determineTprime(arr[i])<<"\n";
	}
	
	return 0;
}