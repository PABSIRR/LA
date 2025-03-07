#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* secret = "pretty pretty pretty pretty pretty pretty please don't blow up\n";

void explode() {
    puts("BOOM! The bomb exploded. You lost 100% of your grade (it went from 0 to 0).");
    exit(1);
}

void defuse() {
    puts("You defused the bomb!");
    FILE* flagfile = fopen("flag.txt", "r");
    if (flagfile == NULL) {
        puts("Couldn't read flag file. Try connecting to the server to run instead.");
    } else {
        char buf[256];
        fgets(buf, 256, flagfile);
        buf[strcspn(buf, "\n")] = '\0';
        puts("Here's the flag:");
        puts(buf);
    }
    exit(0);
}

int magic(int n) {
    int v = 10;
    switch (n) {
        case 7:
            v = 0;
            break;
        case 9:
            v = 1;
        case 10:
            v += 1;
        case 12:
            v *= 2;
            break;
        case 13:
            v = 42;
            break;
        case 14:
            v = 1337;
            break;
        default:
            v = -1;
    }
    return v;
}
int mystery2(long long n){
    if(n == 1){
        return 1;
    } else {
        return n * mystery2(n-1);;
    }

}
int main(void) {
    setbuf(stdout, NULL);
    char buf[256];

    // Part 1
    puts("What's the password?");
    fgets(buf, 256, stdin);
    if (strcmp(buf, secret) != 0) {
        explode();
    }
    // Part 2
    puts("What's the number cuh?");
    fgets(buf, 256, stdin);
    long long n = atoll(buf);
    if(mystery2(n) != 24){
        explode();
    }
    puts("What's my favorite number?");
    fgets(buf, 256, stdin);
    int x = atoi(buf);
    if (magic(x) != 22) {
        explode();
    }
    defuse();
    return 0;
}
