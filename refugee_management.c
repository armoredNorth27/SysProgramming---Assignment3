//Name: Alexander Nedev
//Student Number: 101195595

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char *userid; // alphanumeric, 10 characters long, and must not contain any special characters
    char *name;
    char *profession;
    int age; // value is between 1 and 120
} Refugee;

typedef struct{
    int size; // size or the array, or the number of elements added to the array
    Refugee **elements; // contains the elements of the array
} Array;

//? Adds a new user to the users Array
void add_user(Array *users, char* userid, char *name, char *profession, int age);

//? Frees all manually allocated memory
void clear_list(Array *users);

//? Displays all users within the users Array
void display_users(Array *users);

//? Returns the user with the specified ID
Refugee* display_user(Array *users, char *userid);

//? Returns the youngest user in the database
Refugee* youngest_user(Array *users);

//? Removes the user with the specified userid
void remove_user(Array *users, char *userid);

//? Sorts the database in descending order of the user's age
void sort_data(Array *users);

//? Helper function: Prints out all fields with the associated refugee parameter
void print_refugee(Refugee *refugee);

int main(){

    //Starting initializations
    Array users = {0, NULL};
    char choice[100] = "";
    int true = 1;

    //Information for each refugee
    char userid[10] = "";
    char name[100] = "";
    char profession[100] = "";
    int age = -1;
    
    //Contains the bulk of the program will all function calls and
    //logic being implemented here
    while(true == 1){

        printf("============================\n");
        printf("What would you like to do?\n");
        printf("============================\n");
        printf("(E) Enter information\n");
        printf("(A) Display information\n");
        printf("(I) Display information for an individual\n");
        printf("(Y) Show youngest person\n");
        printf("(R) Remove a user\n");
        printf("(S) Sort data\n");
        printf("(Q) Quit\n");
        printf("----------------------------\n");

        printf("Enter a choice from the menu (E, A, I, Y, R, S, Q): ");
        scanf(" %s", choice);

        //* Adds a new user to the database
        if(toupper(choice[0]) == 'E' && strlen(choice) == 1){

            printf("Enter the user id: ");
            scanf(" %[^\n]s", userid);
            // Check if userid is alphanumeric and has a length of 10 chars max
            while( true == 1 ){

                //Checks length of userid
                if(strlen(userid) > 10){
                    printf("Sorry that's not a valid userid, try again. ");
                    scanf(" %[^\n]s", userid);
                }

                else{
                    // Goes through all characters and checks if they're alhpanumeric
                    for(int i=0; i<strlen(userid); i++){
                        if(isalnum(userid[i]) == 0){
                            break;
                        }
                        else if(i == strlen(userid)-1){
                            true = 0;
                        }
                    }

                    // If userid is not alphanumeric, ask again
                    if(true == 1){
                        printf("Sorry that's not a valid userid, try again. ");
                        scanf(" %[^\n]s", userid);
                    }
                }

            }
            true = 1;

            printf("Enter the name: ");
            scanf(" %[^\n]s", name);

            printf("Enter the occupation: ");
            scanf(" %[^\n]s", profession);

            printf("Enter the age: ");
            scanf(" %d", &age);
            // Checks if the 0 < age <= 120
            while( true == 1 ){

                if( (age < 1) || (age > 120) ){
                    printf("Please enter an age greater than 0 and less than or equal to 120: ");
                    scanf(" %d", &age);
                }
                else{
                    break;
                }

            }
            true = 1;

            add_user(&users, userid, name, profession, age);
        }

        //* Displays all refugees in the database
        else if(toupper(choice[0]) == 'A' && strlen(choice) == 1){
            display_users(&users);
        }

        //* Displays the user with the specified ID
        else if(toupper(choice[0]) == 'I' && strlen(choice) == 1){
            
            //Deals with empty databases
            if(users.size == 0){
                printf("The database is empty. There are no refugees to search for.\n");
            }

            //Handles all other cases
            else{
                printf("Enter the userid: ");
                scanf(" %[^\n]s", userid);
                // Check if userid is alphanumeric and has a length of 10 chars max
                while( true == 1 ){

                    //Checks length of userid
                    if(strlen(userid) > 10){
                        printf("Sorry that's not a valid userid, try again. ");
                        scanf(" %[^\n]s", userid);
                    }

                    else{
                        // Goes through all characters and checks if they're alhpanumeric
                        for(int i=0; i<strlen(userid); i++){
                            if(isalnum(userid[i]) == 0){
                                break;
                            }
                            else if(i == strlen(userid)-1){
                                true = 0;
                            }
                        }

                        // If userid is not alphanumeric, ask again
                        if(true == 1){
                            printf("Sorry that's not a valid userid, try again. ");
                            scanf(" %[^\n]s", userid);
                        }
                    }

                }
                true = 1;

                printf("The user found is: ");
                print_refugee(display_user(&users, userid));
            }

        }

        //* Displays the youngest user in the database
        else if(toupper(choice[0]) == 'Y' && strlen(choice) == 1){

            //Deals with databases that have 0 refugees
            if(users.size == 0){
                printf("The database is empty. There are no refugees.\n");
            }

            //Deals with all databases that have more than 1 refugee
            else{
                printf("The youngest user is: ");
                print_refugee(youngest_user(&users));
            }   
        }

        //* Removes a user from the database with a specified ID
        else if(toupper(choice[0]) == 'R' && strlen(choice) == 1){

            //Deals with empty refugee database
            if(users.size == 0){
                printf("Database is empty. Nothing can be removed.\n");
            }

            //Removes specified user if they exist
            else{
                printf("Enter the userid: ");
                scanf(" %[^\n]s", userid);
                // Check if userid is alphanumeric and has a length of 10 chars max
                while( true == 1 ){

                    //Checks length of userid
                    if(strlen(userid) > 10){
                        printf("Sorry that's not a valid userid, try again. ");
                        scanf(" %[^\n]s", userid);
                    }

                    else{
                        // Goes through all characters and checks if they're alhpanumeric
                        for(int i=0; i<strlen(userid); i++){
                            if(isalnum(userid[i]) == 0){
                                break;
                            }
                            else if(i == strlen(userid)-1){
                                true = 0;
                            }
                        }

                        // If userid is not alphanumeric, ask again
                        if(true == 1){
                            printf("Sorry that's not a valid userid, try again. ");
                            scanf(" %[^\n]s", userid);
                        }
                    }

                }
                true = 1;

                //Checks if user exists inside the database
                if(display_user(&users, userid)->age == -1){
                    printf("No such user exists.\n");
                }
                //If refugee exists, remove them from the database
                else{
                    remove_user(&users, userid);
                }

            }

        }

        //* Sorts the database in descending order of the user's age
        else if(toupper(choice[0]) == 'S' && strlen(choice) == 1){
            sort_data(&users);
        }

        //* Quits program
        else if(toupper(choice[0]) == 'Q' && strlen(choice) == 1){
            true = 0;
            printf("Quitting program...\n");
        }

        //* Deals with invalid input
        else{
            printf("Invalid selection, try again.\n");
        }

        printf("\n");
    }

    printf("Deallocating memory...\n");
    clear_list(&users);
    printf("Done, thank you for using this refugee_management system!\n");
    return 0;
}

