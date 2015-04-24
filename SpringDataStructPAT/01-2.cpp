#include <iostream>

using namespace std;

int main()
{	
	int maxsize = 0;
	cin >> maxsize;
	
	int data[maxsize];
	int begin = 0, maxbegin = 0, maxend = maxsize-1;
	int tmpsum = 0, maxsum = -1;
	for(int i = 0; i<maxsize; i++)
	{
		cin >> data[i];
		tmpsum += data[i];
		if(tmpsum > maxsum)
		{
			maxsum = tmpsum;
			maxbegin = begin;
			maxend = i;
		}
		else if(tmpsum < 0)
		{
			tmpsum = 0;
			begin = i+1;
		}
	} 
	
	if(maxsum < 0)
	{
		maxsum = 0;
		maxbegin = 0;
		maxend = maxsize-1;
	}
	cout << maxsum 
		<< " " 
		<< data[maxbegin] 
		<< " " 
		<< data[maxend];
	
	return 0;
}

	
	

