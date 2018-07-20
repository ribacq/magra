#include "group.h"

// Group is the constructor for the Group class.
Group::Group(std::string name, std::string description, Group *parent): name(name), description(description) {
	// no subgroups in the beginning
	this->subgroups = new std::vector<Group *>();

	// insert in the tree
	this->moveTo(parent);
}

/* groups management */

// Group::moveTo removes a group from its current parent and into the given group.
void Group::moveTo(Group *parent) {
	// do nothing if asked to move to NULL
	if (parent == NULL) {
		return;
	}

	// remove from current parent
	if (this->parent != NULL) {
		for (int i = 0; i < this->parent->subgroups->size(); ++i) {
			if (this->parent->subgroups->at(i) == this) {
				this->parent->subgroups->erase(this->parent->subgroups->begin()+i);
				break;
			}
		}
	}

	// link to new parent
	this->parent = parent;
	this->parent->subgroups->push_back(this);
}
