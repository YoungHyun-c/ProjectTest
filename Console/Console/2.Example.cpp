// armor클래스 -> 맵에 담고 싶다.

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

// Scene클래스 만듬.
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
	// 씬을 추가하는 함수
	void AddScene(const std::string& _Name, Scene* _Scene)
	{
		SceneList[_Name] = _Scene;
		// 씬의 이름을 키로 하고, 포인터를 값으로 저장한다.
	}

	// 씬을 삭제하는 함수.
	void RemoveScene(const std::string& _Name)
	{
		// 씬 이름으로 map에서 찾아야함.
		// 씬이 있으면, 지워라.
		if (CurSceneName == _Name)
		{
			CurSceneName = "";
		}
		auto iter = SceneList.find(_Name);
		// 씬이 있으면
		if (iter != SceneList.end())
		{
			delete iter->second;
			iter->second = nullptr;
			SceneList.erase(iter);
		}
	}

	// 현재 씬을 설정하는 함수.
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
			std::cout << "없음" << std::endl;
		}
	}
	
	// 현재 씬을 출력 (보여주는) 함수.
	void PrintCurScene() const
	{
		if (CurSceneName.empty())
		{
			std::cout << "현재 씬이 비어있습니다. 설정해주세요" << std::endl;
			return;
		}
		
		std::cout << "현재 씬 : " << CurSceneName << std::endl;
		std::cout << "정보 : " << CurScene->GetDesc() << std::endl;
	}

private:
	// 씬의 이름을 키 값으로, 씬에 대한 포인터를 값으로 저장.
	std::map<std::string, Scene*> SceneList;
	// 현재 씬을 가리키는 포인터
	Scene* CurScene;
	// 현재 씬의 이름
	std::string CurSceneName;
};


int main()
{
	std::map<std::string, Armor> armor;

	armor.insert(std::make_pair("Shield", Armor("방패", 10)));
	armor.insert(std::make_pair("SmallShiled", Armor("작은방패", 10)));
	armor.insert(std::make_pair("Greave", Armor("신발", 10)));

	for (std::pair<const std::string, Armor>& pPair : armor)
	{
		std::cout << "Pair 키 : " << pPair.first << std::endl;
	}

	for (std::map<std::string, Armor>::iterator	i = armor.begin(); i != armor.end(); i++)
	{
		std::cout << "Iterator 키 :" << i->first << std::endl;
	}
	
	for (auto& Pair : armor)
	{
		std::cout << "키 : " << Pair.first << std::endl;
		std::cout << "이름 : " << Pair.second.GetName() << std::endl;
		std::cout << "방어 : " << Pair.second.getDef() << std::endl;
	}


	SceneManager SM;
	SM.AddScene("Menu", new Scene("메뉴씬이다."));
	SM.AddScene("Battle", new Scene("배틀씬이다."));
	
	SM.SetCurScene("Menu");
	SM.PrintCurScene();

	SM.SetCurScene("Battle");
	SM.PrintCurScene();

	SM.RemoveScene("Battle");
	SM.PrintCurScene();

	return 0;
}


/*
맵의 검색속도가 굉장히 빠르다.
-> 이진 트리로 되어있기 때문에.
*/