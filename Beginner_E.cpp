#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	string brain;
	cin>>s>>brain;
	string tmp;
	int i = 0, j1 = 0, j2 = s.length() - 1;
	bool reverse = true;	//true�� ������, false�� ������ 
	while(i != brain.length()){
		if(brain[i] == 'S'){
			if(reverse = true){
				cout<<s.front();
				s.erase(s.begin());
			}
			else{
				cout<<s.back();
				s.erase(s.end());
			}
		}
		if(brain[i] == 'R'){
			if(reverse)
				reverse = false;
			else
				reverse = true;			
		}
		if(brain[i] == 'A'){
			if(reverse){
				s = "x" + s;
			}
			else{
				s = s + "x";
			}
		}
		i++;
	}
	return 0;
}
