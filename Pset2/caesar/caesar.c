#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define FIRSTUPPER 65
#define FIRSTLOWER 97
#define ALPHABETCEIL 26

//Get key in command line
int main(int argc, char* argv[]) {
   //validate user input
   int key = atoi(argv[argc - 1]);
   string plainText;
   
   while (argc != 2) {
       printf("Only one command line argument please!\n");
       return 1;
   }
   

   //grab the plaintext argument
   do {
       plainText = GetString();
   } while (plainText == '\0');
   
   
    //encrypt the text
    //Capital A = 65, lowercase a = 97
    //cyphertext[i] = (plaintext[i] + key) % 26
    // i = (i + n) mod N
    for (int i = 0; i < strlen(plainText); i++) {
        int cypherText = 0;
       
        if (isupper(plainText[i])) {
            
           cypherText = ((plainText[i] - FIRSTUPPER + key) % ALPHABETCEIL) + FIRSTUPPER;
           printf("%c", cypherText);
           
        } else if (islower(plainText[i])) {
            cypherText = ((plainText[i] - FIRSTLOWER + key) % ALPHABETCEIL) + FIRSTLOWER;
            printf("%c", cypherText);
            
        } else {
           printf("%c", plainText[i]);
       }
      
        
    }
    
    printf("\n");
    
} 
    