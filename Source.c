#include <stdio.h>
#include <stdlib.h>
#include "header.h"



/*
@Description:check if the database is full
@Return Value:return 1 if the database is full, otherwise 0
*/
int SDB_IsFull(void)
{
	struct simpleDb* Is_full = (struct simpleDb*)malloc(sizeof(struct simpleDb));
	Is_full = (struct simpleDb*)first_elements;
	int i = 1;
	if (first_elements == NULL)
	{
		printf_s("this database is empty");
		return 0;
	}
	while (Is_full != current_elements)
	{
		Is_full = (struct simpleDb*)Is_full->next_student;
		i++;

	}
	if (i >= 10)
	{
		printf_s("this database is full");
		return 1;
	}
	else
	{
		printf_s("this database isnot full");
		return 0;
	}

	
}

/*
@description:Get the number of entiers in the database
@Return Value:return the number of entries
*/
int SDB_GetUsedSize(void)
{

	struct simpleDb* Is_full = (struct simpleDb*)malloc(sizeof(struct simpleDb));
	Is_full = (struct simpleDb*)first_elements;
	int i = 1;
	if (first_elements == NULL)
	{
		printf_s("this database is empty");
		return 0;
	}
	while (Is_full != current_elements)
	{
		Is_full = (struct simpleDb*)Is_full->next_student;
		i++;
		
	}
	printf_s("\n we used %d of the database", i);
	
	return i;

}

/*
@Description:Add new entry to the database
@Return Value:return 1 if the new entry is successfully added
@Input parameters-id:studentID,year:student_year,subjectsID:pointer to 3 subjects ID,grades:pointer to 3 grades
@the allowed range for the grades is only from 0 to 100
@Assume that the caller will always provide the 3 subjects with their grades
*/
int SDB_AddEntry(int id, int year, int* subjectID, int* grades)
{

	struct simpleDb* new_elements;
	if (first_elements == NULL)
	{
		new_elements = (struct simpleDb*)malloc(1 * sizeof(struct simpleDb));
		new_elements->student_ID = id;
		new_elements->student_year = year;
		new_elements->course_1_ID = subjectID[0];
		new_elements->course_2_ID = subjectID[1];
		new_elements->course_3_ID = subjectID[2];
		new_elements->course_1_Grade = grades[0];
		new_elements->course_2_Grade = grades[1];
		new_elements->course_3_grade = grades[2];
		new_elements->next_student = NULL;
		first_elements = (struct simpleDb*)new_elements;
		current_elements = (struct simpleDb*)new_elements;
		printf_s("\n%d", new_elements->student_ID);
		printf_s("\n%d", new_elements->student_year);
	


	}
	else
	{
		struct simpleDb* Is_full = (struct simpleDb*)malloc(sizeof(struct simpleDb));
		Is_full = (struct simpleDb*)first_elements;
		int i = 2;
		while (Is_full != current_elements)
		{
			Is_full = (struct simpleDb*)Is_full->next_student;
			i++;

		}
		if (i <= 10)
		{
			new_elements = (struct simpleDb*)malloc(1 * sizeof(struct simpleDb));
			current_elements->next_student = (struct simpleDb*)new_elements;
			current_elements = (struct simpleDb*)new_elements;
			new_elements->student_ID = id;
			new_elements->student_year = year;
			new_elements->course_1_ID = subjectID[0];
			new_elements->course_2_ID = subjectID[1];
			new_elements->course_3_ID = subjectID[2];
			new_elements->course_1_Grade = grades[0];
			new_elements->course_2_Grade = grades[1];
			new_elements->course_3_grade = grades[2];
			new_elements->next_student = NULL;
			printf_s("\n%d\n%d\n%d", new_elements->course_1_ID, new_elements->course_2_ID, new_elements->course_3_ID);
			printf_s("\n%d\n%d\n%d", new_elements->course_1_Grade, new_elements->course_2_Grade, new_elements->course_3_grade);

		}
		else
		{
			printf_s("\nthis database is completely full");
		}
		


		
	}
	
	return 0;

}

