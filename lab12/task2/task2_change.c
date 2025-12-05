#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 512

int find_substring(const char *line, const char *old) {
    int i = 0, j;
    if (!*old) return 0;
    while (line[i]) {
        j = 0;
        while (line[i+j] && old[j] && line[i+j] == old[j])
            j++;
        if (!old[j])
            return i;
        i++;
    }
    return -1;
}

void change(char *line, const char *old, const char *new) {
    char buffer[MAX_LINE];
    int pos;

    while ((pos = find_substring(line, old)) != -1) {
        int i=0, k=0;

        // Copy everything to old
        for(i=0; i<pos && k<MAX_LINE-1; i++)
            buffer[k++] = line[i];

        // Copy new
        for(i=0; new[i] && k<MAX_LINE-1; i++)
            buffer[k++] = new[i];

        int old_len=0;
        while(old[old_len]) old_len++;

        for(i=pos+old_len; line[i] && k<MAX_LINE-1; i++)
            buffer[k++] = line[i];

        buffer[k]='\0';

        i=0;
        while(buffer[i]) {
            line[i] = buffer[i];
            i++;
        }
        line[i] = '\0';
    }
}

int main() {
    FILE *input = fopen("input.txt","r");
    if(!input) {
        perror("Error: File cannot be opened input.txt\n");
        return 1;
    }

    FILE *output = fopen("output.txt","w");
    if(!output) {
        perror("Error: File creation isn't possible output.txt\n");
        fclose(input);
        return 1;
    }

    char line[MAX_LINE];

    while(fgets(line, MAX_LINE, input)) {
        // main --> start
        change(line, "main()", "start()");
        // NULL --> nullptr
        change(line, "NULL", "nullptr");
        fputs(line, output);
    }

    fclose(input);
    fclose(output);

    printf("The result is ready, to view go to output.txt\n");
    return 0;
}
