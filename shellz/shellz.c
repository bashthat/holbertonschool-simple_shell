#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>
#include <stdlib.h>
#include <wait.h>

#define SENTENCE_LEN 511
#define PATH_MAX 512

void printPrompt();
char *getUserName();
int numOfWords(const char sentence[]);
void parseString(char sentence[], char** parsedStr);
void freeArr(char** parsedStr);
void exeCommand(char** command);
void donePrint(int numOfCommands, int lengthOfCommands);

int main() {

char sentence[SENTENCE_LEN];
char** parsedStr;
int numOfCommands = 0, lengthOfCommands = 0, parsedStrLen;

while(1)
{
    printPrompt();
    if(fgets(sentence , SENTENCE_LEN, stdin) != NULL) {
        parsedStrLen = numOfWords(sentence);
        lengthOfCommands += (int) (strlen(sentence) - 1);
        numOfCommands++;
        if(parsedStrLen > 0) {
            parsedStr = (char **) malloc((parsedStrLen + 1) * sizeof(char*));
            if (parsedStr == NULL) {
                fprintf(stderr, "malloc failed");
                exit(1);
            }
            parsedStr[parsedStrLen] = NULL;
            parseString(sentence, parsedStr); //allocates the words in the array
            if(strcmp(parsedStr[0], "done") == 0 && parsedStrLen == 1)
            {
                donePrint(numOfCommands, lengthOfCommands);
                freeArr(parsedStr);
                break;
            }
            pid_t id;
            id = fork();
            if (id < 0) {
                perror("ERR");
                freeArr(parsedStr);
                exit(1);
            }
            else if (id == 0) {
                exeCommand(parsedStr);
                freeArr(parsedStr);
            }
            else {
                wait(NULL);
                freeArr(parsedStr);
            }
        }
    }
}
return 0;
    }


//Prints prompt in the following format user@current dir>, if getUserName or getcwd fails -
// print NULL in their place
void printPrompt()
{
    char* userName = getUserName();
    char currentDir[PATH_MAX];

    getcwd(currentDir, sizeof (currentDir));
    printf("%s@%s>", userName, currentDir);
}

//Returns the user name as a char*, if getpwuid fails - return NULL
char *getUserName()
{
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);
    if (pw)
        return pw->pw_name;
    else {
        return NULL;
    }
}

//receives a sentence and returns the number of words in it, ignoring blank spaces
int numOfWords(const char sentence[] )
{
    int i = 0, wordCounter = 0;
    while(sentence[i] != '\n')
    {
        if(sentence[i] != ' ' && (sentence[i+1] == ' ' || sentence[i+1] == '\n'))
            wordCounter++;
        i++;
    }
    return wordCounter;
}

/*receives a sentence as a char[] and a char**
 *assign dynamically the sentence words into the char**
 */
void parseString(char sentence[], char** parsedStr) {
    char tmpWord[SENTENCE_LEN];
    int tmpIndex = 0, parsedIndex = 0;
    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] != ' ' && sentence[i] != '\n') {
            tmpWord[tmpIndex] = sentence[i];
            tmpIndex++;
        }
            //End of word
        else if ((sentence[i] == ' ' || sentence[i] == '\n') && tmpIndex > 0) {
            tmpWord[tmpIndex] = '\0';
            parsedStr[parsedIndex] = (char *) malloc((strlen(tmpWord)) + 1);
            if (parsedStr[parsedIndex] == NULL) {
                freeArr(parsedStr);
                fprintf(stderr, "malloc failed");
                exit(1);
            }
            strcpy(parsedStr[parsedIndex], tmpWord);
            parsedIndex++;
            tmpIndex = 0;
        }
    }
}

//Receives an array and free each cell from 0 to the first NULL
void freeArr(char** parsedStr) //---should maybe get the array size although?
{
    int i =0;
    while(parsedStr[i])
        free(parsedStr[i++]);
    free(parsedStr);
}


// Receives a command to execute as an array** and execute it using execvp, cd not supported
void exeCommand(char** command)
{
    if(strcmp(command[0], "cd") == 0) {
        printf("command not supported (YET)\n");
        freeArr(command);
        exit(0);
    }
    else if(execvp(command[0], command) != -1)
    {
        freeArr(command);
        exit(0);
    }
    else {
        perror("command not found");
        freeArr(command);
        exit(1);
    }
}
