#include "ConsoleGameObject.h"
#include "PackManScreen.h"

void ConsoleGameObject::Render()
{
	if (false == IsUpdate())
	{
		return;
	}

	// PackManScreen::GetMainScreen().SetScreenCharacter(Pos, RenderChar);
	PackManScreen::GetMainScreen().SetScreenCharacter(Pos, RenderChar);
}

void ConsoleGameObject::Update()
{

}