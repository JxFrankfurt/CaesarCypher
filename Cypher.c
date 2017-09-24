//Jackson Frankfurt
//Caesar Cypher
//7/20/17

#include <stdio.h>
#include <string.h>
char LowerToUpper (char);
//cypher.txt, encrypt OR decrypt, input.txt, output.txt

/*Cypher example with format:
A Q
B D
C E
D P
E O
F S
G C
H R
I F
J W
K Z
L A
M Y
N L
O X
P B
Q V
R M
S K
T U
U J
V N
W T
X G
Y I
Z H
*/
int main (int argc, char *argv[]){
  const short CypherLength = 25; //number of characters substituted minus one, limited by size of 'short' datatype
  char alphaGet[CypherLength];
  char alphaPut[CypherLength];
  char inputBuffer;
  //idea: make 2 alphabet arrays to have the same index for corresponding characters

  if(argc != 5)printf("This program needs 5 arguments. You input %d.\n", argc);
  else if (strcmp (argv[2],"encrypt") == 0){
    printf("Encrypting...\n");
    FILE *cypher = fopen(argv[1], "r"); //open cypher.txt
    if(!cypher)printf("ERROR 1 The required format is: <program executable> cypher.txt encrypt/decrypt input.txt output.txt\n");
    else{
      FILE *clear = fopen(argv[3], "r"); //open clear_text.txt
      if(!clear)printf("ERROR 2 The required format is: <program executable> cypher.txt encrypt/decrypt input.txt output.txt\n");
      else{
        FILE *crypt = fopen(argv[4], "w"); //open crypt_text.txt
        if(!crypt)printf("ERROR 3 The required format is: <program executable> cypher.txt encrypt/decrypt input.txt output.txt\n");
        else{
          //deal with the data here
          //for (short i = 0; cStorage[i] != EOF; i++)
          // short i = 0;
          // short counterGet = 0;
          // short counterPut = 0;
          // short First = 0;
        //  do{//convert all lowercase input into caps
        //    // if (First == 1){
            //   i++;
            // }
            // cStorage[i]  = fgetc(cypher); //gets the first char in the cypher
            // if (i == 0 && cStorage[i] == EOF){
            //   printf("You input a blank cypher.\n");
            // }
            // if (i%4 == 0){
            //   alphaGet[counterGet] = cStorage[i];
            //   printf("%c", alphaGet[counterGet]);
            //   counterGet++;
            // }
            // if (i%4 == 2){
            //   alphaPut[counterPut] = cStorage[i];
            //   printf("%c", alphaPut[counterPut]);
            //   counterPut++;
            // }
            //testing
            // if (cStorage[i] != EOF){
            //   printf("%c",cStorage[i]);//test
            // }
            //printf("Letter pairs: %c, %c\n", alphaGet[counterGet-1], alphaPut[counterPut-1]);
            //First = 1;
        //  }
          for (short i = 0; (fscanf(cypher,"%c %c\n", &alphaGet[i], &alphaPut[i]) == 2); i++){
            //printf("Answers: %c, %c\n", alphaGet[i], alphaPut[i]); //test
          }
          inputBuffer = fgetc(clear);
          if (inputBuffer <= 122 && inputBuffer >= 97) {
            inputBuffer = LowerToUpper(inputBuffer);
          }
          while (inputBuffer != EOF) {
            for (short i = 0; (i <= CypherLength); i++) {
              if (alphaGet[i] == inputBuffer){
                inputBuffer = alphaPut[i];
                i = CypherLength; //out of the for loop
              }
            }
            if (inputBuffer != EOF) {
              fputc(inputBuffer, crypt); //output here
              //printf("Output is: %c\n", inputBuffer);//test
              inputBuffer = fgetc(clear);
              if (inputBuffer <= 122 && inputBuffer >= 97) {
                inputBuffer = LowerToUpper(inputBuffer);
              }
            }
            else {
              printf("ERROR 7 Your input file was empty. The required format is: <program executable> cypher.txt encrypt/decrypt input.txt output.txt\n");
            }
          }
          //end dealing with data
          printf("Encrypted.\n");
          fclose(cypher); //close cypher.txt
          fclose(clear); //close clear_text.txt
          fclose(crypt); //close crypt_text.txt
        }
      }
    }
  }
  else if (strcmp (argv[2],"decrypt") == 0){
    printf("Decrypting...\n");
    FILE *cypher = fopen(argv[1], "r"); //open cypher.txt
    if(!cypher)printf("ERROR 4 The required format is: <program executable> cypher.txt encrypt/decrypt input.txt output.txt\n");
    else{
      FILE *crypt = fopen(argv[3], "r"); //open input.txt
      if(!crypt)printf("ERROR 5 The required format is: <program executable> cypher.txt encrypt/decrypt input.txt output.txt\n");
      else{
        FILE *clear = fopen(argv[4], "w"); //open output.txt
        if(!clear)printf("ERROR 6 The required format is: <program executable> cypher.txt encrypt/decrypt input.txt output.txt\n");
        else{
          //deal with the data here
          //can i do the same thing as above?
          // for (short i = 0; cStorage[i] != EOF; i++) {
          //   if (i%4 == 0){
          //     alphaGet[i] = cStorage[i];
          //   }
          //   if (i%4 == 2){
          //     alphaPut[i] = cStorage[i];
          //   }
          //   cStorage[i]  = fgetc(cypher); //gets the first char in the cypher
          //   //testing
          //   printf("%c\n",cStorage[i]);
          // }
          //end dealing with data
          for (short i = 0; (fscanf(cypher,"%c %c\n", &alphaGet[i], &alphaPut[i]) == 2); i++){
            //printf("Answers: %c, %c\n", alphaGet[i], alphaPut[i]); //test
          }
          inputBuffer = fgetc(crypt);
          if (inputBuffer <= 122 && inputBuffer >= 97) {
            inputBuffer = LowerToUpper(inputBuffer);
          }
          while (inputBuffer != EOF) {
            for (short i = 0; (i <= CypherLength); i++) {
              if (alphaPut[i] == inputBuffer){
                inputBuffer = alphaGet[i];
                i = CypherLength; //out of the for loop
              }
            }
            if (inputBuffer != EOF) {
              fputc(inputBuffer, clear); //output here
              //printf("Output is: %c\n", inputBuffer);//test
              inputBuffer = fgetc(crypt);
              if (inputBuffer <= 122 && inputBuffer >= 97) {
                inputBuffer = LowerToUpper(inputBuffer);
              }
            }
            else {
              printf("ERROR 8 Your input file was empty. The required format is: <program executable> cypher.txt encrypt/decrypt input.txt output.txt\n");
            }
          }
          //stop dealing with data
          printf("Decrypted.\n");
          fclose(cypher); //close cypher.txt
          fclose(clear); //close crypt_text.txt
          fclose(crypt); //close clear_text.txt
        }
      }
    }
  }
  else{
    printf("You did not say whether to encrypt or decrypt. The required format is: <program executable> cypher.txt encrypt/decrypt input.txt output.txt\n");
  }
return 0;
} //end main
char LowerToUpper (char Lower){ //yolo
  char Upper = Lower - 32;
return Upper;
} //end LowerToUpper
