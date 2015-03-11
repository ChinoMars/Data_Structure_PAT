#include <iostream>

using namespace std;

int scale(int num)
{
	int i = 0;
	if(num > 0) i = 1;
	
	num -= 1;
	i++;
	while(num>=4*i-2)
	{
		num -= 4*i-2;
		i++;
	}
	
	return i-1;
}

void prnt(int scale, char c)
{
	for(int i=0; i<scale-1; i++)
	{
		for(int j=0; j<i; j++) cout << " ";
		for(int k=0; k<2*(scale-i)-1; k++) cout << c;
		cout << "\n";
	}
	
	for(int i=0; i<scale-1; i++) cout << " ";
	cout << c << "\n";
	
	
	for(int i=scale-1; i>0; i--)
	{
		for(int j=0; j<i-1; j++) cout << " ";
		for(int k=0; k<2*(scale-i)+1; k++) cout << c;
		cout << "\n";
	}
}

int main()
{
	int num = 0;
	cin >> num;
	
	char c;
	cin >> c;
	
	int scl = scale(num);
	prnt(scl,c);
	cout << num-2*scl*scl+1;
	
	return 0;
}
