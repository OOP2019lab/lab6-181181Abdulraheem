#include "students.h"


int main()
{

	student s1;
	s1.addquizscore(10);
	s1.addquizscore(3);
	s1.addquizscore(7);
	s1.addquizscore(1);
	s1.print();
	student s2(4,2);
	s2.addquizscore(9);
	s2.addquizscore(4);
	s2.addquizscore(6);
	s2.print();
	student s3(s1);
	s3.updateScore(1,3);
	s3.updateScore(10,3);
	cout << s1.compare(s2) << endl;
	s3.setGPA(3);
	s3.print();
	s1.print();
	

/*
copy constructor ?
Firstly s3(s1);
Secondly when cout << s1.compare(s2) there new copy of s2 is created in the scope of compare

 destructor ?
outside the scope of main, s1, s2, s3 were destroyed*/

	return 0;
}

