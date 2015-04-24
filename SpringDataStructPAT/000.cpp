#include <iostream>
#include <stdlib.h>

using namespace std;

bool isIpLegal(char *);
char* ip2Bin(char *);
int* iptoNum(char *);

int main()
{
	char ip[20];
	cin.get(ip,21);
	if(!isIpLegal(ip))
	{
		cout << "data error" << endl;
		return 0;
	}
	
	char *ipBin = ip2Bin(ip);
	for(int i = 0; i < 32; ++i) 
	{
//		if(!(i%8)) cout << '\n';
		cout << ipBin[i];   
	}
	cout << endl;
	
    delete [] ipBin;

    return 0;
}


char* ip2Bin(char *str)
{
//	if(!isIpLegal(str)) return NULL;
	
	int *Num = iptoNum(str);
	int idx = 0;
	char *ipBin = new char [40];
	
	for(int i = 0; i < 32; ++i) ipBin[i] = '0';
	ipBin[32] = '\0';
	for(int i = 0; i < 32; ++i)
	{
		int divd = Num[idx];
		for(int j = 7; j >= 0; --j)
		{
			if(divd)
			{
				int rem = divd%2;
				divd /= 2;
				if(rem) ipBin[i*8+j] = '1';
				else ipBin[i*8+j] = '0';
				
			}
			else 
			{
				break;
			}
		}
		++idx;
	}
	delete [] Num;
	return ipBin;
	
}

bool isIpLegal(char *str)
{
	char *p = str;
	if(!(*p > '/' && *p < ':')) return false;
	int dotNum = 0;
	for(int i = 0; str[i] != '\0'; ++i)
	{
		if(!((str[i] > '/' && str[i] < ':') || str[i] == '.')) return false;
		if(str[i] == '.')
		{
			dotNum++;
			if(dotNum>3) return false;
			int sectNum = atoi(p);
			if(sectNum > 255 || sectNum < 0)
			{
//				cout << "data error";
				return false;	
			}
			p = &str[i+1];
			if(dotNum == 3)
			{
				if(*p > '/' && *p < ':')
				{
					sectNum = atoi(p);
					if(sectNum > 255 || sectNum < 0)
					{
//						cout << "data error";
						return false;	
					}
				}
				else return false;
				
			}
		}
	}
	return true;
}

int* iptoNum(char *str)
{
//	if(!isIpLegal(str)) return NULL;
	
	char *p = str;
	int idx = 0;
	int dotNum = 0;
	int *Num = new int [4];
	for(int i = 0; str[i] !='\0'; ++i)
	{
		if(str[i] == '.')
		{
			++dotNum;
			int sectNum = atoi(p);
			Num[idx] = sectNum;
			++idx;
			p = &str[i+1];
			if(dotNum == 3)
			{
				Num[idx] = atoi(p);
				break;
				
			}
		}
	}
	return Num;
		
}









