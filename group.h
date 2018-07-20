#include <string>
#include <vector>

#include "word.h"

// Group is the class for a group of words, that can also have subgroups.
class Group {
	// members
	std::string name;
	std::string description;
	int index;

	Group *parent;
	std::vector<Group *> *subgroups;

	std::vector<Word *> *words;

public:
	// constructor
	Group(std::string name, std::string description, Group *parent);
	
	// getters
	std::string getName()
		{ return this->name; }
	std::string getDescription()
		{ return this->description; }
	Group *getParent()
		{ return this->parent; }
	std::vector<Group *> *getSubgroups()
		{ return this->subgroups; }
	std::vector<Word *> *getWords()
		{ return this->words; }
	
	// setters
	void setName(std::string name)
		{ this->name = name; }
	void setDescription(std::string description)
		{ this->description = description; }
	
	// groups management
	void moveTo(Group *parent);

	// words management
	void addWord(std::string text, std::string meaning, std::string description);
	void addWord(Word *word);
	void moveWordTo(int pos, Group *group);
	void removeWord(int pos);
	std::vector<Word *> *getAllWords();
	
	// tree-view related
	int row();
};
