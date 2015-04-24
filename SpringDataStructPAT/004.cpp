#include <iostream>

using namespace std;

int ctoi(char c)
{
	if(c > '/' && c <':') return c-'0';
}

int* multiBy2(int *num, const int len)
{
	int *res;
	int resLen = len;
	if(num[0]>4)
	{
		resLen++;
		res = new int [resLen];
	}
	else
		res = new int [resLen];

	bool flag = false;
	for(int i = resLen-1, j = len-1; j >= 0; --i,--j)
	{
		res[i] = num[j] * 2 % 10;
		if(flag)
		{
			res[i]++;
			flag = false;
		}
		if(num[j]>4) flag = true;
	}
	if(resLen>len) res[0] = 1;
	
	return res;
	
}

bool isFunNum(int *num, int *res, int len)
{
	int prod = 0;
	bool flag = false;
	int zNumN = 0, zNumR = 0;
	for(int i = 0; i < len; ++i)
	{
		if(num[i] == 0) zNumN++;
		if(res[i] == 0) zNumR++;
		if(res[i]) flag = true;
		prod = num[i]^res[i]^prod;
	}
	if((!prod) && flag && (zNumN == zNumR)) return true;
	else return false;
}


int main()
{
	char cnum[20];
	cin.get(cnum,21);
		
	int num[20];
	int len = 0;
	for(; cnum[len] != '\0'; ++len)
	{
		num[len] = ctoi(cnum[len]);
	}

	int *res = multiBy2(num, len);
	int resLen = len;
	bool eqLen = true;
	if(num[0] > 4)
	{
		resLen++;
		eqLen = false;
	}
	if(eqLen)
	{
		if(isFunNum(num,res,len))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	else
	{
		cout << "No" << endl;
	}
	
	
	bool flag = false;
	for(int i = 0; i < resLen; ++i)
	{
		if(!flag)
		{
			if(res[i] != 0) flag = true;
		}
		if(flag)
		{
			cout << res[i];
		}
	}
	if(!flag) cout << 0;
	cout << endl;
	
	delete [] res;
	
	return 0;
}
