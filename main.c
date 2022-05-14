#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

char* encoder_function(char input[], int string_length)

{
        char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
        char *res_string = (char *) malloc(SIZE * sizeof(char));
        int x, n_bits = 0, z = 0, v = 0, c = 0, temporary;
        int a;
        int b;
        int j = 0;
        // takes 3 bits
        for (a = 0; a < string_length; a = a + 3)
        {
                v = 0, c = 0, n_bits = 0;
                for (b = a; b < string_length && b <= a + 2; b++)
                {       // creates new space for string by adding zeros
                        v = v << 8;
                        v = v | input[b];
                        //c is a variable for keeping the new 3 bits
                        c++;
                }
                n_bits = c * 8;
                // we divide by three to know how many 0s to add
                z = n_bits % 3;
                 //
                while (n_bits != 0)
                {
                        //checks if 6 or less
                        if (n_bits >= 6)
                        {
                                temporary = n_bits - 6;
                               x = (v >> temporary ) & 63;
                                n_bits = n_bits - 6;
                        } // runs till lrss than 6
                        else
                        {

                                temporary = 6 - n_bits;
                               x = (v << temporary) & 63;
                                n_bits = 0;
                        } // here we have res_string = alphabet[x]
                        res_string[j++] = alphabet[x];
                        }
 }
                        // adds zeros to cover                        
                        for (a = 1; a <= z; a++)
                        {
                        res_string[j++] = '=';
                        }
                        res_string[j] = '\0';
                        return res_string;

}

int main()
{

        int string_length;
        char input [SIZE];
        //makes one string from them
        scanf ("%[^\n]%*c", input);
         //checks length
        int length = strlen(input);
        // a copy is made to count the size
        char input_copy [length];
        for(int a =0; a < strlen(input); a++){
                input_copy[a] = input[a];
}
         // padding is done
        string_length = sizeof(input_copy) / sizeof(input_copy[0]);
        printf("Input : %s\n", input_copy);
        // puts in encoder_function
        printf("Encoded : %s\n", encoder_function(input_copy, string_length));
        return 0;
    
}
