// StringUtility.cpp
#include "StringUtility.h"

void PrintfCharacterString(CharacterString stringToPrint)
{
	int numCharacters = stringToPrint.numCharacters;
	
	char* printCharArray = new char[numCharacters];
	
	for (int i = 0; i < numCharacters; ++i) {
		printCharArray[i] = stringToPrint.characterArray[i];
	}

	printf("%s",printCharArray);
}

bool SearchCharacterStringFor(CharacterString desiredString, CharacterString searchedString)
{
	bool stringFound = false;

	return stringFound;
}

CharacterString ConvertIntegerToCharacterString(int integerForConversion)
{
	CharacterString returnString;
	
	char initString[] = "\0";

	returnString.numCharacters = 0;
	returnString.characterArray = initString;

	//returnString.Initialize(initString);

	return returnString;
}

int ConvertCharacterStringToInteger(CharacterString integerString)
{
	return -1;
}

CharacterString ConvertVector2ToCharacterString(int vector2ForConversion)
{
	CharacterString returnString;

	char initString[] = "\0";

	returnString.numCharacters = 0;
	returnString.characterArray = initString;

	return returnString;
}

// possible required formats for vector2String:
// "vector2(x,y)\0"
// "(x,y)\0"
// "x,y\0"
sf::Vector2f ConvertCharacterStringToVector2(CharacterString vector2String)
{
	sf::Vector2f returnVector(0, 0);

	return returnVector;
}