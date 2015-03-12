#include <iostream>

using namespace std;

int main()
{		
	int list[1000];
	int maxsize = 0;
	for(int i=0; i<100; i++){
		cin >> list[i];
		maxsize++;
		if(i%2){
			if(list[i]==0) break;
		}
	}

	if(maxsize <= 2){
		cout << 0 << " " << 0;
	}
	else {	
		for(int i=0; i<maxsize-2; i+=2){
			cout << list[i]*list[i+1] << " " << list[i+1]-1;
			if(i+1<maxsize-3) cout <<" ";
		}
	
	}
		
	return 0;
}

	
	

