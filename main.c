#include <stdio.h>
#include <stdlib.h>
#include "header.h"




int main(void)
{
	/*
	@variables
	*/
	int done = 0;
	int stdID = 456;
	int year = 2000;
	int _1course_ID = 2;
	int _2course_ID = 2;
	int _3course_ID = 2;
	int subjectIDs[3];
	int _1course_grade = 2;
	int _2course_grade = 2;
	int _3course_grade = 2;
	int grades[3];
	int num;
	struct simpleDb Db[10];

	/*
	@To call the functions
	*/
	while (done == 0)
	{
		printf_s("what operation do you want to make");
		printf_s("\n1)Add student\n2)check if the list is full\n3)get the used size of the data base\n4)delete student\n5)read the database IDs\n6)get sepesefic student\n7)if a student exists\n");
		scanf_s("%d", &num);
		fflush(stdin);

		switch (num)
		{
			case 1:
				printf_s("\nplease enter the required data\n");
				printf_s("Enter the student ID:");
				scanf_s("%d", &stdID);
				fflush(stdin);
				printf_s("\nEnter the student year:");
				scanf_s("%d", &year);
				fflush(stdin);
				printf_s("\nEnter the first course ID:");
				scanf_s("%d", &_1course_ID);
				fflush(stdin);
				printf_s("\nEnter the second course ID:");
				scanf_s("%d", &_2course_ID);
				fflush(stdin);
				printf_s("\nEnter the third course ID:");
				scanf_s("%d", &_3course_ID);
				fflush(stdin);
				printf_s("\nEnter the first course grade:");
				scanf_s("%d", &_1course_grade);
				fflush(stdin);
				printf_s("\nEnter the second course grade:");
				scanf_s("%d", &_2course_grade);
				fflush(stdin);
				printf_s("\nEnter the third course grade:");
				scanf_s("%d", &_3course_grade);
				subjectIDs[0] = _1course_ID;
				subjectIDs[1] = _2course_ID;
				subjectIDs[2] = _3course_ID;
				grades[0] = _1course_grade;
				grades[1] = _2course_grade;
				grades[2] = _3course_grade;

				SDB_AddEntry(stdID, year, subjectIDs, grades);
				break;

			case 2:
				SDB_IsFull();
				break;

			case 3:
				SDB_GetUsedSize();
				break;

			case 4:
				printf_s("\nEnter the ID of this student");
				scanf_s("%d", &stdID);
				SDB_DeleteEntey(stdID);
				break;
			
			case 5:
				SDB_GetIdList();
				break;

			case 6:
				printf_s("\nEnter the ID of this student");
				scanf_s("%d", &stdID);
				SDB_ReadEntry(stdID);

			case 7:
				printf_s("\nEnter the ID of this student");
				scanf_s("%d", &stdID);
				SDB_IsIdExist(stdID);
				break;
			
			default:
				break;
		}
		printf_s("\nif you want to make another operation press 0, otherwise 1\n");
		scanf_s("%d", &done);
		

	}
	
	return 0;
}
