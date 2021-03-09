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
// simplified character heuristic
void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS])
{
    int i;
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
    int i;
    int temp = 0;
    int j;

    while (s <= n )
    {
        for (i = 0; i < m; i++){

            if (txt[s] == pat[i])
                {
                temp = badchar[pat[i]];
                s -= temp;
                }
            }
            
        while (pat[j] == txt[s + j])
            j++;

        if (j > m)
        {
            printf("\n pattern occurs at shift = %d", s);
            s += n;
        }
        else
        s += m;
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
    
    search( txt, pat);
    return 0;
}