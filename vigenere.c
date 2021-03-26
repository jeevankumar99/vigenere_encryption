// to encrypt entered plain text to cipher text using vigenere encryption

#include <stdio.h>
#include <string.h>
#include <cs50.h>

char vigenere();

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (strlen(argv[1]) > 3) // to check if the arguement entered by the user is an alphabet
        {
            return 1;
            exit(1);
        }
        string pt = get_string("plaintext: ");
        int size = strlen(pt);
        int asciik[3];
        for (int j = 0; j < 3; j++)  // to convert the arguement as ascii for the key
        {
            asciik[j] = (int) argv[1][j];
            if (asciik[j] >= 97)
            {
                asciik[j] -= 32;
            }
            asciik[j] -= 65;
        }
        char ecryp = vigenere(pt, asciik, size); // using the function
        return 0;  // program runs without errors
    }

    else
    {
        printf("No arguement\n");
        return 1;  // there is some error with the program
    }
}

//Function to encrpt the plain text

char vigenere(string plain, int asciik[], int length)  // asciik is a key
{
    int z = -1, counter = 0;
    int ascii[length];
    for (int i = 0; i < length; i++)  // to convert the string values to an integer ascii value
    {
        ascii[i] = (int) plain[i];
    }
    for (int m = 0; m < length; m++)
    {

        if (ascii[m] < 65 || ascii[m] > 122) // to  skip the key if there is a character other than alphabets
        {
            continue;
        }
        z++;
        if (z % 3 == 0)  // as there is only three keys and they have to start again
        {
            z = 0;
        }

        if (ascii[m] >= 65 && ascii[m] <= 90) // for uppercase entered by the user
        {
            ascii[m] += asciik[z];
            while (ascii[m] > 90)
            {
                ascii[m] = 64 + (ascii[m] - 90);
            }
        }
        else if (ascii[m] >= 97 && ascii[m] <= 122) // for lowercase alphabets entered by the user
        {
            ascii[m] += asciik[z];
            while (ascii[m] > 122)
            {
                ascii[m] = 96 + (ascii[m] - 122);
            }
        }
    }
    char encrypt[length];
    printf("ciphertext: ");
    for (int k = 0; k < length; k++)
    {
        encrypt[k] = (char) ascii[k];
        printf("%c", encrypt[k]);
    }
    printf("\n"); // to go to the next line after the program ends
    return 0;
}









