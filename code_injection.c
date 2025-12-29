#include <stdio.h>

void vulnerable() {
    char buf[16];
    gets(buf);   
}

int main() {
    vulnerable();
    return 0;
}

