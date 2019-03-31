//#include <pch.ch>
#include <bits/stdc++.h>
#define SubjectMaxSum 6
#define StudentMAxSum 5000 + 5
#define INF 0x7fffffff

inline void subjectNamePrint(int subject_number)
{
	switch(subject_number)
	{
		case 1 :
			std :: cout << "A";
			break;
		case 2 : 
			std :: cout << "B";
			break;
		case 3 : 
			std :: cout << "C";
			break;
		case 4 : 
			std :: cout << "D";
			break;
		case 5 : 
			std :: cout << "E";
			break;
		case 6 : 
			std :: cout << "F";
			break;
		default : 
			break;
	}
}

struct GradeNode
{
	int SubjectNumber;
	int SubjectGrade;
	bool BeenQualified;
	bool BeenEdited;
};

struct StudentNode
{
	std :: string StudentName;
	std :: string MatrikelNumber;

	int TotalGrade;
	int GradeOrder;
	GradeNode StudentGrade[SubjectMaxSum + 1]; 

	void print()
	{
		std :: cout << this->MatrikelNumber << "	" << this->StudentName << std :: endl;
		std :: cout << "TotalGrade : " << this->TotalGrade << "    Rank : " << this->GradeOrder << std :: endl;
		for(int i = 1; i <= SubjectMaxSum; ++ i)
		{
			if(this->StudentGrade[i].BeenEdited)
			{
				subjectNamePrint(i);
				std :: cout << "    " << this->StudentGrade[i].SubjectGrade << std :: endl;
			}
		}
	
		std :: cout << std :: endl;
	}
};

int command_order, balabala_cnt, tmp_subject_number;
bool MainCyclicFlag = true;
std :: vector<StudentNode> student_pool;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

void init()
{
	command_order = -1;	
}

inline void doNothing()
{
	system("cls");
	std :: cout << "do nothing !" << std :: endl;
	system("pause");
}

inline void balabala()
{
	std :: cout << "*********************  " << ++ balabala_cnt << "  **********************" << std :: endl;
	system("pause");
} 

inline int getPoolSize()
{
	return student_pool.size();
}

inline int typeTurn(std :: string str)
{
	if(str == "Q" || str == "q") return -113;

	int tmp = 0;
	for(int i = 0; i < str.size(); ++ i)
	{
		if(str[i] > '9' || str[i] < '0') return - 524;
		tmp = tmp * 10 + str[i] - '0';
	}
	return tmp;
}

/*
StudentNode* studentQuery(std :: string matrikel_number)
{
	std :: vector<StudentNode> :: iterator it;
	for(it = student_pool.begin(); it != student_pool.end(); )
	{
		if(it->MatrikelNumber == matrikel_number)
		{
			StudentNode* tmp = it;
			return tmp;
			break;
		}
		else
		{
			++ it;
		}
	}

	return NULL;
}

GradeNode* gradeQuery(std :: string matrikel_number, int subject_number)
{ 
	StudentNode* target = studentQuery(matrikel_number);
	std :: vector<GradeNode> :: iterator it;
	for(it = target->StudentGrade.begin(); it != target->StudentGrade.end(); )
	{
		if(it->SubjectNumber == subject_number)
		{
			return it;
			break;
		}
		else
		{
			++ it;
		}
	} 

	return NULL;
}

bool subjectQuery(std :: string matrikel_number, int subject_number)
{
	std :: vector<StudentNode> :: iterator it;
	std :: vector<GradeNode> :: iterator it_2;

	for(it = student_pool.begin(); it != student_pool.end(); )
	{
		if(it->MatrikelNumber == matrikel_number)
		{
			for(it_2 = it->StudentGrade.begin(); it_2 != it->StudentGrade.end();)
			{
				if(it_2->SubjectNumber == subject_number)
				{
					return true;
				}
				else
				{
					++ it_2;
				}
			}

			return false;
		}
		else
		{
			++ it;
		}
	}

	return false;
}
*/

bool studentQuery(std :: string matrikel_number)
{
	std :: vector<StudentNode> :: iterator it;
	for(it = student_pool.begin(); it != student_pool.end(); )
	{
		if(it->MatrikelNumber == matrikel_number)
		{
			return true;
			break;
		}
		else
		{
			++ it;
		}
	}

	return false;
}

