#pragma once

// Ό³Έν :
template <typename DataType>
class GameEngineArray
{
public:
	// delete Function
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;
	GameEngineArray& operator = (GameEngineArray&& _Other) noexcept = delete;

	GameEngineArray() {}

	GameEngineArray(size_t _Value)
	{
		if (0 >= _Value)
		{
			return;
		}

		Resize(_Value);
	}

	void Resize(size_t _Value)
	{
		DataType* NewPtr = new DataType[_Value];
		size_t CopySize = _Value < ArrCount ? _Value : ArrCount;

		for (size_t i = 0; i < CopySize; i++)
		{
			NewPtr[i] = ArrPtr[i];
		}

		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		ArrPtr = NewPtr;
		ArrCount = _Value;
	}

protected:

private:
	size_t ArrCount = 0;
	DataType* ArrPtr = nullptr;

};

