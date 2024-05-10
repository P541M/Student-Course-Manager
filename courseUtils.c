#include "functionHeaders.h"

//Function 1 defnition - Finished.
FILE *openFileForReading(char fileName [MAX_STR]){
    
    FILE * filePointer = fopen(fileName, "r");

    //If statement to verity if file is valid.
    if(filePointer == NULL){
        return NULL;
    }
    else{
        return filePointer;
    }
}

//Funciton 2 definition - Finished.
int readCourse (char filename [MAX_STR], struct courseStruct courseInfo [NUMBER_COURSES]){

    //Declaration of variable(s) for later usage.
    int i = 0;
    int x = 0;
    int lineAmount = 1;
    char characterFromFile;

    //Open file for reading.
    FILE * filePointer = openFileForReading(filename);

    //If statement to validate the file.
    if(filePointer != NULL){
        
        //While loop that reads the characters.
        while(!feof(filePointer)){
            characterFromFile = getc(filePointer);
            
            //If statement that counts the lines in the file.
            if(characterFromFile == '\n'){
                lineAmount++;
            }
        }
        //Brings the file pointer to the start of the file.
        rewind(filePointer);

        //If statement to check if the line amount is equal.
        if(lineAmount == 2 * NUMBER_COURSES){
            for(i = 0; i < ((2 * NUMBER_COURSES) - 1 ); i++){
                if(i <= (NUMBER_COURSES - 1)){                   
                    fgets(courseInfo[i].courseName, MAX_STR, filePointer);
                    
                    //For loop that replaces the new line with a null.
                    for(x = 0; x < MAX_STR; x++){              
                        if(courseInfo[i].courseName[x] == '\n' ){
                            courseInfo[i].courseName[x] = '\0';
                        }
                    }
                    printf("%s \n", courseInfo[i].courseName);
                }
                //Reads course ID.
                if(i >= NUMBER_COURSES){
                    fscanf(filePointer, " %d", &courseInfo[i - NUMBER_COURSES].courseID);
                    printf("%d \n", courseInfo[i - NUMBER_COURSES].courseID);
                }
                
            }
            //Closes file.
            fclose(filePointer);
            return 1;
        }
        else{
            //Returns -1 if the line count is not equal.
            return -1;
        }
    }
    else{
        //Returns -1 if the file is null.
        return -1;
    }
}

//Funciton 3 definition - Finished.
int readProfAndCoursesTaught (char filename [MAX_STR], struct profStruct profInfo [NUMBER_PROFS], struct courseStruct courseInfo [NUMBER_COURSES]){

    //Declaration of variable(s) for later usage.
    int i;
    int x;
    // int tempCourseID = 0;
    char tempCourseYN[NUMBER_PROFS][MAX_STR];
    FILE * filePointer = openFileForReading(filename);

    //If statement to validate the file.
    if(filePointer != NULL){
        for(i = 0; i < (2 * NUMBER_PROFS); i++){
            if(i < NUMBER_PROFS){
                fscanf(filePointer, " %s", profInfo[i].profName);
                printf("%s ", profInfo[i].profName);
            }

            //Reads and stores the info of each course taught by the prof.
            if(i >= NUMBER_PROFS){
                
                fscanf(filePointer, " %s", tempCourseYN[i - 6]);

                for(x = 0; x < NUMBER_COURSES; x++){

                    //Converts the data to lowercase.
                    tempCourseYN[i - 6][x] = tolower(tempCourseYN[i - 6][x]);

                    //If statement to check if prof teaches the course.
                    if(tempCourseYN[i - 6][x] == 'y'){
                        profInfo[i - 6].coursesTaught[x] = courseInfo[x].courseID;
                    }
                    else if(tempCourseYN[i - 6][x] == 'n'){
                        profInfo[i - 6].coursesTaught[x] = -1;
                    }
                    printf("%d ", profInfo[i - 6].coursesTaught[x]);
                }
            }
        }
    }
    else{
        
        fclose(filePointer);
        return -1;
    }
    //Closes file.
    fclose(filePointer);
    return 1;
}

