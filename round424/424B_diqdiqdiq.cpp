#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;
char a[27];
char b[27];
char str[1001];
int main()
{
	scanf(" %s %s %s", a, b, str);
	int len = strlen(str);
	for(int i=0;i<len;i++)
	{
		if(isdigit(str[i]))
			printf("%c",str[i]);
		else if(isupper(str[i]))
		{
			char c = str[i]-'A'+'a';
			for(int k=0;k<26;k++)
			if(a[k] ==c)
				printf("%c",toupper(b[k]));
		}
		else
		{
			for(int k=0;k<26;k++)
			if(a[k] ==str[i])
				printf("%c",b[k]);
		}
	}
	return 0;
}