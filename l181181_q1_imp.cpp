#include "students.h"
int student::counter = 0;

student::student()
{
	id = ++counter;
	quiztaken = 0;
	quizcapacity = 3;
	GPA = -1;
	quizscores  = new float [quizcapacity];
}
student::student(int a , float b)
{
	id = ++counter;
	quizcapacity = a;
	quiztaken  =0 ;
	GPA = b;
	quizscores  = new float [quizcapacity];
}
student::student (const student &ss)
{
	id = ss.id;
	quiztaken = ss.quiztaken;
	quizcapacity = ss.quizcapacity;
	GPA = ss.GPA;
	if (ss.quizscores != nullptr)
	{
		quizscores = new float[quizcapacity];
		for (int i = 0 ; i < quiztaken ;i++)
	     quizscores[i] = ss.quizscores[i];
	}
}
student::~student()
{
	if (quizscores != nullptr)
		delete [] quizscores;
	quizscores = nullptr;
}
void student::addquizscore(float score)
{
	if (quiztaken < quizcapacity)
	{
		quizscores[quiztaken] = score;
		quiztaken++;
	}
	else 
		cout << "Sorry no space available\n";

}
void student::setGPA(float gpa)
{
	GPA = gpa;
}
float student::getGPA() const
{
	return GPA;
}
int student::getQuizzestaken() const
{
	return quiztaken;
}
void student::print()  const
{
	cout << "ID : " << id<<endl;
	cout << "GPA : " << GPA<<endl;
	cout << "No. of Quizzes taken : " << quiztaken;
	cout << endl;
	if (quiztaken > 0)
	{
		for (int i = 0 ; i < quiztaken ;i++)
			cout << "Quiz no. "<< i + 1 << " : " << quizscores[i]<< endl;
	}

	cout << "\n\n";
}
bool student::compare(student Z)
{
	if (Z.GPA < GPA)
		return false;
	else 
		return true;
}
void student::updateScore(int a , float b)
{
	if (a <= quiztaken)
	{
		quizscores[a - 1] = b;
	}
	else 
		cout << "Quiz not taken\n";

}

void student::copyquizzes(student stu)
{
	stu.quizscores = new float[quiztaken];
	for (int i = 0; i < stu.quiztaken; i++)
	{
		stu.quizscores[i] = quizscores[i];
	}
}


void student::copyobjects(student &s1)
{
	id = s1.id;
	quiztaken = s1.quiztaken;
	quizcapacity = s1.quizcapacity;
	GPA = s1.GPA;
	quizscores = new float[quizcapacity];
	for (int i = 0; i < quiztaken; i++)
		quizscores[i] = s1.quizscores[i];
}





	