#include <iostream>

using namespace std;

bool isFunNum(const int *a, int lenA, const int *b, int lenB)
{
  if(lenA != lenB) return false;
  for(int i = 0; i < 10; ++i)
  {
	if(a[i] != b[i])
	{
	  return false;
	}
  }
  return true;
}

int* dNum(int *a, int len)
{
  int *p;
  int lenP = len;
  if(a[0] > 4) lenP++;
  p = new int [lenP];
  
  bool flag = false;
  for(int i = len-1, j = lenP-1; i >= 0; --i, --j)
  {
  	p[j] = a[i] * 2 % 10;
    if(flag)
    {
      p[j]++;
      flag = false;
    }
    if(a[i] > 4) flag = true;
  }
  if(lenP > len) p[0] = 1;
  
  return p;
}

int ctoi(char c)
{
  if(c > '/' && c <':') return c-'0';
}

int main()
{
  char cnum[20];
  cin.get(cnum,21);
  int num[20];
  int len = 0;
  
  bool zeroFlag = true;
  for(int i = 0; cnum[i] != '\0'; ++i)
  {
  	if(cnum[i] != '0') zeroFlag = false;
  	if(zeroFlag)
  	{
  	  continue;
	}
	num[len] = ctoi(cnum[i]);
	len++;
  }

  int counterA[10];
  for(int i = 0; i < 10; ++i)
  {
  	counterA[i] = 0;
  }
  for(int i = 0; i < len; ++i)
  {
  	counterA[num[i]]++;
  }
  
  int lenB = (num[0]>4)?(len+1):len; 
  int *douNum = dNum(num, len);
  int counterB[10];
  for(int i = 0; i < 10; ++i)
  {
  	counterB[i] = 0;
  }
  for(int i = 0; i < lenB; ++i)
  {
  	counterB[douNum[i]]++;
  }

  if(isFunNum(counterA, len, counterB, lenB))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  
  for(int i = 0; i < lenB; ++i)
  {
    cout << douNum[i];
  }
  cout << endl;
 
  delete [] douNum;
  return 0;
}


