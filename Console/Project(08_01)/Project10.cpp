#include <iostream>
#include <string>


// 구조체를 활용한 학생정보 출력하기.
struct Student
{
public:
	std::string Name = "";
	int Number;
	int Age;
	float Grade;
	
	void Print(Student _Student)
	{
		std::cout << Number << "번 학생 정보 출력" << std::endl;
		std::cout << "이름 : " << Name << std::endl;
		std::cout << "나이 : " << Age << std::endl;
		std::cout << "학점 : " << Grade << std::endl;
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
	AddStudent(&FirstStudent, "라라", 21, 3.5f);
	FirstStudent->Print(*FirstStudent);

	Student* SecondStudent = nullptr;
	AddStudent(&SecondStudent, "루루", 22, 3.9f);
	SecondStudent->Print(*SecondStudent);

	return 0;
}