#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;
int n;
int arr[101];
int main()
{
	int state=0;
	scanf("%d %d", &n, &arr[0]);
	bool istrue = true;
	for(int i=1;i<n;i++)
	{
		scanf("%d", &arr[i]);
		if(state ==0)
		{
			if(arr[i] < arr[i-1])
				state =2;
			else if(arr[i] == arr[i-1])
				state =1;
		}
		else if(state ==1)
		{
			if(arr[i]> arr[i-1])
				istrue = false;
			else if(arr[i] < arr[i-1])
				state = 2;
		}
		else
		{
			if((arr[i] >= arr[i-1]))
			istrue =false;
		}
	}
	printf("%s", istrue?"YES":"NO");
	return 0;
}