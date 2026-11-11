#include <stdio.h>
#include <stdlib.h>
int input_choice() {
    int choice;
    printf("Enter a number 1 to 3. 4 to quit\n");
    scanf("%d", &choice);
    return choice;
}
void process_choice(int choice) {
    switch (choice) {
        case 1:
            printf("Choice is 1\n");
            break;
        case 2:
            printf("Choice is 2\n");
            break;
        case 3:
            printf("Choice is 3\n");
            break;
        case 4:
            printf("Quitting the game...\n");
            exit(0); // Exits the program successfully
        default:
            printf("Invalid choice. Please renter.\n");
            break;
    }
}
int main() {
    int choice;
    do{
        choice = input_choice();
        process_choice(choice);
    } while (choice != 4);
    return 0;
}