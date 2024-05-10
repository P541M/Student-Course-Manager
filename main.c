#include "functionHeaders.h"

int main(int argc, char * argv[]){

    char fileNameOne[MAX_STR], fileNameTwo[MAX_STR];
    strcpy(fileNameOne, argv[1]);
    strcpy(fileNameTwo, argv[2]);
    char cName[50], cNameFound[50];
    int func2 = 0;
    int func3 = 0;
    int func4 = 0;
    int func5 = 0;
    int func6 = 0;
    int func7 = 0;
    float func8 = 0.0;
    int courseNum = 0;
    int cNumFound = 0;
    struct courseStruct courseInfo[NUMBER_COURSES];
    struct profStruct profInfo[NUMBER_PROFS];
    char profsNCourses[NUMBER_PROFS][MAX_STR];
    char taughtBy[NUMBER_PROFS][MAX_STR];


    //function "call" for task 1
    printf("Function 1\n-----------\n");
    printf("This function just opens the file.");
    printf("\n\n");

    //function call for task 2
    printf("Function 2\n-----------\n");
    func2 = readCourse(fileNameOne, courseInfo);
    printf("1 if successful: %d", func2);
    printf("\n\n");

    //function call for task 3
    printf("Function 3\n-----------\n");
    func3 = readProfAndCoursesTaught(fileNameTwo, profInfo, courseInfo);
    printf("\n1 if successful: %d", func3);
    printf("\n\n");

    //function call for task 4
    printf("Function 4\n-----------\n");
    func4 = nCourses(3, profInfo, profsNCourses);
    printf("%d", func4);
    printf("\n\n");

    //function call for task 5
    printf("Function 5\n-----------\n");
    func5 = getCourseName(courseNum, cNameFound, courseInfo);
    printf("\n1 if successful: %d", func5);
    printf("\n\n");

    //function call for task 6
    printf("Function 6\n-----------\n");
    func6 = getCourseNum(cName, &cNumFound, courseInfo);
    printf("\n1 if successful: %d", func6);
    printf("\n\n");

    //function call for task 7
    printf("Function 7\n-----------\n");
    func7 = profsTeachingCourse(courseNum, profInfo, taughtBy);
    printf("%d", func7);
    printf("\n\n");

    //function call for task 8
    printf("Function 8\n-----------\n");
    func8 = avgNumCourses(profInfo);
    printf("%f", func8);
    printf("\n\n");
  
    return 0;
}