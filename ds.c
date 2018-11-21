#include <stdio.h> 
#include <conio.h> 
#include <string.h>
#include <ctype.h>
#define MX 5  

char[] caesarEncrypt(char message[100], int key) {
 
 char ch;
    int i;
   char output[100];
    
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            
            output[i] = ch;
        }
    }
    return output;
}

char[] caesarDecrypt(char message[100], int key) {
 
 char ch;
    int i;
   char output[100];
    
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            
            output[i] = ch;
        }
    }
    return output;
}

char[] vigenereEncrypt(char message[100], char key[100]) {
	
    int msgLen = strlen(message);
	int keyLen = strlen(key);
	int i;
	int j;
 
    char newKey[msgLen];
	char encryptedMsg[msgLen];
 
    //generating new key
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
 
        newKey[i] = key[j];
    }
 
    newKey[i] = '\0';

    for(i = 0; i < msgLen; ++i)
        encryptedMsg[i] = ((message[i] + newKey[i]) % 26) + 'A';
 
    encryptedMsg[i] = '\0';
	return encryptedMsg;
}

char[] vigenereDecrypt(char message[100], char key[100]) {
	    int msgLen = strlen(message);
	int keyLen = strlen(key);
	int i;
	int j;
 
    char newKey[msgLen];
	char decryptedMsg[msgLen];
 
    //generating new key
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
 
        newKey[i] = key[j];
    }
 
    newKey[i] = '\0';
 
    for(i = 0; i < msgLen; ++i)
        decryptedMsg[i] = (((message[i] - newKey[i]) + 26) % 26) + 'A';
 
    decryptedMsg[i] = '\0';
	return decryptedMsg;
}

void frequency(char string[100]) {
 	int c = 0, temp, count[26] = {0}, x;
    char string[] = "TEST";
    int letterSorted[26];
   while (string[c] != '\0') {
   
      if (string[c] >= 'A' && string[c] <= 'Z') {
         x = string[c] - 'A';
         count[x]++;
      }
 
      c++;
   }
   
   for(int i = 0; i < 26; i++) {
	   letterSorted[i] = i;
   }
 
	for(int i = 0; i < 25; i++) {
		for(int j = i + 1; j < 26; j++) {
			if(count[i] < count[j]) {
				temp = count[i];
				count[i] = count[j];
				count[j] = temp;
				temp = letterSorted[i];
				letterSorted[i] = letterSorted[j];
				letterSorted[j] = temp;
			}
		}
	}
  
   for (c = 0; c < 26; c++)
         printf("%c occurs %d times in the string.\n", letterSorted[c] + 'A', count[c]);
 
}

int main() {
	
	FILE *fp;
    char str[MAXCHAR];
    char* filename = "c:\\temp\\test.txt";
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL);
}


void playfairEncrypt(char ch1, char ch2, char key[MX][MX]) {  
    int i, j, w, x, y, z;  
    
    
    for (i = 0; i < MX; i++) {  
        for (j = 0; j < MX; j++) {  
            if (ch1 == key[i][j]) {  
                w = i;  
                x = j;  
            } else if (ch2 == key[i][j]) {  
                y = i;  
                z = j;  
            }  
        }  
    }  
    if (w == y) {  
        x = (x + 1) % 5;  
        z = (z + 1) % 5;  
        printf("%c%c", key[w][x], key[y][z]);  
    } else if (x == z) {  
        w = (w + 1) % 5;  
        y = (y + 1) % 5;  
        printf("%c%c", key[w][x], key[y][z]);  
    } else {  
        printf("%c%c", key[w][z], key[y][x]);  
    }    
}  

void playfairDecrypt(char ch1, char ch2, char key[MX][MX]) {  
    int i, j, w, x, y, z;  
    
    
    for (i = 0; i < MX; i++) {  
        for (j = 0; j < MX; j++) {  
            if (ch1 == key[i][j]) {  
                w = i;  
                x = j;  
            } else if (ch2 == key[i][j]) {  
                y = i;  
                z = j;  
            }  
        }  
    }  
    if (w == y) {  
        x = ((x - 1) + 5) % 5;  
        z = ((z - 1) + 5) % 5;  
        printf("%c%c", key[w][x], key[y][z]);  
    } else if (x == z) {  
        w = ((w - 1) + 5) % 5;  
        y = ((y - 1) + 5) % 5;  
        printf("%c%c", key[w][x], key[y][z]);  
    } else {  
        printf("%c%c", key[w][z], key[y][x]);  
    }    
}  


