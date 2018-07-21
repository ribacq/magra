#include <QString>

// Word is the class that represent a word in the language.
class Word {
	// members
	QString text;
	QString meaning;
	QString description;

public:
	// constructor
	Word(QString text, QString meaning, QString description);

	// getters
	QString getText()
		{ return this->text; }
	QString getMeaning()
		{ return this->meaning; }
	QString getDescription()
		{ return this->description; }
	
	// setters
	void setText(QString text)
		{ this->text = text; }
	void setMeaning(QString meaning)
		{ this->meaning = meaning; }
	void setDescription(QString description)
		{ this->description = description; }
};