bool subjectQuery(std :: string matrikel_number, int subject_number)
{
	std :: vector<StudentNode> :: iterator it;

	for(it = student_pool.begin(); it != student_pool.end(); )
	{
		if(it->MatrikelNumber == matrikel_number)
		{
			if(it->StudentGrade[subject_number].BeenEdited)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			++ it;
		}
	}

	return false;
}

inline void addStudent(std :: string matrikel_number, std :: string student_name)
{
	StudentNode tmp_student;
	tmp_student.MatrikelNumber = matrikel_number;
	tmp_student.StudentName = student_name;
	tmp_student.TotalGrade = 0;
	for(int i = 1; i <= SubjectMaxSum; ++ i)
	{
		tmp_student.StudentGrade[i].BeenEdited = false;
	}
	student_pool.push_back(tmp_student);

	std :: cout << matrikel_number << " " << student_name << "    added" << std :: endl;
}

void addStudent()
{
	system("cls");
	
	std :: string matrikel_number;
	std :: string student_name;

	//std :: cout << "add" << std :: endl;
	std :: cout << "#Enter the student number : " << std :: endl;
	std :: cin >> matrikel_number;
	if(matrikel_number == "q" || matrikel_number == "Q") return;
	std :: cout << "#Enter the student name : " << std :: endl; 
	std :: cin >> student_name;
	if(student_name == "q" || student_name == "Q") return;
	addStudent(matrikel_number, student_name);
	
	system("pause");
}

void deleteStudent(std :: string matrikel_number)
{
	std :: vector<StudentNode> :: iterator it;

	for(it = student_pool.begin(); it != student_pool.end(); )
	{
		if(it->MatrikelNumber == matrikel_number)
		{
			it = student_pool.erase(it);
			std :: cout << matrikel_number << "    deleted" << std :: endl;
			break;
		}
		else
		{
			++ it;
		}
	}
}

void deleteStudent()
{
	system("cls"); 
	
	//std :: cout << "del" << std :: endl;
	std :: string matrikel_number;
	std :: cout << "#Enter the student number : " << std :: endl;
	std :: cin >> matrikel_number;
	if(matrikel_number == "q" || matrikel_number == "Q") return;
	deleteStudent(matrikel_number);
	
	system("pause");
}

void addGrade(std :: string matrikel_number, int subject_number, int subject_grade)
{
	std :: vector<StudentNode> :: iterator it;

	for(it = student_pool.begin(); it != student_pool.end(); )
	{
		if(it->MatrikelNumber == matrikel_number)
		{
			it->StudentGrade[subject_number].SubjectGrade = subject_grade; 
			it->StudentGrade[subject_number].BeenQualified = (subject_grade >= 60) ? true : false;\
			it->StudentGrade[subject_number].BeenEdited = true;
			it->TotalGrade += subject_grade;
			std :: cout << matrikel_number << "    " << subject_number << " " << subject_grade << "    added" << std :: endl;
			break;
		}
		else
		{
			++ it;
		}
	}
}

