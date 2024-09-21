//#include "cipher.c"
char decipher(char str,int k){

    char ch;

   

    ch = str;
    // Check for valid characters.
    if (isalnum(ch)) {

        //Lowercase characters.
        if (islower(ch)) {
            ch = (ch - 'a' - k) % 26 + 'a';
        }
        // Uppercase characters.
        if (isupper(ch)) {
            ch = (ch - 'A' - k) % 26 + 'A';
        }

        // Numbers.
        if (isdigit(ch)) {
            int ach = (ch - '0' - k);
            if (ach<0)
            {
                ach+=10;
            }
            ch=ach%10+'0';
            
        }
    }
    // Invalid character.
    else {
        ch=ch;
    }

    // Adding encoded answer.
    return ch;



    
}
