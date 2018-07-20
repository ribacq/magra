#include <string>
#include <vector>

class Group {
	// members
	std::string name;
	std::string description;

	Group *parent;
	std::vector<Group *> *subgroups;

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
	
	// setters
	void setName(std::string name)
		{ this->name = name; }
	void setDescription(std::string description)
		{ this->description = description; }
	
	// groups management
	void moveTo(Group *parent);
};
