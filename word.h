#include <string>

// Word is the class that represent a word in the language.
class Word {
	// members
	std::string text;
	std::string meaning;
	std::string description;

public:
	// constructor
	Word(std::string text, std::string meaning, std::string description);

	// getters
	std::string getText()
		{ return this->text; }
	std::string getMeaning()
		{ return this->meaning; }
	std::string getDescription()
		{ return this->description; }
	
	// setters
	void setText(std::string text)
		{ this->text = text; }
	void setMeaning(std::string meaning)
		{ this->meaning = meaning; }
	void setDescription(std::string description)
		{ this->description = description; }
};
