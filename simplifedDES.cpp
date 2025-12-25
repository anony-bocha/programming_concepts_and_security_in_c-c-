#include <iostream>
#include <vector>
using namespace std;
/*Here we implement the Simplified DES (S-DES) algorithm
the following are some of the utilities to be used in the implementation*/
/* ---------- Permutation Tables ---------- */
int P10[] = {3,5,2,7,4,10,1,9,8,6};
int P8[]  = {6,3,7,4,8,5,10,9};
int IP[]  = {2,6,3,1,4,8,5,7};
int IP_INV[] = {4,1,3,5,7,2,8,6};
int EP[]  = {4,1,2,3,2,3,4,1};
int P4[]  = {2,4,3,1};
/*Remeber the substitution box from our lecture class and this table is the S-Box table (S1 and S2)*/
/* ---------- S-Boxes ---------- */
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

/* These are additional utility functions to perform permutations, shift operations and XOR operations */

// Perform permutation
vector<int> permute(vector<int> input, int* table, int size) {
    vector<int> output;
    for(int i = 0; i < size; i++)
        output.push_back(input[table[i] - 1]);
    return output;
}

// Left circular shift
vector<int> leftShift(vector<int> bits, int shifts) {
    while(shifts--) {
        int first = bits[0];
        bits.erase(bits.begin());
        bits.push_back(first);
    }
    return bits;
}

// XOR operation
vector<int> XOR(vector<int> a, vector<int> b) {
    vector<int> result;
    for(size_t i = 0; i < a.size(); i++)
        result.push_back(a[i] ^ b[i]);
    return result;
}
/*here is the key generation section*/
/* ---------- Key Generation ---------- */
void generateKeys(vector<int> key, vector<int> &K1, vector<int> &K2) {
    vector<int> permutedKey = permute(key, P10, 10);

    vector<int> left(permutedKey.begin(), permutedKey.begin() + 5);
    vector<int> right(permutedKey.begin() + 5, permutedKey.end());

    left = leftShift(left, 1);
    right = leftShift(right, 1);

    vector<int> combined;
    combined.insert(combined.end(), left.begin(), left.end());
    combined.insert(combined.end(), right.begin(), right.end());
    K1 = permute(combined, P8, 8);

    left = leftShift(left, 2);
    right = leftShift(right, 2);

    combined.clear();
    combined.insert(combined.end(), left.begin(), left.end());
    combined.insert(combined.end(), right.begin(), right.end());
    K2 = permute(combined, P8, 8);
}
/*Remember the F function we have leaned in a class that perorms the Feistel cipher*/
/* ---------- F Function ---------- */
vector<int> F(vector<int> right, vector<int> key) {
    vector<int> expanded = permute(right, EP, 8);
    vector<int> xored = XOR(expanded, key);

    vector<int> left(xored.begin(), xored.begin() + 4);
    vector<int> rightHalf(xored.begin() + 4, xored.end());

    int row = left[0] * 2 + left[3];
    int col = left[1] * 2 + left[2];
    int val = S0[row][col];

    vector<int> s0 = {val / 2, val % 2};

    row = rightHalf[0] * 2 + rightHalf[3];
    col = rightHalf[1] * 2 + rightHalf[2];
    val = S1[row][col];

    vector<int> s1 = {val / 2, val % 2};

    vector<int> combined;
    combined.insert(combined.end(), s0.begin(), s0.end());
    combined.insert(combined.end(), s1.begin(), s1.end());

    return permute(combined, P4, 4);
}

/* ---------- Encryption ---------- */
vector<int> encrypt(vector<int> plaintext, vector<int> K1, vector<int> K2) {
    vector<int> permuted = permute(plaintext, IP, 8);

    vector<int> left(permuted.begin(), permuted.begin() + 4);
    vector<int> right(permuted.begin() + 4, permuted.end());

    vector<int> fResult = F(right, K1);
    vector<int> newLeft = XOR(left, fResult);

    // Swap
    vector<int> temp = right;
    right = newLeft;
    left = temp;

    fResult = F(right, K2);
    newLeft = XOR(left, fResult);

    vector<int> combined;
    combined.insert(combined.end(), newLeft.begin(), newLeft.end());
    combined.insert(combined.end(), right.begin(), right.end());

    return permute(combined, IP_INV, 8);
}

/* ---------- Main ---------- */
int main() {
    vector<int> key = {1,0,1,0,0,0,0,0,1,0};
    vector<int> plaintext = {1,0,0,1,0,1,1,1};

    vector<int> K1, K2;
    generateKeys(key, K1, K2);

    vector<int> ciphertext = encrypt(plaintext, K1, K2);

    cout << "Ciphertext: ";
    for(int bit : ciphertext)
        cout << bit;
    cout << endl;

    return 0;
	
}

