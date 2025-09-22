#include <stdio.h>
#include <stdlib.h>  
#include <string.h>

#define Table "insurance_data.csv" //constant value 
#define Max_Line 256
#define Max_Field 50

typedef struct {
    char insured_name[Max_Field];
    char insurance_type[Max_Field];
    char start_date[Max_Field];
    char end_date[Max_Field];
} InsuranceRecord;

void create_csv_if_not_exists();
int is_valid_date(const char *date_str);
void add_record();
void display_records();
void search_record();
void update_record();
void delete_record();
void show_menu();


int main(){
    int choice;
    show_menu();
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);
    while(1){
        while (getchar() != '\n'); 
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

void show_menu(){ //menu function
    printf("\n--- Health Insurance Management System ---\n");
    printf("1. Add a new record\n");
    printf("2. Display all records\n");
    printf("3. Search for a record\n");
    printf("4. Update a record\n");
    printf("5. Delete a record\n");
    printf("6. Exit\n");
}

int is_valid_date(const char *date_str){
    if (strlen(date_str) != 10) {
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            if (date_str[i] != '-') {
                return 0;
            }
        } else {
            if (date_str[i] < '0' || date_str[i] > '9') {
                return 0;
            }
        }
    }
    return 1;
}

void add_record() {
    printf("\n--- Add a New Record ---\n");
    InsuranceRecord record;

    printf("Enter Insured Name: ");
    fgets(record.insured_name, sizeof(record.insured_name), stdin);
    record.insured_name[strcspn(record.insured_name, "\n")] = 0;

    printf("Enter Insurance Type: ");
    fgets(record.insurance_type, sizeof(record.insurance_type), stdin);
    record.insurance_type[strcspn(record.insurance_type, "\n")] = 0;

    do {
        printf("Enter Start Date (YYYY-MM-DD): ");
        fgets(record.start_date, sizeof(record.start_date), stdin);
        record.start_date[strcspn(record.start_date, "\n")] = 0;
        if (!is_valid_date(record.start_date)) {
            printf("Invalid date format. Please use YYYY-MM-DD.\n");
        }
    } while (!is_valid_date(record.start_date));

    do {
        printf("Enter End Date (YYYY-MM-DD): ");
        fgets(record.end_date, sizeof(record.end_date), stdin);
        record.end_date[strcspn(record.end_date, "\n")] = 0;
        if (!is_valid_date(record.end_date)) {
            printf("Invalid date format. Please use YYYY-MM-DD.\n");
        }
    } while (!is_valid_date(record.end_date));

    FILE *file = fopen(Table, "a");
    if (file != NULL) {
        fprintf(file, "%s,%s,%s,%s\n", record.insured_name, record.insurance_type, record.start_date, record.end_date);
        printf("Record added successfully!\n");
        fclose(file);
    } else {
        perror("Error writing to file");
    }
}
void display_records(){printf("Hello");}
void search_record(){printf("Hello");}
void update_record(){printf("Hello");}
void delete_record(){printf("Hello");}
