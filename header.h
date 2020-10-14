

/*
structure of maximum 10 entries
*/
typedef struct simpleDb
{
	int student_ID;
	int student_year;
	int course_1_ID;
	int course_1_Grade;
	int course_2_ID;
	int course_2_Grade;
	int course_3_ID;
	int course_3_grade;
	struct simpleDb* next_student;
};

struct simpleDb* first_elements;
struct simpleDb* current_elements;



/*
@Description:check if the database is full
@Return Value:return 1 if the database is full, otherwise 0
*/
int SDB_IsFull(void);

/*
@description:Get the number of entiers in the database
@Return Value:return the number of entries
*/
int SDB_GetUsedSize(void);

/*
@Description:Add new entry to the database
@Return Value:return 1 if the new entry is successfully added
@Input parameters-id:studentID,year:student_year,subjectsID:pointer to 3 subjects ID,grades:pointer to 3 grades
@the allowed range for the grades is only from 0 to 100
@Assume that the caller will always provide the 3 subjects with their grades
*/
int SDB_AddEntry(int id, int year, int* subjectID, int* grades);

/*
@Description:Delete the entry with the given ID
@Input Parameter-id:ID of the entry to be deleted
*/
void SDB_DeleteEntey(int ID);


/*
@Description:read an entry matching the provided Id
@Return Value:Return 1 if the entry exist, otherwise 0
@Input Parameter-id:student ID
@Output Parrameter-year:Pointer to the student year
@Output Parrameter-subject:Pointer to the subjects
@Output Parrameter-grades:Pointer to the grades
*/
int SDB_ReadEntry(int id);


/*
@Description:Get the list of the IDs of the students
@Output Parameter-count:Pointer to the number of entries currently exists in the database
@outPut parameter-list:Pointer to the list of the IDs
*/
void SDB_GetIdList(void);


/*
@Description:Checks if the provided student ID exists
@Return Value:Return 1 if ID exists inthe Database, otherwise 0
*/
int SDB_IsIdExist(long ID);