int removerepeated(int size,char a[])
{
 int i,j,k;
 for(i=0;i<size;i++)
  {
 for(j=i+1;j<size;)
 {
    if(a[i]==a[j])
    {
     
     for(k=j;k<size;k++)
     {
      a[k]=a[k+1];
     }
         size--;
        }
    else
    {
      j++;
     } 
 }
 }
return(size);
}

void encryptPlayfair(char text[1000], char keystr[100]) {
	int i, j, k = 0, l, m = 0, n;  
    char key[MX][MX], keyminus[100];
    char alpa[26] = {  
        'A',  
        'B',  
        'C',  
        'D',  
        'E',  
        'F',  
        'G',  
        'H',  
        'I',  
        'J',  
        'K',  
        'L',  
        'M',  
        'N',  
        'O',  
        'P',  
        'Q',  
        'R',  
        'S',  
        'T',  
        'U',  
        'V',  
        'W',  
        'X',  
        'Y',  
        'Z'  
    };  
    n = strlen(keystr);  
    n = removerepeated(n, keystr);
    j = 0;  
    for (i = 0; i < 26; i++) {  
        for (k = 0; k < n; k++) {  
            if (keystr[k] == alpa[i]) break;  
            else if (alpa[i] == 'J') break;  
        }  
        if (k == n) { 
            keyminus[j] = alpa[i];  
            j++;  
        }  
    }  
    k = 0;  
    for (i = 0; i < MX; i++) {  
        for (j = 0; j < MX; j++) {  
            if (k < n) {  
                key[i][j] = keystr[k];  
                k++;  
            } else {  
                key[i][j] = keyminus[m];  
                m++;  
            }  
        }    
    }  
	
    for (i = 0; i < strlen(text); i++) {  
        if (text[i] == 'J') text[i] = 'I';  
        if (text[i + 1] == '\0') playfairEncrypt(text[i], 'X', key);  
        else {  
            if (text[i + 1] == 'J') text[i + 1] = 'I';  
            if (text[i] == text[i + 1]) playfairEncrypt(text[i], 'X', key);  
            else {  
                playfairEncrypt(text[i], text[i + 1], key);  
                i++;  
            }  
        }  
    }
}

void decryptPlayfair(char text[1000], char keystr[100]) {
	int i, j, k = 0, l, m = 0, n;  
    char key[MX][MX], keyminus[100];
    char alpa[26] = {  
        'A',  
        'B',  
        'C',  
        'D',  
        'E',  
        'F',  
        'G',  
        'H',  
        'I',  
        'J',  
        'K',  
        'L',  
        'M',  
        'N',  
        'O',  
        'P',  
        'Q',  
        'R',  
        'S',  
        'T',  
        'U',  
        'V',  
        'W',  
        'X',  
        'Y',  
        'Z'  
    };  
    n = strlen(keystr);  
    n = removerepeated(n, keystr);
    j = 0;  
    for (i = 0; i < 26; i++) {  
        for (k = 0; k < n; k++) {  
            if (keystr[k] == alpa[i]) break;  
            else if (alpa[i] == 'J') break;  
        }  
        if (k == n) { 
            keyminus[j] = alpa[i];  
            j++;  
        }  
    }  
    k = 0;  
    for (i = 0; i < MX; i++) {  
        for (j = 0; j < MX; j++) {  
            if (k < n) {  
                key[i][j] = keystr[k];  
                k++;  
            } else {  
                key[i][j] = keyminus[m];  
                m++;  
            }  
        }    
    }  
	
    for (i = 0; i < strlen(text); i++) {  
        if (text[i] == 'J') text[i] = 'I';  
        if (text[i + 1] == '\0') playfairDecrypt(text[i], 'X', key);  
        else {  
            if (text[i + 1] == 'J') text[i + 1] = 'I';  
            if (text[i] == text[i + 1]) playfairDecrypt(text[i], 'X', key);  
            else {  
                playfairDecrypt(text[i], text[i + 1], key);  
                i++;  
            }  
        }  
    }
}