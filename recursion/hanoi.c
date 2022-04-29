#include <stdio.h>
#include <stdlib.h>

static int step = 0;

void toh(int n, char from, char to, char aux);

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    toh(n, 'A', 'C', 'B');
    return 0;
}

void toh(int n, char from, char to, char aux) {
    step = step+1;
    if(n==1) {
        printf("\nMove disk 1 from rod %c to rod %c", from, to);
    } else {
        toh(n-1, from, aux, to);
        printf("\nMove disk %d from rod %c to rod %c", n, from, to);
        toh(n-1, aux, to, from);
    }
}




