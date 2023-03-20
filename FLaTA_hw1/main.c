#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct binaryNode {
    char data[64];
    struct binaryNode *pointer;
} binaryNode_t;

binaryNode_t *createBinaryNode(char data[64]) {
    binaryNode_t *node = malloc(sizeof(binaryNode_t));
    strcpy(node->data, data);
    node->pointer = NULL;
    return node;
}

int binaryToDecimal(char binaryNumber[64]) {
    int power = 1, decimalNumber = 0;
    for (int i = strlen(binaryNumber) - 1; i != -1; i--) {
        if (binaryNumber[i] == '1')
            decimalNumber += power;
        power <<= 1;
    }
    return decimalNumber;
}

void printBinarySet(binaryNode_t *head) {
    binaryNode_t *temporary = head;
    while (temporary != NULL) {
        printf("%s\n", temporary->data);
        temporary = temporary->pointer;
    }
}
void printDecimalSet(binaryNode_t *head) {
    binaryNode_t *temporary = head;
    while (temporary != NULL) {
        printf("%d\n", binaryToDecimal(temporary->data));
        temporary = temporary->pointer;
    }
}

bool isUniqueNode(binaryNode_t *head, char data[64]) {
    binaryNode_t *temporary = head;
    while (temporary != NULL) {
        if (strcmp(temporary->data, data) == 0)
            return false;
        temporary = temporary->pointer;
    }
    return true;
}

int isBinary(char data[]) {
    int isBinary = 1;

    if (strcmp(data, "/exit") == 0) {
        return 2;
    }
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == '0' || data[i] == '1')
            isBinary = 0;
        else
            return 1;
    }
    return isBinary;
}

int main() {
    binaryNode_t *binaryHeadNode = NULL;
    binaryNode_t *binaryTemporaryNode;

    int choice;
    char data[64] = "0";

    puts("Start entering binary digits: (Enter '/exit' to exit)");

    while (strcmp(data, "/exit") != 0) {
        scanf("%s", data);
        if (isBinary(data) == 0) {
            if (isUniqueNode(binaryHeadNode, data)) {
                binaryTemporaryNode = createBinaryNode(data);
                binaryTemporaryNode->pointer = binaryHeadNode;
                binaryHeadNode = binaryTemporaryNode;
            } else
                puts("This number is not unique! Try again");
        } else if (isBinary(data) == 2) {
            puts("Binary set filling finished");
        } else
            puts("Please enter a binary digit!");
    }
    printBinarySet(binaryHeadNode);

    puts("If you want to convert binary numbers of this set to decimal numbers, type '0'. "
           "Otherwise, type '1'");
    scanf("%d", &choice);

    if (choice == 0) {
        puts("Converted binary set:");
        printDecimalSet(binaryHeadNode);
    }
    return 0;
}
