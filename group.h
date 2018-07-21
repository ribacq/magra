/* Written by Quentin RIBAC
 * July 2018
 *
 * This is free software.
 * See LICENSE file for more info.
 */

#pragma once

#include <iostream>
#include <vector>

#include <QString>

#include "word.h"

// Group is the class for a group of words, that can also have subgroups.
class Group {
	// members
	QString name;
	QString description;
	int index;

	Group *parent = NULL;
	std::vector<Group *> *subgroups;

	std::vector<Word *> *words;

public:
	// constructor and desctructor
	Group(QString name, QString description, Group *parent);
	~Group();
	
	// getters
	QString getName()
		{ return this->name; }
	QString getDescription()
		{ return this->description; }
	Group *getParent()
		{ return this->parent; }
	std::vector<Group *> *getSubgroups()
		{ return this->subgroups; }
	std::vector<Word *> *getWords()
		{ return this->words; }
	Group *child(int i)
		{ return this->subgroups->at(i); }
	
	// setters
	void setName(QString name)
		{ this->name = name; }
	void setDescription(QString description)
		{ this->description = description; }
	
	// groups management
	void moveTo(Group *parent);

	// words management
	void addWord(QString text, QString meaning, QString description);
	void addWord(Word *word);
	void moveWordTo(int pos, Group *group);
	void removeWord(int pos);
	std::vector<Word *> *getAllWords();
	
	// tree-view related
	unsigned int row();
	int columnCount()
		{ return 2; }
	QString data(int column) const;
};
