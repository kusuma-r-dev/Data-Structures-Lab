/*
Given a word and a character ch, reverse the part of the word from 
index 0 up to the first occurrence of ch. 
If ch is not present, leave the word unchanged and do nothing.
*/
#include <stdio.h>

int main()
{
    char word[50], ch;
    int i, pos = -1;
    char temp;

    printf("Enter the word: ");
    scanf("%s", word);

    printf("Enter the character: ");
    scanf(" %c", &ch);

    for(i = 0; word[i] != '\0'; i++)
    {
        if(word[i] == ch)
        {
            pos = i;
            break;
        }
    }

    if(pos != -1)
    {
        int start = 0;
        int end = pos;

        while(start < end)
        {
            temp = word[start];
            word[start] = word[end];
            word[end] = temp;

            start++;
            end--;
        }

        printf("Result: %s", word);
    }

    return 0;
}