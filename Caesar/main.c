#include <stdio.h>
#include <stdlib.h>

int main()
{
    char encriptedMessage[100];
    char decriptedMessage[100];
    char currentChar;
    int i;
    int key;

    printf("Enter a message to decrypt: ");
    gets(encriptedMessage);
    printf("Enter key: ");
    scanf("%d", &key);

    for(i = 0; encriptedMessage[i] != '\0'; ++i)
    {
        currentChar = encriptedMessage[i];

        if(currentChar >= 'a' && currentChar <= 'z')
        {
            currentChar = currentChar - key;

            if(currentChar < 'a')
            {
                currentChar = currentChar + 'z' - 'a' + 1;
            }

            decriptedMessage[i] = currentChar;
        }
        else if(currentChar >= 'A' && currentChar <= 'Z')
        {
            currentChar = currentChar - key;

            if(currentChar < 'A')
            {
                currentChar = currentChar + 'Z' - 'A' + 1;
            }

            decriptedMessage[i] = currentChar;
        }
    }

    printf("Decrypted message: %s", decriptedMessage);

    return 0;
}
