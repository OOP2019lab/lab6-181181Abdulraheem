#include <iostream>
using namespace std;


class student
{
	static int counter;
	int id;
	float *quizscores;
	int quizcapacity;
	int quiztaken;
	float GPA;
public:
	student();
	student(int,float);
	student(const student &);
	~student();
	void addquizscore(float );
	void setGPA(float );
	float getGPA() const;
	void print() const;
	bool compare(student);
	void updateScore(int , float);
	int getQuizzestaken() const;
	void copyquizzes(student stu);
	void copyobjects(student &s1);

};


