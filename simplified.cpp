# include <string.h>
#include <iostream>
#include <string>
using namespace std;
 
# define NO_OF_CHARS 256
 
// A utility function to get maximum of two integers
int max(int a, int b)
{    return (a > b) ? a : b;
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

    while (s <= n )
    {
        int j = 0;
        
        for (i = 0; i < m; i++){

            if (txt[s] == pat[i])
                {
                temp = badchar[pat[i]];
                s -= temp;
                }
            }
            
        while (pat[j] == txt[s + j])
            j++;

        if (j >= m)
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
    char txt[] = "xxxxxxxcvsd";
    char pat[] = "cvsd";
    
    search(txt, pat);
    return 0;
}