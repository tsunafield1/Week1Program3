#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int nub = 0,i = 0,sum = 0,t[100];
	bool check = 0;
	char pre,in,w[40];
	FILE *word;
	word = fopen("p042_words.txt", "r");
	for (int j = 1; j <= 100; j++) //Find tn
	{
		t[j-1] = j * (j + 1) / 2;
	}
	while(1)
	{
		fscanf(word, "%c", &in);
		if (in == '\"')  //Collect words + Triangle?
		{
			i = 0;
			while (1) //Collect words
			{
				pre = in;
				fscanf(word, "%c", &in);
				if (pre == '\"' && in == '\"')
				{
					check = 1;
					break;
				}
				else if (in != '\"')
				{
					w[i] = in;
					i++;
				}
				else if (in == '\"')break;
			}
			sum = 0;
			for (int j = 0; j < i; j++) //Calculate word value
			{
				sum += w[j] - 64;
			}
			for (int j = 0; j < 100; j++) //Triangle?
			{
				if (sum < t[j])break;
				else if (sum == t[j])
				{
					nub++;
					break;
				}
			}
		}
		if (check)break;
	}
	printf("%d", nub);
}