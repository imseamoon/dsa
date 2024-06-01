#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int scoreOfString(char* s) {
    int ans = 0;

    for(int i=1 ; s[i]!='\0';i++)
    {
        ans += abs(s[i-1] - s[i]);
    }
    return ans;
}

int main(int argv, char* argc[])
{
	char s[] = "hello";
	printf("%d",scoreOfString(s));

	return 0;
}

