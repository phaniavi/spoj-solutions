#include <bits/stdc++.h>
using namespace std;

char *pat;
int *LPS;
int m;//'m' is the size of pattern

void buildLPS()
{
	LPS[0] = 0;
	LPS[1] = 0;
	for(int i=2; i<=m; ++i)
	{
		int j = LPS[i-1];
		while(true)
		{
			if(pat[j] == pat[i-1])
			{
				LPS[i] = j+1;
				break;
			}
			if(j == 0)
			{
				LPS[i] = 0;
				break;
			}
			j = LPS[j];
		}
	}
}

bool findKMP()
{
	int i=0;//'i' is the length of the text taken input so far
	int j=0;//'j' is the length of the longest prefix-proper_suffix for the text so far
	char ch;
	bool flag = false;
	while(true)
	{
		ch = getchar();
		if(ch == '\n')
			break;
		while(true)
		{
			if(ch == pat[j])
			{
				j++;
				if(j == m)
				{
					flag = true;
					printf("%d\n",i-m+1);
					j = LPS[j];
				}
				break;
			}
			else if(j == 0)
				break;
			else 
				j = LPS[j];
		}
		i++;
	}
	return flag;
}

int main() {
	while(scanf("%d",&m)!=EOF)
	{
		getchar();
		pat = new char[m+10];
		LPS = new int[m+10];
		scanf("%s",pat);
		buildLPS();
		if(findKMP() == false)
			cout<<"NO SOLUTION\n";
		delete[] pat;
		delete[] LPS;
	}
	return 0;
}
