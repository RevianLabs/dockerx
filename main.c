#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define str char *
#define APP_VERSION "0.0.1"

void printUsage() {
    printf("DockerX Version %s\n", APP_VERSION);
    printf("DockerX passes all arguments towards docker/podman with the addition of -e DISPLAY=:0 for X11 forwarding\n");
    printf("Requirements:\n"
           "\tDocker or Podman installed and available in your path.\n"
    );
    printf("Usage:\n"
           "\tdockerx -p 80:80 myimage:mytag\n"
    );
}

int main(int argc, const str argv[]) {
    if(argc < 2) {
        printUsage();
    }

    char command[1024];

    if (system("which docker > /dev/null 2>&1")) {
        if(system("which podman > /dev/null 2>&1")) {
            printUsage();
            return 1;
        }
        strcpy(command, "podman ");
    } else {
        strcpy(command, "docker ");
    }

    strcat(command, "run -e DISPLAY=:0 -v /tmp/.X11-unix:/tmp/.X11-unix ");

    *argv++;
    while(*argv) {
        strcat(command, *argv++);
        strcat(command, " ");
    }

    printf("command=%s", command);
    system(command);

    return 0;
}
