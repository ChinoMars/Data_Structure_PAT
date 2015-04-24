#include <iostream>

using namespace std;

void deriPoly(int *poly, int len)
{
	if(poly[1] == 0 || poly[0] == 0)
	{
		cout << "0 0";
		return;
	}
	for(int i = 0; i < len-2; i += 2)
	{
		if(i != 0) cout << ' ';
		cout << poly[i]*poly[i+1] << ' ' << poly[i+1]-1;
	}
	return;
}

int main()
{	
	int poly[100];
	int len = 0;
	for(; len < 100; ++len)
	{
		cin >> poly[len];
		if(poly[len] == 0) break;
	}
	len++;
	
	deriPoly(poly,len);
	
	return 0;
}

	
	


