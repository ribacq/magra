/* Written by Quentin RIBAC
 * July 2018
 *
 * This is free software.
 * See LICENSE file for more info.
 */

#include "group.h"

// Group::Group is the constructor for the Group class.
Group::Group(QString name, QString description, Group *parent, int row): name(name), description(description) {
	// no subgroups or words in the beginning
	this->subgroups = new std::vector<Group *>();
	this->words = new std::vector<Word *>();

	// insert in the tree
	this->moveTo(parent, row);
}

// Group::~Group is the destructor.
Group::~Group() {
	// remove from parent
	moveTo(NULL, -1);

	// delete subgroups
	for (unsigned int i = 0; i < subgroups->size(); i++) {
		Group *group = subgroups->at(i);
		subgroups->erase(subgroups->begin()+i);
		delete group;
	}

	// delete words
	for (unsigned int i = 0; i < words->size(); i++) {
		Word *word = words->at(i);
		words->erase(words->begin()+i);
		delete word;
	}
}

/* groups management */

// Group::moveTo removes a group from its current parent and into the given group.
void Group::moveTo(Group *parent, int row) {
	// remove from current parent
	if (this->parent != NULL) {
		for (unsigned int i = 0; i < this->parent->subgroups->size(); ++i) {
			if (this->parent->subgroups->at(i) == this) {
				this->parent->subgroups->erase(this->parent->subgroups->begin()+i);
				break;
			}
		}
	}

	if (parent != NULL) {
		// link to new parent
		this->parent = parent;
		if (row < 0) {
			this->parent->subgroups->push_back(this);
		} else {
			this->parent->subgroups->insert(this->parent->subgroups->begin() + row, this);
		}
	}
}

/* words management */

// Group::addWord adds a word to the group.
void Group::addWord(QString text, QString meaning, QString description) {
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
unsigned int Group::row() {
	if (parent != NULL) {
		for (unsigned int i = 0; i < parent->subgroups->size(); ++i) {
			if (parent->subgroups->at(i) == this) {
				return i;
			}
		}
	}
	return 0;
}

QString Group::data(int column) const {
	switch (column) {
	case 0:
		return name;
		break;
	case 1:
		return description;
		break;
	default:
		return name;
		break;
	}
}

/* misc */

// prints the groups tree to STDOUT
void Group::printTree(unsigned int indent) const {
	QTextStream out(stdout);

	if (indent == 0) {
		out << "\n-----\n";
	}

	for (unsigned int i = 0; i < indent; ++i) {
		out << "  ";
	}
	out << name << "\n";
	for (unsigned int i = 0; i < subgroups->size(); ++i) {
		subgroups->at(i)->printTree(indent + 1);
	}
}
