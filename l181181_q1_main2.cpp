#include "students.h"

void printarrays(student arr[] , int size )
{
	for (int i = 0 ; i < size; i++)
	{
		cout << "Student " << i + 1 <<": \n";
			arr[i].print();
	}

}
student* GPAarrays(student st[] ,int size , int &k)
{
	student *newarr;
	newarr = new student [size];
	for (int i = 0; i < size ; i++)
	{
		if (st[i].getGPA() > 2.0)
		{
			newarr[k] = st[i];
			st[i].copyquizzes(newarr[k]);           //deepcopyofquizzes
			k++;
		}
	}
	return newarr;
}
void copy(student a, student b)
{
	a.copyobjects(b);
}
student* Sortarray(student st[], int size)
{
	for (int j = 0; j < size - 1; j++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (st[i].getGPA() < st[i + 1].getGPA())
			{
				student temp;
				copy(temp, st[i]);
				copy(st[i], st[i + 1]);
				copy(st[i + 1], temp);
			}
		}
	}
	return st;
}
int main()
{
	student st[3] = {student(3,2.0),student(3,3.0),student(4,2.33)};

	st[0].addquizscore(1);                     //scoresupdate for 1st student
	st[0].addquizscore(4);
	st[0].addquizscore(10); 

	st[1].addquizscore(10);                    //scoresupdate for 2nd student
	st[1].addquizscore(4);
	st[1].addquizscore(9);

	st[2].addquizscore(9);                      //scoresupdate for 3rd student
	st[2].addquizscore(8);
	st[2].addquizscore(7); 
	printarrays(st ,3);

	student *newarray;
	int k = 0;
	newarray = GPAarrays(st, 3, k);                              //Getiing the array of students with GPA > 2 
	for (int i = 0 ; i < k ; i++)
	newarray[i].print();                                      //array of GPA > 2

	student *sortedarray;                                           //sorted array
	sortedarray = Sortarray(st, 3);
	printarrays(sortedarray, 3);

	delete sortedarray;
	delete newarray;
	sortedarray = nullptr;
	newarray = nullptr;

	/* copy constructor is invoked when the object is passed by value  or returned by a function*/
	/* Destructor is invoked at the end when the object goes out of scope*/


	return 0;
}