/*
@Description:Delete the entry with the given ID
@Input Parameter-id:ID of the entry to be deleted
*/
void SDB_DeleteEntey(int ID)
{
	struct simpleDb* last = (struct simpleDb*)malloc(sizeof(struct simpleDb));
	struct simpleDb* _2ndlast = (struct simpleDb*)malloc(sizeof(struct simpleDb));
	
	int flag = 0;
	if (first_elements == NULL)
	{
		printf_s("this database is empty");
	}
	else if (first_elements->next_student==NULL)
	{
		if (first_elements->student_ID==ID)
		{
			first_elements = NULL;
		}
		else
		{
			printf_s("this student is not in the database");
		}
	}
	else
	{
		last = (struct simpleDb*)first_elements;
		_2ndlast = (struct simpleDb*)first_elements->next_student;
		while (_2ndlast->next_student != NULL)
		{
			if (_2ndlast->student_ID==ID)
			{
				flag = 1;
				break;
			}
			_2ndlast = (struct simpleDb*)_2ndlast->next_student;
			last = (struct simpleDb*)last->next_student;
		}
		if (flag == 1)
		{
			last->next_student = (struct simpleDb*)_2ndlast->next_student;
			_2ndlast->next_student = NULL;
			free(_2ndlast);
		}
		else
		{
			printf_s("this Id is not found");
		}
		
	}
	
}

/*
@Description:read an entry matching the provided Id
@Return Value:Return 1 if the entry exist, otherwise 0
@Input Parameter-id:student ID
@Output Parrameter-year:Pointer to the student year
@Output Parrameter-subject:Pointer to the subjects
@Output Parrameter-grades:Pointer to the grades 
*/
int SDB_ReadEntry(int id)
{
	int flag = 0;
	struct simpleDb* vary = (struct simpleDb*)first_elements;//pointer that moves through all the database
	if (first_elements == NULL)
	{
		printf_s("this database is emply");
		return 0;
	}
	else
	{
		
		while (vary != NULL)
		{
			if (vary->student_ID == id)
			{
				flag = 1;
				break;
			}
			vary = (struct simpleDb*)vary->next_student;

		}
		if (flag == 1)
		{

			printf_s("this student is exist");
			printf_s("\n%d", vary->student_year);
			printf_s("\n%d\n%d\n%d", vary->course_1_ID, vary->course_2_ID, vary->course_3_ID);
			printf_s("\n%d\n%d\n%d", vary->course_1_Grade, vary->course_2_Grade, vary->course_3_grade);
			return 1;
		}
		else
		{
			printf_s("this student is not exist in this database");
			return 0;
		}

	}


	
}

/*
@Description:Get the list of the IDs of the students
*/
void SDB_GetIdList(void)
{
	struct simpleDb* vary = (struct simpleDb*)first_elements;//pointer that moves through all the database
	if (first_elements == NULL)
	{
		printf_s("this database is emply");
	}
	else
	{
		
		do
		{
			printf_s("\n%d", vary->student_ID);
			vary = (struct simpleDb*)vary->next_student;

		} while (vary != NULL);
		
	}


}

/*
@Description:Checks if the provided student ID exists
@Return Value:Return 1 if ID exists inthe Database, otherwise 0
*/
int SDB_IsIdExist(int ID)
{
	int flag = 0;
	struct simpleDb* vary = (struct simpleDb*)first_elements;//pointer that moves through all the database
	if (first_elements == NULL)
	{
		printf_s("this database is emply");
		return 0;
	}
	else
	{
		
		while (vary != NULL)
		{
			if (vary->student_ID == ID)
			{
				flag = 1;
				break;
			}
			
			vary = (struct simpleDb*)vary->next_student;

		}
		if (flag == 1)
		{
			printf_s("this student is exist");
			return 1;
		}
		else
		{
			printf_s("this student is not exist in this database");
			return 0;
		}
		
		
	}

	
}










