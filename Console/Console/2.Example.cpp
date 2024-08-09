// armorŬ���� -> �ʿ� ��� �ʹ�.

#include <iostream>
#include <map>

class Armor
{
public:
	Armor() : Name(""), Def(0) {}

	Armor(const std::string& _Name, int _Def) : Name(_Name) , Def(_Def){}


public:
	std::string GetName() const
	{
		return Name;
	}

	int getDef() const
	{
		return Def;
	}


private:
	std::string Name;
	int Def;
};

// SceneŬ���� ����.
class Scene
{
public:
	Scene() : Desc("") {}
	Scene(const std::string& _Desc) : Desc(_Desc) {}

	std::string GetDesc() const
	{
		return Desc;
	}

private:
	std::string Desc;
};

class SceneManager
{
public:
	SceneManager() : CurScene(nullptr), CurSceneName("") {}
	~SceneManager()
	{
		for (auto& i : SceneList)
		{
			delete i.second;
			i.second = nullptr;
		}
	}
	// ���� �߰��ϴ� �Լ�
	void AddScene(const std::string& _Name, Scene* _Scene)
	{
		SceneList[_Name] = _Scene;
		// ���� �̸��� Ű�� �ϰ�, �����͸� ������ �����Ѵ�.
	}

	// ���� �����ϴ� �Լ�.
	void RemoveScene(const std::string& _Name)
	{
		// �� �̸����� map���� ã�ƾ���.
		// ���� ������, ������.
		if (CurSceneName == _Name)
		{
			CurSceneName = "";
		}
		auto iter = SceneList.find(_Name);
		// ���� ������
		if (iter != SceneList.end())
		{
			delete iter->second;
			iter->second = nullptr;
			SceneList.erase(iter);
		}
	}

	// ���� ���� �����ϴ� �Լ�.
	void SetCurScene(const std::string& _Name)
	{
		auto Iter = SceneList.find(_Name);
		if (Iter != SceneList.end())
		{
			CurScene = Iter->second;
			CurSceneName = _Name;
		}
		else
		{
			std::cout << "����" << std::endl;
		}
	}
	
	// ���� ���� ��� (�����ִ�) �Լ�.
	void PrintCurScene() const
	{
		if (CurSceneName.empty())
		{
			std::cout << "���� ���� ����ֽ��ϴ�. �������ּ���" << std::endl;
			return;
		}
		
		std::cout << "���� �� : " << CurSceneName << std::endl;
		std::cout << "���� : " << CurScene->GetDesc() << std::endl;
	}

private:
	// ���� �̸��� Ű ������, ���� ���� �����͸� ������ ����.
	std::map<std::string, Scene*> SceneList;
	// ���� ���� ����Ű�� ������
	Scene* CurScene;
	// ���� ���� �̸�
	std::string CurSceneName;
};


int main()
{
	std::map<std::string, Armor> armor;

	armor.insert(std::make_pair("Shield", Armor("����", 10)));
	armor.insert(std::make_pair("SmallShiled", Armor("��������", 10)));
	armor.insert(std::make_pair("Greave", Armor("�Ź�", 10)));

	for (std::pair<const std::string, Armor>& pPair : armor)
	{
		std::cout << "Pair Ű : " << pPair.first << std::endl;
	}

	for (std::map<std::string, Armor>::iterator	i = armor.begin(); i != armor.end(); i++)
	{
		std::cout << "Iterator Ű :" << i->first << std::endl;
	}
	
	for (auto& Pair : armor)
	{
		std::cout << "Ű : " << Pair.first << std::endl;
		std::cout << "�̸� : " << Pair.second.GetName() << std::endl;
		std::cout << "��� : " << Pair.second.getDef() << std::endl;
	}


	SceneManager SM;
	SM.AddScene("Menu", new Scene("�޴����̴�."));
	SM.AddScene("Battle", new Scene("��Ʋ���̴�."));
	
	SM.SetCurScene("Menu");
	SM.PrintCurScene();

	SM.SetCurScene("Battle");
	SM.PrintCurScene();

	SM.RemoveScene("Battle");
	SM.PrintCurScene();

	return 0;
}


/*
���� �˻��ӵ��� ������ ������.
-> ���� Ʈ���� �Ǿ��ֱ� ������.
*/