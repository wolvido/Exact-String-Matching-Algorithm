# include <string.h>
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <fstream>
using namespace std;

int  hexToDecimal(const char* hex);
const int MAX_SIZE = 1000000;
# define NO_OF_CHARS 256
 
// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}
 
// The preprocessing function for Boyer Moore's bad character heuristic
void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS])
{
    int i;
 
    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
 
    // Fill the actual value of last occurrence of a character
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}
 
void search(char *txt, char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);
 
    int badchar[NO_OF_CHARS];
 
    badCharHeuristic(pat, m, badchar);
 
    int s = 0; // s is shift of the pattern with respect to text
    while (s <= (n - m))
    {
        int j = m - 1;
 
        while (j >= 0 && pat[j] == txt[s + j])
            j--;
 
        if (j < 0)
        {
            printf("\n pattern occurs at shift = %d", s);
 
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
 
        }
 
        else
            s += max(1, j - badchar[txt[s + j]]);
    }
}
 
/* Driver program to test above funtion */
int main()
{
    ifstream read;
		read.open("example.txt");
					
			char* txt = new char[MAX_SIZE];
						
			while (!read.eof())
			{	
				for (int i = 0; i <= MAX_SIZE; i++)
				{

						read >> txt[i];
						
				}
			}
    
    char pat[] = "pattern";

    search(txt, pat);
    return 0;
}