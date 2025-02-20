ssh name@lnxsrv13.seas.ucla.edu
scp minibomb skylar@lnxsrv13.seas.ucla.edu:~
objdump -d minibomb
./minibomb
gcc minibomb.c -Wall -Wpedantic -Werror -O0 -fno-inline -fno-pie -std=c99 -o minibomb