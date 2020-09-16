/*  
  可以轉換進位制
  a為目前的進位制
  b為想轉換成的進位制
  c為目前進位制的數值
  會輸出ans(b進位制的c)
*/
#include<iostream> 
#include<stack>
#include<string>
#include<cmath>  
#include<sstream> //add
using namespace std;
  
int atoi(string s,int a){
	int ans=0;	
	for(int i=0;i<s.size();i++){
		char t=s[i];
		if(t>='0'&&t<='9'){
			ans=ans*a+t-'0';
		}
		else{
			ans=ans*a+t-'a'+10;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a;
	cin>>a;
	stack<int> stk; //用出c的b進位制
				    //先堆疊在top,再cout,pop() 
	if(a==10){
		int b,c;
		cin>>b>>c;
		while(c){
			stk.push(c%b);
			c=c/b;
		} 
		while(!stk.empty()){
			cout<<stk.top();
			stk.pop();
		}
		cout<<endl;
	}
	else{            //若不是10進位制,先轉換為10進位制 
		int b,c;     //轉換之進位制 
		string s;
		cin>>b>>c;
		stringstream ss;
		ss<<c;
		s=ss.str();
		int ans=atoi(s,a); //ans為10進位制的s
		while(ans){
			stk.push(ans%b);
			ans=ans/b;
		} 
		while(!stk.empty()){
			cout<<stk.top();
			stk.pop();
		}
		cout<<endl;
	}
	return 0;
}
