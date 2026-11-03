
#include <stdio.h>
#include <string.h>

struct Expense {
    char date[20];
    char category[30];
    char description[50];
    float amount;
};

int main() {

    struct Expense e[100];
    int choice, count = 0, i;
    float total = 0;
    char search[30];

    do {

        printf("\n================================");
        printf("\n      PERSONAL EXPENSE TRACKER");
        printf("\n================================");
        printf("\n1. Add Expense");
        printf("\n2. View All Expenses");
        printf("\n3. Calculate Total Expenses");
        printf("\n4. Search Expense");
        printf("\n5. Exit");
        printf("\n================================");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:

                if(count >= 100) {
                    printf("\nExpense limit reached!");
                    break;
                }

                printf("\nEnter Date (DD-MM-YYYY): ");
                scanf("%19s", e[count].date);

                printf("Enter Category (Food/Travel/Shopping): ");
                scanf("%29s", e[count].category);

                printf("Enter Description: ");
                scanf(" %49[^\n]", e[count].description);

                printf("Enter Amount: ");
                scanf("%f", &e[count].amount);

                if(e[count].amount <= 0) {
                    printf("\nInvalid amount!");
                    break;
                }

                count++;

                printf("\nExpense Added Successfully!");

                break;


            case 2:

                if(count == 0) {
                    printf("\nNo Expenses Available!");
                    break;
                }

                printf("\n------ ALL EXPENSES ------");

                for(i = 0; i < count; i++) {

                    printf("\n\nDate: %s", e[i].date);
                    printf("\nCategory: %s", e[i].category);
                    printf("\nDescription: %s", e[i].description);
                    printf("\nAmount: Rs. %.2f", e[i].amount);

                }

                break;


            case 3:

                total = 0;

                for(i = 0; i < count; i++) {
                    total = total + e[i].amount;
                }

                printf("\nTotal Expenses = Rs. %.2f", total);

                break;


            case 4:

                printf("\nEnter Category to Search: ");
                scanf("%29s", search);

                int found = 0;

                for(i = 0; i < count; i++) {

                    if(strcmp(e[i].category, search) == 0) {

                        printf("\nDate: %s", e[i].date);
                        printf("\nDescription: %s", e[i].description);
                        printf("\nAmount: Rs. %.2f\n", e[i].amount);

                        found = 1;
                    }
                }

                if(found == 0) {
                    printf("\nNo Expense Found!");
                }

                break;


            case 5:

                printf("\nThank You for Using Expense Tracker!");

                break;


            default:

                printf("\nInvalid Choice! Please Try Again.");

        }

    } while(choice != 5);

    return 0;
}