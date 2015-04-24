#include <iostream>

using namespace std;

int main()
{	
	int maxsize = 0;
	cin >> maxsize;
	
	int *data = new int [maxsize];
	int tmpsum = 0, maxsum = -1;
	for(int i = 0; i < maxsize; ++i)
	{
		cin >> data[i];
		tmpsum += data[i];
		if(tmpsum > maxsum)
		{
			maxsum = tmpsum;
		}
		else if(tmpsum < 0)
		{
			tmpsum = 0;
		}
	}
	
	if(maxsum < 0)
	{
		maxsum = 0;
	}
	
	cout << maxsum << endl;
	
	return 0;
}

	
	


