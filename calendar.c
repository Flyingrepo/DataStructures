#include <stdio.h>
#include <stdlib.h>

#define MAX_DAYS 7


struct Day {
    char* dayName;
    int date;
    char* activityDescription;
};


void create(struct Day* day) {
    day->dayName = (char*)malloc(sizeof(char) * 20); 
    printf("Enter day name: ");
    scanf("%s", day->dayName);
    
    printf("Enter date: ");
    scanf("%d", &day->date);
    __fpurge(stdin);

    day->activityDescription = (char*)malloc(sizeof(char) * 100); 
    printf("Enter activity description: ");
    scanf(" %[^\n]", day->activityDescription); 
}

void read(struct Day* calendar) {
    for (int i = 0; i < MAX_DAYS; ++i) {
        printf("\nEnter details for day %d:\n", i + 1);
        create(&calendar[i]);
    }
}


void display(struct Day* calendar) {
    printf("\nWeek's Activity Details Report:\n");
    printf("%-10s %-10s %-30s\n", "Day", "Date", "Activity Description");
    for (int i = 0; i < MAX_DAYS; ++i) {
        printf("%-10s %-10d %-30s\n", calendar[i].dayName, calendar[i].date, calendar[i].activityDescription);
    }
}


void freeMemory(struct Day* calendar) {
    for (int i = 0; i < MAX_DAYS; ++i) {
        free(calendar[i].dayName);
        free(calendar[i].activityDescription);
    }
}

int main() {
    
    struct Day* calendar = (struct Day*)malloc(sizeof(struct Day) * MAX_DAYS);

    
    if (calendar == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    read(calendar);
    display(calendar);
    freeMemory(calendar);
    free(calendar);
    return 0;
}