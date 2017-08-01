// StringUtility.h
#pragma once
#include <SFML/System.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

struct CharacterString {
	int numCharacters;
	char* characterArray;
	
	CharacterString() {}
	
	void Initialize(char* initString) {
		int numCharacters = 0;
		char nextChar = initString[0];

		if (initString != NULL) {
			// test out strings with fewer than 10 characters
			while (nextChar != '\0' && numCharacters < 10) {
				nextChar = initString[numCharacters];
				numCharacters++;
			}
		}		
		
		characterArray = (char*)malloc(numCharacters);

		for (int i = 0; i < numCharacters; ++i) {
			characterArray[i] = initString[i];
		}
	}

	~CharacterString() {
		// may not need to free memory in destructor (i.e. may automatically free in destructor)
		free(characterArray);		
	}
	
};

void PrintfCharacterString(CharacterString stringToPrint);
bool SearchCharacterStringFor(CharacterString desiredString, CharacterString searchedString);
CharacterString ConvertIntegerToCharacterString(int integerForConversion);
int ConvertCharacterStringToInteger(CharacterString integerString);
CharacterString ConvertVector2ToCharacterString(int vector2ForConversion);
sf::Vector2f ConvertCharacterStringToVector2(CharacterString vector2String);