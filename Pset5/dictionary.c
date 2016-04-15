/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "dictionary.h"
#define MAXSIZE 27


//tries struct
typedef struct node
{
   bool isWord;
   struct node* children[MAXSIZE];
} node;

//declare node pointer called root.
node* root;

int count = 0; //create a global counter for number of words.

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
     int i = 0; 
   
    //initialized node pointer called cursor to equal root.
    node* cursor = root;
   
    //uses a while loop to iterate over the word. 
    while (word[i] != '\0')
    {   
       
        char num = word[i];
        
        //condition that accounts for apostrphe.
        if (word[i] == '\'')
        {
            num = 'z' + 1;   
        }     
        int newNum = tolower(num) - 'a'; 
        
        //condition to check if children is not NULL and moves there.
        if (cursor->children[newNum] != NULL)
        {
            cursor = cursor->children[newNum];
            i++;
        }
        else 
        {
            return false; 
        }
    }
    //upon reaching the end, checks what you have found is a word. 
    if (cursor->isWord == true)
    {
        return true; 
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* dict = fopen(dictionary, "r"); 
    if (dict == NULL)
    {
        printf("Could not open dictionary file");
        return false;
    }
    //mallocs memory in the heap for the root. 
    root = malloc(sizeof(node));
    //sets node pointer called cursor to root. 
    node* cursor = root; 
    
    int letter = 0;
    //iterate over file
    while(fgetc(dict) != EOF)
    {
        
        fseek(dict, -1, SEEK_CUR);
        cursor = root; 
        for (letter = fgetc(dict); letter != '\n'; letter = fgetc(dict))
        {   
            
            //dealing with that pesky apostrphe
            if (letter == '\'')
            {
                letter = 'z' + 1;
                
            }
            
            //if the next node associated with the letter is NULL, mallocs a node. 
            if (cursor->children[letter - 'a'] == NULL)
            {
                cursor->children[letter - 'a'] = malloc(sizeof(node));
                cursor = cursor->children[letter - 'a'];
            } 
            
            //if letter is there, follow the pointer. 
            else
            { 
                cursor = cursor->children[letter - 'a']; 
            }
        }
        
        //at the end, sets the word to true. 
        cursor->isWord = true; 
        
        //increases number of words by 1. 
        count++;
    }
    fclose(dict);
   
    return true;
    
    
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return count;
}

//created new function since dictionary.h cannot be altered at all.
bool clearnode(node* current)
{
    //recursively free each of current's children, very elegant solution. 
    for (int i = 0; i < MAXSIZE; i++)
    {
        if (current->children[i] != NULL)
        {
            clearnode(current->children[i]);
        }    
    }
    
    //then free current. 
    free(current);
    return true;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    return clearnode(root);
}