//Funciton 4 definition - Finished.
int nCourses (int n, struct profStruct profInfo [NUMBER_PROFS], char profsNCourses [NUMBER_PROFS][MAX_STR]){

    //Declaration of variable(s) for later usage.
    int i = 0;
    int x = 0;

    //For loop to look through all the professors.
    for(i = 0; i < NUMBER_PROFS; i++){
        int coursesTaught = 0;

        //For loop to look through all the courses.
        for(x = 0; x < NUMBER_COURSES; x++){

            //If statement to increment if it goes by a course that is being taught.
            if(profInfo[i].coursesTaught[x] > 0){
                coursesTaught++;
            }
        }

        //If statement to add the prof name to the array.
        if(coursesTaught >= n){
            strcpy(profsNCourses[i], profInfo[i].profName);
            printf("%s\n", profsNCourses[i]);
        }

        //Resets incrementer for next cycle.
        coursesTaught = 0;
    }
    return i;
}

//Funciton 5 definition - Finished.
int getCourseName (int courseNum, char cNameFound [50], struct courseStruct courseInfo [NUMBER_COURSES]){

    //Gets input for course code.
    printf("What course would you want? (Enter code of course): ");
    scanf(" %d", &courseNum);

    //Goes through the courses and prints the given course name using the code.
    for(int i = 0; NUMBER_COURSES; i++){
        if(courseNum == courseInfo[i].courseID){
            strcpy(cNameFound, courseInfo[i].courseName);
            printf("The course name is: %s", cNameFound);
            return 1;
        }
    }
    return 0;
}

//Funciton 6 definition - Finished.
int getCourseNum (char cName [50], int * cNumFound, struct courseStruct courseInfo [NUMBER_COURSES]){

    //Gets input for course name.
    printf("What course code do you want? (Enter name of course): " );
    scanf(" %[^\n]s", cName);

    //Declaration of variable(s) for later usage.
    bool sameCourse = false;

    //For loop to look through the courses and find the course code.
    for (int i = 0; i < NUMBER_COURSES && !sameCourse; i++) {
        if((strcmp(cName, courseInfo[i].courseName)) == 0){
            sameCourse = true;
            *cNumFound = courseInfo[i].courseID;
            printf("The Program code is: %d", *cNumFound);
            return 1;
        }
    }
    return 0;
}

//Funciton 7 definition - Finished.
int profsTeachingCourse (int courseNum, struct profStruct profInfo [NUMBER_PROFS], char taughtBy [NUMBER_PROFS][MAX_STR]){

    //Gets input for course code.
    printf("What course would you like to find the profs for? (Enter code of course): ");
    scanf(" %d", &courseNum);

    //Declaration of variable(s) for later usage.
    int profAmount = 0;
    
    printf("This course is taught by: ");

    //For loop to look through the courses and find the profs teaching the course.
    for(int i = 0; i < NUMBER_PROFS; i++){
        for(int x = 0; x < NUMBER_PROFS; x++){
            if(courseNum == profInfo[i].coursesTaught[x]){
                profAmount++;
                strcpy(taughtBy[i], profInfo[i].profName);
                printf("%s ", taughtBy[i]);
            }
        }
    }
    return profAmount;
}

//Funciton 8 definition - Finished.
float avgNumCourses (struct profStruct profInfo [NUMBER_PROFS]) {

    //Declaration of variable(s) for later usage.
    float courses = 0;
    
    //For loop to look through all profs and courses.
    for (int i = 0; i < NUMBER_PROFS; i++) {
        for (int x = 0; x < NUMBER_COURSES; x++) {
            courses += profInfo[i].coursesTaught[x] > 0;
        }
    }
    
    //Calculation and print statement.
    float averageCourse = ceil((courses + 1)/ NUMBER_PROFS);
    printf("The average number of courses taught by a Prof is: %.2lf / %d = %.2lf", courses + 1, NUMBER_PROFS, averageCourse);
    return averageCourse;
}