#include <stdio.h>
#include <cs50.h>

int main(void) {
    
    
    int opm = 192, bow = 16, minutes, output;
    
    printf("Minutes: ");
    minutes = GetInt();
    
    
    output = (minutes * opm) / bow;
    
    printf("%d\n", output);
    
    
    
    
    
    
}