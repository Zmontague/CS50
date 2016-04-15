#include <stdio.h>
#include <cs50.h>

int main(void) {
    //variable declartion
    int height;
    //loop to ensure entrance conditions are met
    do {
        printf("Height: ");
        height = GetInt();
        //giving a return if height is equal to zero
        if (height == 0) {
            return 0;
        }
        
    }
    while ((height > 23) || (height < 1));
    
    
    //counting out the height in loop
    for (int i = 0; i < height; i++) {
        //subtracting height from loop length and one to give desired number of spaces
        for (int spaces = 0; spaces < height - i - 1; spaces++) {
            printf(" ");
            
        }
        //adding two to count to give desired number of hashes. 
        for (int hashes = 0; hashes < i + 2; hashes++) {
            printf("#");
        }
        
        printf("\n");
    
        
    }
}