void addGrade()
{
	system("cls"); 
	
	std :: cout << "#Subject Code : " << std :: endl;
	std :: cout << "#A    1	" << "B    2    " << "C    3" << std :: endl;	
	std :: cout << "#D    4	" << "E    5    " << "F    6" << std :: endl << std :: endl;

	bool flag = true;
	std :: string matrikel_number;
	std :: cout << "#Enter the student number : " << std :: endl;
	std :: cin >> matrikel_number;
	if(matrikel_number == "Q" || matrikel_number == "q") return; 

	if(! studentQuery(matrikel_number))
	{
		std :: cout << "#Student not found ! " << std :: endl;
		system("pause");
		return;
	}

	std :: string subject_number_str;
	std :: string subject_grade_str;
	int subject_number, subject_grade;
	while(flag) 
	{
		bool subject_number_judge = true;
		bool subject_grade_judge = true;
		while(subject_number_judge)
		{
			subject_number_judge = false;
			std :: cout << "#Enter the subject number : " << std :: endl;
			std :: cin >> subject_number_str;
			subject_number = typeTurn(subject_number_str);

			if(subject_number == -113) return;
			if(subjectQuery(matrikel_number, subject_number))
			{
				std :: string command_string;
				std :: cout << "#Grade of this subject has been added, do you want to edit the grade ? (Y / N)" << std :: endl;
				std :: cin >> command_string;

				if(command_string == "Y")
				{
					//std :: cout << "*** YES ***" << std :: endl;
					/*
					std :: vector<StudentNode> :: iterator it;
					std :: vector<GradeNode> :: iterator it_2;
					for(it = student_pool.begin(); it != student_pool.end(); )
					{
						if(it->MatrikelNumber == matrikel_number)
						{
							for(it_2 = it->StudentGrade.begin(); it_2 != it->StudentGrade.end();)
							{
								if(it_2->SubjectNumber == subject_number)
								{
									it_2 = it->StudentGrade.erase(it_2);
									break;
								}
								else
								{
									++ it_2;
								}
							}	
							break;
						}
						else
						{
							++ it;
						}
					}
					*/
				}
				else if(command_string == "N")
				{
					subject_number_judge = true;
				}
			}

			if(subject_number > SubjectMaxSum || subject_number < 1)
			{
				subject_number_judge = true;
				//std :: cout << "Input " << subject_number << std :: endl;
				std :: cout << "#Invalid subject code, please check it and type in again" << std :: endl;
			}
		}

		while(subject_grade_judge)
		{
			subject_grade_judge = false;
			std :: cout << "#Enter the subject score : " << std :: endl;
			std :: cin >> subject_grade_str;
			subject_grade = typeTurn(subject_grade_str);

			if(subject_grade == -113) return;
			if(subject_grade > 100 || subject_grade < 0)
			{
				subject_grade_judge = true;
				std :: cout << "#Invalid grade, please check it and type in again" << std :: endl;
			}
		}

		if(! flag) break;
		addGrade(matrikel_number, subject_number, subject_grade);
	}
}

void editCertainStudent()
{
	system("cls");
	std :: string str;
	std :: cout << "#Please type in the student number or name : " << std :: endl;
	std :: cin >> str;

	std :: vector<StudentNode> :: iterator it;
	bool flag = false;
	for(it = student_pool.begin(); it != student_pool.end(); ++ it)
	{
		if(it->MatrikelNumber == str || it->StudentName == str)
		{
			std :: cout << "#Student found" << std :: endl;
			it->print();
			flag = true;
			system("pause");
		}
		else
		{
			++ it;
		}
	}

	if(!flag) 
	{
		std :: cout << "#Student not found !" << std :: endl;
		system("pause");
		return; 
	}

	while(flag)
	{
		system("cls");
		std :: cout << "#Student information edit" << std :: endl;
		it->print();
		std :: cout << "#What do you want to do ?" << std :: endl;
		std :: cout << ">1    edit the student number" << std :: endl;
		std :: cout << ">2    edit the student name" << std :: endl;
		std :: cout << ">3    edit the score" << std :: endl;
		std :: cout << ">Q    return to the main interface" << std :: endl;
		std :: cin >> str;
		
		if(str == "Q" || str == "q")
		{
			return;
		}
		else if(str == "1")
		{
			
		}
	}
}

inline bool cmpAsMatrikelNumber(StudentNode x, StudentNode y)
{
	bool flag;
	flag = (x.MatrikelNumber.compare(y.MatrikelNumber) < 0) ? true : false;
	return flag;
} 

inline bool cmpAsTotalGrade(StudentNode x, StudentNode y)
{
	return x.TotalGrade > y.TotalGrade;
}

inline bool cmpAsSingleSubject(StudentNode x, StudentNode y)
{
	int subject_number = tmp_subject_number;
	if(x.StudentGrade[subject_number].SubjectGrade == y.StudentGrade[subject_number].SubjectGrade)
	{
		if(x.TotalGrade == y.TotalGrade)
		{
			bool flag = false;
			for(int i = 1; i <= SubjectMaxSum; ++ i)
			{
				if(i == subject_number) continue;
				if(x.StudentGrade[i].SubjectGrade > y.StudentGrade[i].SubjectGrade)
				{	
					flag = true;
					return true;
				}
				else if (x.StudentGrade[i].SubjectGrade < y.StudentGrade[i].SubjectGrade)
				{
					flag = true;
					return false;
				}
			}

			if(! flag) 
			{
				flag = (x.MatrikelNumber.compare(y.MatrikelNumber) < 0) ? true : false;
				return flag;
			}
		}
		return x.TotalGrade > y.TotalGrade;
	}
	return x.StudentGrade[subject_number].SubjectGrade > y.StudentGrade[subject_number].SubjectGrade;
}

