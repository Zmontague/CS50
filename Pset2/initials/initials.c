#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{   //prompt and store user data
    //printf("Name please: ");
    string getName = GetString();
    
    //runs through the length of name
    for (int i = 0; i < strlen(getName); i++)
    {   //check to find the first characters of each name.
        if ((i == 0 && isalpha(getName[0])) ||  // < Checks very first character
            (isalpha(getName[i]) && isspace(getName[i - 1]))) //Then compares to check ith character of GetName and checks to ensure there was a space infront of the ith character
        {   //prints the first initials after each iteration. 
            printf("%c", toupper(getName[i]));
        }
    }
    
    printf("\n");
}
    