#include <stdio.h>

int P10[] = {3,5,2,7,4,10,1,9,8,6};
int P8[]  = {6,3,7,4,8,5,10,9};
int IP[]  = {2,6,3,1,4,8,5,7};
int IP_INV[] = {4,1,3,5,7,2,8,6};
int EP[]  = {4,1,2,3,2,3,4,1};
int P4[]  = {2,4,3,1};

int S0[4][4] = {
    {1,0,3,2},
    {3,2,1,0},
    {0,2,1,3},
    {3,1,3,2}
};

int S1[4][4] = {
    {0,1,2,3},
    {2,0,1,3},
    {3,0,1,0},
    {2,1,0,3}
};

void permute(int* input, int* table, int size, int* output) {
    int i;
    for(i = 0; i < size; i++)
        output[i] = input[table[i] - 1];
}

void leftShift(int* bits, int size, int shifts) {
    int i, j, first;
    for(i = 0; i < shifts; i++) {
        first = bits[0];
        for(j = 0; j < size - 1; j++)
            bits[j] = bits[j + 1];
        bits[size - 1] = first;
    }
}

void XOR(int* a, int* b, int size, int* result) {
    int i;
    for(i = 0; i < size; i++)
        result[i] = a[i] ^ b[i];
}

void generateKeys(int* key, int* K1, int* K2) {
    int permutedKey[10];
    int left[5];
    int right[5];
    int combined[10];
    int i;
    
    permute(key, P10, 10, permutedKey);
    
    for(i = 0; i < 5; i++) {
        left[i] = permutedKey[i];
        right[i] = permutedKey[i + 5];
    }
    
    leftShift(left, 5, 1);
    leftShift(right, 5, 1);
    
    for(i = 0; i < 5; i++) {
        combined[i] = left[i];
        combined[i + 5] = right[i];
    }
    
    permute(combined, P8, 8, K1);
    
    leftShift(left, 5, 2);
    leftShift(right, 5, 2);
    
    for(i = 0; i < 5; i++) {
        combined[i] = left[i];
        combined[i + 5] = right[i];
    }
    
    permute(combined, P8, 8, K2);
}

void F_function(int* right, int* key, int* result) {
    int expanded[8];
    int xored[8];
    int left[4];
    int rightHalf[4];
    int row, col, val;
    int s0[2], s1[2];
    int combined[4];
    
    permute(right, EP, 8, expanded);
    XOR(expanded, key, 8, xored);
    
    left[0] = xored[0];
    left[1] = xored[1];
    left[2] = xored[2];
    left[3] = xored[3];
    
    rightHalf[0] = xored[4];
    rightHalf[1] = xored[5];
    rightHalf[2] = xored[6];
    rightHalf[3] = xored[7];
    
    row = left[0] * 2 + left[3];
    col = left[1] * 2 + left[2];
    val = S0[row][col];
    s0[0] = val / 2;
    s0[1] = val % 2;
    
    row = rightHalf[0] * 2 + rightHalf[3];
    col = rightHalf[1] * 2 + rightHalf[2];
    val = S1[row][col];
    s1[0] = val / 2;
    s1[1] = val % 2;
    
    combined[0] = s0[0];
    combined[1] = s0[1];
    combined[2] = s1[0];
    combined[3] = s1[1];
    
    permute(combined, P4, 4, result);
}

void encrypt(int* plaintext, int* K1, int* K2, int* ciphertext) {
    int permuted[8];
    int left[4];
    int right[4];
    int fResult[4];
    int newLeft[4];
    int temp[4];
    int combined[8];
    int i;
    
    permute(plaintext, IP, 8, permuted);
    
    for(i = 0; i < 4; i++) {
        left[i] = permuted[i];
        right[i] = permuted[i + 4];
    }
    
    F_function(right, K1, fResult);
    XOR(left, fResult, 4, newLeft);
    
    for(i = 0; i < 4; i++) {
        temp[i] = right[i];
        right[i] = newLeft[i];
        left[i] = temp[i];
    }
    
    F_function(right, K2, fResult);
    XOR(left, fResult, 4, newLeft);
    
    for(i = 0; i < 4; i++) {
        combined[i] = newLeft[i];
        combined[i + 4] = right[i];
    }
    
    permute(combined, IP_INV, 8, ciphertext);
}

int main() {
    int key[10] = {1,0,1,0,0,0,0,0,1,0};
    int plaintext[8] = {1,0,0,1,0,1,1,1};
    int K1[8], K2[8];
    int ciphertext[8];
    int i;
    
    generateKeys(key, K1, K2);
    encrypt(plaintext, K1, K2, ciphertext);
    
    printf("Ciphertext: ");
    for(i = 0; i < 8; i++)
        printf("%d", ciphertext[i]);
    printf("\n");
    
    return 0;
}

