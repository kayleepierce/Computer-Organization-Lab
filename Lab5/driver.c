/*
* Kaylee Pierce
* CPSC 2311-002
* kayleej@clemson.edu
* Instructor: Dr. Yvon Feaster
*/

#include "functions.h"

int main(int argc, char *argv[]) {
    assert(argc == 3 && "Please use: ./NAME program input_file output_file");

    FILE* input = fopen(argv[1], "r");
    assert(input != NULL && "Could not open the input file. Please try again");

    FILE* output = fopen(argv[2], "w");
    assert(output != NULL && "Could not open the output file. Please try again");

    node_t* head = NULL;

    head = createList(input, &head);

    printList(output, head);

    deleteList(&head);

    fclose(input);
    fclose(output);

    return 0;
}
