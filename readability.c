#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

int letter_count(string copy);
int word_count(string copy);
int sentence_count(string copy);
void grade_index(string copy);

int main()
{
    string text = get_string("Text: ");
    grade_index(text);
}

int letter_count(string copy)
{
    int letters = 0;
        for (int i = 0; i < strlen(copy); i++)
        {
            if((copy[i] >= 'a' && copy[i] <= 'z') || (copy[i] >= 'A' && copy[i] <= 'Z'))
                {
                letters++;
            }
            else
            {
                letters += 0;
            }
        }
    return letters;
}


int word_count(string copy)
{
    int words = 1;
        for(int i = 0; i < strlen(copy); i++)
        {
            if(copy[i] == ' ')
            {
                words++;
            }
            else
            {
                words += 0;
            }
        }
    return words;
}


int sentence_count(string copy)
{
    int sentences = 0;
        for(int i = 0; i < strlen(copy); i++)
        {
            if(copy[i] == '.' || copy[i] == '!' || copy[i] == '?')
            {
                sentences++;
            }
            else
            {
                sentences += 0;
            }
        }
    return sentences;
}

void grade_index(string copy)
{
    float L = (100 * letter_count(copy)) / (float) word_count(copy);
    float S = (100 * sentence_count(copy)) / (float) word_count(copy);
    int grade = round(0.0588 * L - 0.296 * S - 15.8);

        if(grade < 1)
        {
            printf("Before Grade 1\n");
        }
        else if(grade >= 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %d\n",grade);
        }
}
