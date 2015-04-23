#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isPrime(int num)
{
	if(num <= 1) return false;
	if(num == 2) return true;
	if(!(num%2)) return false;
	for(int i = 3; i <= sqrt(num); i++)
	{
		if(!(num%i)) return false;
	}
	return true;
}

int main()
{
	int N = 0;
	cin >> N;
	
	int primeCP = 0;
	for(int i = 1; i <= N; i+=2)
	{
		if(isPrime(i))
		{
			int tmp = i+2;
			if(isPrime(tmp) && tmp <= N)
			{
				primeCP++;				
			}
		}
			
	}
	
	cout << primeCP << endl;
	return 0;
}
