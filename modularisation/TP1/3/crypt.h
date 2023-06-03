#ifndef _CRYPT_H_
#define _CRYPT_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static const char square[8][8] = {
   {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},
   {'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'},
   {'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X'},
   {'Y', 'Z', '0', '1', '2', '3', '4', '5'},
   {'6', '7', '8', '9', ' ', '!', '"', '#'},
   {'$', '%', '&', '\'', '(', ')', '*', '+'},
   {',', '-', '.', '/', ':', ';', '<', '='},
   {'>', '?', '@', '[', '\\', ']', '^', '_'}
};

static const char alpha[26][6] = {
    ".-",   //A
    "-...", //B
    "-.-.", //C
    "-..",  //D
    ".",    //E
    "..-.", //F
    "--.",  //G
    "....", //H
    "..",   //I
    ".---", //J
    "-.-",  //K
    ".-..", //L
    "--",   //M
    "-.",   //N
    "---",  //O
    ".--.", //P
    "--.-", //Q
    ".-.",  //R
    "...",  //S
    "-",    //T
    "..-",  //U
    "...-", //V
    ".--",  //W
    "-..-", //X
    "-.--", //Y
    "--..", //Z
};

char* encryptRot13 (char* msg);
char* decryptRot13 (char* msg);
char* encryptPolybe(char* msg);
char* decryptPolybe(char* msg);
char* encryptMorse(char* msg);
char* decryptMorse(char* msg);

#endif