//? Adds a new user to the users Array
void add_user(Array *users, char* userid, char *name, char *profession, int age){

    //Keeps track of where the new user needs to be added
    users->size += 1;
    int index = (users->size)-1;

    //Allocate memory for 1 refugee
    if(users->size == 1){
        users->elements = (Refugee**)malloc(sizeof(Refugee*));

        if(users->elements == NULL){
            printf("Memory allocation error\n");
            exit(0);
        }
    }
    //Allocate memory for an extra refugee everytime a new refugee is added
    else if(users->size > 1){
        users->elements = (Refugee**)realloc(users->elements, (users->size) * sizeof(Refugee*));

        if(users->elements == NULL){
            printf("Memory allocation error\n");
            exit(0);
        }
    }

    //Create new refugee structure
    Refugee *newRefugee = NULL;
    newRefugee = (Refugee*)malloc(sizeof(Refugee));
    if(newRefugee == NULL){
        printf("Memory allocation error\n");
        exit(0);
    }
    newRefugee->age = age;
    newRefugee->name = strdup(name);
    newRefugee->profession = strdup(profession);
    newRefugee->userid = strdup(userid);

    //Allocate memory to hold a new refugee
    users->elements[index] = NULL;
    users->elements[index] = newRefugee;
}

//? Displays all users within the users Array
void display_users(Array *users){

    //Handles empty databases
    if(users->size == 0){
        printf("Database is empty.\n");
    }
    
    //Prints out database as long as at least 1 user is present
    else{
        for(int i=0; i<users->size; i++){
            print_refugee(users->elements[i]);
        }
    }

}

//? Displays the user with the specified ID
Refugee* display_user(Array *users, char *userid){
    
    //If specified user isn't found, return an empty user
    Refugee *emptyRefugee;
    emptyRefugee->userid = "N/A";
    emptyRefugee->name = "N/A";
    emptyRefugee->profession = "N/A";
    emptyRefugee->age = -1;

    //Return an emptyRefugee if the database is empty
    if(users->size == 0){
        return emptyRefugee;
    }

    //Check if the refugee is in the database
    else{
        //Iterate through all users in the database and return
        //the one that has the matching ID
        for(int i=0; i<users->size; i++){
            if(strcmp(users->elements[i]->userid, userid) == 0){
                return users->elements[i];
            }
        }

        return emptyRefugee;
    }

}

