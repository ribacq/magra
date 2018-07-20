#include "group.h"
#include <iostream>

// Group::Group is the constructor for the Group class.
Group::Group(std::string name, std::string description, Group *parent): name(name), description(description) {
	// no subgroups or words in the beginning
	this->subgroups = new std::vector<Group *>();
	this->words = new std::vector<Word *>();

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
		for (unsigned int i = 0; i < this->parent->subgroups->size(); ++i) {
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

/* words management */

// Group::addWord adds a word to the group.
void Group::addWord(std::string text, std::string meaning, std::string description) {
	this->words->push_back(new Word(text, meaning, description));
}

void Group::addWord(Word *word) {
	this->words->push_back(word);
}

// Group::moveWordTo moves the word at position pos from this group to another one. Move to NULL will effectively delete the word from memory.
void Group::moveWordTo(int pos, Group *group) {
	if (group != NULL) {
		group->addWord(this->words->at(pos));
	} else {
		delete this->words->at(pos);
	}
	this->words->erase(this->words->begin()+pos);
}

// Group::removeWord removes the word at position pos from this group.
void Group::removeWord(int pos) {
	this->moveWordTo(pos, NULL);
}

// Group::getAllWords returns a vector of all words including subgroups.
std::vector<Word *> *Group::getAllWords() {
	std::vector<Word *> *words = new std::vector<Word *>(*this->words);
	if (this->subgroups->size() > 0) {
		for (unsigned int i = 0; i < this->subgroups->size(); ++i) {
			std::vector<Word *> *subwords = this->subgroups->at(i)->getAllWords();
			words->insert(words->end(), subwords->begin(), subwords->end());
		}
	}
	return words;
}

/* tree-view related */

// row returns the index of the group in the parent group
int Group::row() {
	if (parent != NULL) {
		for (int row = 0; row < parent->subgroups->size(); ++row) {
			if (parent->subgroups->at(row) == this) {
				return row;
			}
		}
	}
	return 0;
}
