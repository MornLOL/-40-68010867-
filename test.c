#include <stdio.h>
#include <stdlib.h>  
#include <string.h>

#define Table "insurance_data.csv" //constant value 
#define Max_Line 256
#define Max_Field 50

void show_menu(){ //menu function
    printf("\n--- Health Insurance Management System ---\n");
    printf("1. Add a new record\n");
    printf("2. Display all records\n");
    printf("3. Search for a record\n");
    printf("4. Update a record\n");
    printf("5. Delete a record\n");
    printf("6. Exit\n");

    }
void add_record(){}
void display_records(){}
void search_record(){}
void update_record(){}
void delete_record(){}


int main(){
    int choice;
    show_menu();
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);
    switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                search_record();
                break;
            case 4:
                update_record();
                break;
            case 5:
                delete_record();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
     return 0;
}
void create_csv_if_not_exists() {
    FILE *file = fopen(Table, "r");
    if (file == NULL) {
        file = fopen(Table, "w");
        if (file != NULL) {
            fprintf(file, "InsuredName,InsuranceType,StartDate,EndDate\n");
            printf("Created a new file: %s\n", Table);
            fclose(file);
        } else {
            perror("Error creating file");
        }
    } else {
        fclose(file);
    }
}