void sortAsMatrikelNumber()
{
	std :: sort(student_pool.begin(), student_pool.end(), cmpAsMatrikelNumber);
}

void sortAsTotalGrade()
{
	std :: sort(student_pool.begin(), student_pool.end(), cmpAsTotalGrade);
	std :: vector<StudentNode> :: iterator it;
	int cnt = 0;	
	for(it = student_pool.begin(); it != student_pool.end(); ++ it)
	{
		it->GradeOrder = ++ cnt;
	}
}

void sortAsSingleSubject()
{
	system("cls");

	std :: string str;
	std :: cout << "#Please enter the subject code : " << std :: endl;
	std :: cin >> str;
	if(str == "Q" || str == "Q") return;
	tmp_subject_number == typeTurn(str);
	std :: sort(student_pool.begin(), student_pool.end(), cmpAsSingleSubject);
}

void printAll()
{
	system("cls");
	//std :: cout << "print" << std :: endl;
	//sortAsMatrikelNumber();
	std :: vector<StudentNode> :: iterator it;
	//std :: vector<GradeNode> :: iterator it_2;

	for(it = student_pool.begin(); it != student_pool.end(); ++ it)
	{
		/*
		std :: cout << it->MatrikelNumber << "	" << it->StudentName << std :: endl;
		std :: cout << "TotalGrade : " << it->TotalGrade << "    Rank : " << it->GradeOrder << std :: endl;

		/*
		if(it->StudentGrade.empty())
		{
			std :: cout << std :: endl;
			continue;
		}
		for(it_2 = it->StudentGrade.begin(); it_2 != it->StudentGrade.end(); ++ it_2)
		{
			subjectNamePrint(it_2->SubjectNumber);
			std :: cout << "    " << it_2->SubjectGrade << std :: endl;
		}
		*/
		/*
		for(int i = 1; i <= SubjectMaxSum; ++ i)
		{
			if(it->StudentGrade[i].BeenEdited)
			{
				subjectNamePrint(i);
				std :: cout << "    " << it->StudentGrade[i].SubjectGrade << std :: endl;
			}
		}
		
		std :: cout << std :: endl;
		*/
		it->print();
	}

	
	system("pause");
}

inline void getCommand()
{
	// 1 add    add a new student node
	// 2 del    delete a student node
	// 3 prt    print all the student nodes
	// 4 ssn    print as total grade
	system("cls");
	std :: cout << "#Please type command in with your keyboard" << std :: endl;
	std :: cout << ">ads   add a new student" << std :: endl;
	std :: cout << ">del   delets an existing student node" << std :: endl;
	std :: cout << ">prt   print all the existing student information" << std :: endl;
	std :: cout << ">ptg   print in order of total grade" << std :: endl;
	std :: cout << ">pss   print in order of certain subject score" << std :: endl;
	std :: cout << ">adg   add grades to a certain student" << std :: endl;
	//std :: cout << ">edt   locate single student file with student number or name" << std :: endl;
	std :: cout << "! You can return to the main interface anytime by pressing 'Q' " << std :: endl;
	std :: string command_string;
	std :: cin >> command_string;
	//system("pause");

	if(command_string == "ads")
	{
		command_order = 1;
	}
	else if(command_string == "del")
	{
		command_order = 2;
	}
	else if(command_string == "prt")
	{
		command_order = 3;
	}
	else if(command_string == "ptg")
	{
		command_order = 4;
	}
	else if(command_string == "pss")
	{
		command_order = 5;
	}
	else if(command_string == "adg")
	{
		command_order = 6;
	}
	else if(command_string == "edt")
	{
		command_order = 7;
	}
	else
	{
		command_order = -1;
	}
}

inline void executeCommand()
{
	switch(command_order)
	{
		case 1:
			addStudent();
			break;
		case 2:
			deleteStudent();
			break;
		case 3:
			sortAsTotalGrade();
			sortAsMatrikelNumber();
			printAll();
			break;
		case 4:
			sortAsTotalGrade();
			printAll();
			break;
		case 5:
			sortAsTotalGrade();
			sortAsSingleSubject();
			printAll();
			break;
		case 6:
			addGrade();
			break;
		/*
		case 7:
			editCertainStudent();
			break;
		*/
		case -1:
			doNothing();
			break;
		default: break;
	}
}

int main()
{
	while(MainCyclicFlag)
	{
		init();
		getCommand();
		executeCommand();
	}	
}

