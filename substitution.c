#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

const char* wordUpper(string s, int length)
{
    char str[length];
    for (int i = 0; i < length; i++)
    {
        char ch = toupper(s[i]);
        strncat(str,&ch,1);
    }
    string w = str;
    return w;
}


int value = 0;


int main(int argc, string argv[])
{
    string cmdLine = argv[1];
    int length = strlen(cmdLine);

    if (argc != 2)
    {
        printf("Sorry, key not readable.\n");
        return 1;
    }


    for (int i = 0; i < length; i++)
    {
        if((int)toupper(cmdLine[i]) < 65 || (int)toupper(cmdLine[i]) > 90 || length != 26)
        {
            printf("Sorry invalid key.\n");
            return 1;
        }
    }



    string plaintext = get_string("plaintext: ");
    int plainLength = strlen(plaintext);
    char ciphertext[plainLength];
    const char* key = wordUpper(cmdLine, length);

    //make for loop to find the index position of a certain letter(uppercase the letter) in the key
    //Add 64 to ascii value of that variable and save it in a new variable
    //if the original letter was lowercase, then use tolower
    //append to ciphertext
    for (int i = 0; i < plainLength; i++)
    {
        char ch = toupper(plaintext[i]);
        for(int j = 0; j < 26; j++)
        {
            if (key[j] == ch)
            {
                value = j;
                break;
            }
        }
        char cipher = (char)(value + 64);
        if (islower(plaintext[i]))
        {
            cipher = tolower(cipher);
        }
        if (isalpha(ch))
        {
        ciphertext[i] = cipher;
        }
    }
    printf("ciphertext: %s\n", ciphertext);
}

