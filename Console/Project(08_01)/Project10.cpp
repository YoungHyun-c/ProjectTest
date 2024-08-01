#include <iostream>
#include <string>


// ����ü�� Ȱ���� �л����� ����ϱ�.
struct Student
{
public:
	std::string Name = "";
	int Number;
	int Age;
	float Grade;
	
	void Print(Student _Student)
	{
		std::cout << Number << "�� �л� ���� ���" << std::endl;
		std::cout << "�̸� : " << Name << std::endl;
		std::cout << "���� : " << Age << std::endl;
		std::cout << "���� : " << Grade << std::endl;
		std::cout << "============================" << std::endl;
	}
	
	static int Counting()
	{
		return ++Count;
	}

private:
	static int Count;
};
int Student::Count = 0;


void AddStudent(Student** _Student, std::string _Name, int _Age, float _Grade)
{
	Student* Temp = new Student();
	Temp->Name = _Name;
	Temp->Number = Student::Counting();
	Temp->Age = _Age;
	Temp->Grade = _Grade;

	*_Student = Temp;
}

int main()
{
	Student* FirstStudent = nullptr;
	AddStudent(&FirstStudent, "���", 21, 3.5f);
	FirstStudent->Print(*FirstStudent);

	Student* SecondStudent = nullptr;
	AddStudent(&SecondStudent, "���", 22, 3.9f);
	SecondStudent->Print(*SecondStudent);

	return 0;
}