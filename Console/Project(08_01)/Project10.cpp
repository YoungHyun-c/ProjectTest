#include <iostream>
#include <string>

// 구조체를 활용한 학생정보 출력하기.
class Student
{
public:
	std::string Name = "";
	int Number = 0;
	int Age = 0;
	float Grade = 0;

	static void Print(const Student* _Student)
	{
		if (nullptr != _Student)
		{
			std::cout << _Student->Number << "번 학생 정보 출력" << std::endl;
			std::cout << "이름 : " << _Student->Name << std::endl;
			std::cout << "나이 : " << _Student->Age << std::endl;
			std::cout << "학점 : " << _Student->Grade << std::endl;
			std::cout << "============================" << std::endl;
		}
	}

	static int Counting()
	{
		return ++Count;
	}

	static Student* CreateStudent(std::string& _Name, int& _Age, float& _Grade);

private:
	static int Count;
};
int Student::Count = 0;

class CGeneratorStudent
{
public:
	Student* CreateStudent(std::string& _Name, int _Age, float _Grade)
	{
		Student* pObject = new Student();
		pObject->Number = Student::Counting();
		pObject->Name = _Name;
		pObject->Age = _Age;
		pObject->Grade = _Grade;
		return pObject;
	}
};

Student* Student::CreateStudent(std::string& _Name, int& _Age, float& _Grade)
{
	Student* StuArr = new Student();
	StuArr->Name = _Name;
	StuArr->Number = Student::Counting();
	StuArr->Age = _Age;
	StuArr->Grade = _Grade;
	return StuArr;
}

void AddStudent(Student** _Student, std::string& _Name, int& _Age, float& _Grade)
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
	Student* ArrStudent[10] = { };
	std::cout << "학생 명수를 입력하세요 : ";
	int Count = 0;
	std::cin >> Count;
	for (int i = 0; i < Count; i++)
	{
		std::string Name = "";
		int Age;
		float Grade;
		std::cout << "이름을 입력해주세요 : ";
		std::cin >> Name;
		std::cout << "나이를 입력해주세요 : ";
		std::cin >> Age;
		std::cout << "학점을 입력해주세요 : ";
		std::cin >> Grade;
		//AddStudent(&ArrStudent[i], Name, Age, Grade);
		std::cout << std::endl;
		//ArrStudent[i] = ArrStudent[i]->CreateStudent(Name, Age, Grade);
		CGeneratorStudent Genarator;
		ArrStudent[i] = Genarator.CreateStudent(Name, Age, Grade);
	}

	for (int i = 0; i < Count; i++)
	{
		ArrStudent[i]->Print(ArrStudent[i]);
	}

	return 0;
}