//? Returns the youngest user in the database
Refugee* youngest_user(Array *users){

    //Returns an empty refugee is the database is empty
    if(users->size == 0){
        Refugee *emptyRefugee;
        emptyRefugee->age = -1;
        emptyRefugee->name = "N/A";
        emptyRefugee->profession = "N/A";
        emptyRefugee->userid = "N/A";

        return emptyRefugee;
    }

    //If the database only has 1 user, return that user
    else if(users->size == 1){
        return users->elements[0];
    }

    //If there's 2 or more users, find and return the youngest one
    else{
        //Set the current youngestRefugee to the first element
        //and go from there
        Refugee* youngestRefugee = users->elements[0];

        //Search all refugees in the database and compare them
        //to the youngest one. If a younger one is found, then
        //set that refugee to be the youngest one
        for(int i=1; i<users->size; i++){
            if(users->elements[i]->age < youngestRefugee->age){
                youngestRefugee = users->elements[i];
            }
        }

        return youngestRefugee;
    }

}

//? Removes the user with the specified userid
void remove_user(Array *users, char *userid){

    //tempUsers will hold all users excluding the one we want to remove
    Array *tempUsers;
    tempUsers->size = 0;
    tempUsers->elements = NULL;

    //Populates tempUsers
    for(int i=0; i<users->size; i++){
        //If the current user is the same as the one we want to remove, skip them
        if(strcmp(users->elements[i]->userid, userid) == 0){
            continue;
        }
        else{
            add_user(tempUsers, users->elements[i]->userid, users->elements[i]->name, users->elements[i]->profession, users->elements[i]->age);
        }
    }
    
    //Clears the database and repopulates it with all users in the tempUsers database.
    //Clears the tempUsers database when done so we're not wasting memory
    clear_list(users);
    for(int i=0; i<tempUsers->size; i++){
        add_user(users, tempUsers->elements[i]->userid, tempUsers->elements[i]->name, tempUsers->elements[i]->profession, tempUsers->elements[i]->age);
    }
    clear_list(tempUsers);
    printf("User successfully removed.\n");
    
}

//? Sorts the database in descending order of the user's age
void sort_data(Array *users){

    Array sortedUsers = {0, NULL};

    //Don't do anything if database has no users
    if(users->size == 0){
        printf("The database is empty, there's nothing to sort!\n");
    }

    //Don't do anything if the database has 1 user
    else if(users->size == 1){
        printf("The database is already sorted.\n");
    }

    //Sort database if it has more than 1 user
    else{

        //Continue sorting until all users have been sorted
        while(sortedUsers.size < users->size){
            Refugee *oldestRefugee = NULL;

            //When no refugees are sorted, search through all of them
            //and find the oldest one
            if(sortedUsers.size == 0){
                oldestRefugee = users->elements[0];

                for(int i=1; i<users->size; i++){
                    if(users->elements[i]->age > oldestRefugee->age){
                        oldestRefugee = users->elements[i];
                    }
                }
            }

            //When 1 refugee is left to sort, it must be the youngest
            //one, so just add it to the sorted list
            else if(sortedUsers.size == users->size-1){
                oldestRefugee = youngest_user(users);
            }

            //Deals with all other cases
            else{
                oldestRefugee = youngest_user(users);

                //Find oldest refugee not yet sorted
                for(int i=0; i<users->size; i++){ //* Iterate through all refugees in the database

                    for(int j=0; j<sortedUsers.size; j++){ //* Iterate through all refuges in the sorted database

                        //If current refugee is found inside of the sortedUsers database, skip them
                        if(strcmp(users->elements[i]->userid, sortedUsers.elements[j]->userid) == 0){
                            break;
                        }

                        //If we reach the end of the sortedUsers list, then the current user hasn't been added yet
                        else if(j == sortedUsers.size-1){
                            if(users->elements[i]->age > oldestRefugee->age){
                                oldestRefugee = users->elements[i];
                            }
                        }
                    }

                }
            }

            add_user(&sortedUsers, oldestRefugee->userid, oldestRefugee->name, oldestRefugee->profession, oldestRefugee->age);
        }

        //Set the users list to be the sorted list
        clear_list(users);
        for(int i=0; i<sortedUsers.size; i++){
            add_user(users, sortedUsers.elements[i]->userid, sortedUsers.elements[i]->name, sortedUsers.elements[i]->profession, sortedUsers.elements[i]->age);
        }
        clear_list(&sortedUsers);
        printf("Refugees have been sorted.\n");
    }

}

//? Frees all manually allocated memory
void clear_list(Array *users){

    //Free all memory that was assigned for each individual refugee
    for(int i=0; i<users->size; i++){
        free(users->elements[i]->name);
        users->elements[i]->name = NULL;
        free(users->elements[i]->profession);
        users->elements[i]->profession = NULL;
        free(users->elements[i]->userid);
        users->elements[i]->userid = NULL;
        free(users->elements[i]);
        users->elements[i] = NULL;
    }

    //Free the memory used to hold the array of all refugees
    free(users->elements);
    users->elements = NULL;

    //Set counter that tracks number of users to 0
    users->size = 0;
}

//? Helper function: Prints out all fields with the associated refugee parameter
void print_refugee(Refugee *refugee){
    printf("%s | %s | %s | %d\n", refugee->userid, refugee->name, refugee->profession, refugee->age);
}