set -e 
cc -g -std=c99 -c -I /opt/raylib/src linux_platform.c -o ./obj/linux_platform.o
cc -o linux_platform  obj/linux_platform.o -s -Wall -std=c99 -I/opt/raylib/src -L/opt/raylib/release/libs/linux -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./linux_platform
