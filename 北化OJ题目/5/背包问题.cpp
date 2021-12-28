#include<iostream>
using namespace std;
int weight[1000];
bool packet(int s,int n){
	//printf("n: %d total: %d\n",n,s);
	if(s == 0) return true;
	if(s < 0 ||(s > 0 && n < 1)){
		return false;
	}
	if(packet(s - weight[n - 1], n - 1)){
		return true;
	}
	else return packet(s,n - 1);
}
int main(){
	int s, n;
	while(cin>>s>>n){
		for(int i = 0; i < n; i++){
			cin>>weight[i];
		}
		if(packet(s,n))
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
