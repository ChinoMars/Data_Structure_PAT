#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int arryLen = 0, shift = 0;
	cin >> arryLen >> shift;
	
	int *arryNum = new int [arryLen];
	int realshif = shift % arryLen;
	for(int i = realshif; i < arryLen; ++i)
	{
		cin >> arryNum[i];
	}
	for(int i = 0; i < realshif; ++i)
	{
		cin >> arryNum[i];
	}
	
	for(int i = 0; i < arryLen; ++i)
	{
		if(i > 0) cout << ' ';
		cout << arryNum[i];
	}
	cout << endl;
	
	return 0;
}
