#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    
    float input = -1;
    int count, 
    coins,
    q = 25,
    d = 10,
    n = 5;
    
    
    
    //check that the input is not negative.
    do {
        printf("O hai! How much change is owed? ");
        input = GetFloat();
        
        
    } while (input <= 0);
    
     coins = round(input * 100);
    
   count = (coins / q);
   coins = coins % q;
   
   count = count + (coins / d);
   coins = coins % d;
   
   count = count + (coins / n);
   coins = coins % n;
   
   count = count + coins;
   
   
   
   
   
   
   
   
     printf("%d\n", count);
     
}
