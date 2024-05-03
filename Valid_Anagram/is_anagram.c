#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isAnagram(char* s, char* t) {
    // if the length of the two string s and t aren't equal then they cant be anagrams
    if(strlen(s) != strlen(t)) return false;

    //  making a frequency table for the 26 alphbets
    int frequency[26] = {0};

    // iterating length times once and mapping over all the characters
    for (int i = 0; s[i]!= '\0'; i++)
    {
        //  subtracting 97 to get the 0 to 26 equivalent alphabets
        // adding frequency for each alphabet occurance in s
        // removing frequency for each occurance in t
        frequency[(int)s[i]-97]++;
        frequency[(int)t[i]-97]--;
    }

    for (int i = 0; i<26;i++)
    {
        // if any one of the frequency isn't zero then not anagram for sure
        if(frequency[i]!=0) return false;
    }
    
    return true;
}

int main(int argc, char *argv[])
{
	puts("Enter two strings with space seperated");
	char *first, *second;
	scanf("%s %s", first,second);
	printf("%d",isAnagram(first, second)); 	
	return 0;
}
