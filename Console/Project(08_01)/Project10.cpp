#include <iostream>
#include <string>

// ����ü�� Ȱ���� �л����� ����ϱ�.
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
			std::cout << _Student->Number << "�� �л� ���� ���" << std::endl;
			std::cout << "�̸� : " << _Student->Name << std::endl;
			std::cout << "���� : " << _Student->Age << std::endl;
			std::cout << "���� : " << _Student->Grade << std::endl;
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
	std::cout << "�л� ����� �Է��ϼ��� : ";
	int Count = 0;
	std::cin >> Count;
	for (int i = 0; i < Count; i++)
	{
		std::string Name = "";
		int Age;
		float Grade;
		std::cout << "�̸��� �Է����ּ��� : ";
		std::cin >> Name;
		std::cout << "���̸� �Է����ּ��� : ";
		std::cin >> Age;
		std::cout << "������ �Է����ּ��� : ";
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