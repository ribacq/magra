#include <iostream>
#include <vector>

#include "group.h"

using namespace std;

int main(int argc, char **argv) {
	cout << "MAGRA\n";

	// name and description
	cout << endl << "NAME AND DESCRIPTION" << endl;
	Group *g = new Group("words", "Words of the Deẽreẽ conlang", NULL);

	cout << g->getName() << ": " << g->getDescription() << endl;

	g->setName("wordsDRE");
	g->setDescription("Words in Deẽreẽ");

	cout << g->getName() << ": " << g->getDescription() << endl;

	// subgroups
	cout << endl << "SUBGROUPS" << endl;
	Group *g2 = new Group("nouns", "Nouns in Deẽreẽ", g);
	Group *g3 = new Group("verbs", "Verbs in Deẽreẽ", g);

	std::vector<Group *> *gsubs = g->getSubgroups();
	for (int i = 0; i < gsubs->size(); ++i) {
		if (i > 0) {
			cout << "; ";
		}
		cout << gsubs->at(i)->getName();
	}
	cout << endl;

	// words
	cout << endl << "WORDS" << endl;
	g2->addWord("eltol", "bird", "flying animal with feathers");
	g->addWord("ẽi", "person", "a human being");
	g3->addWord("fete", "drink", "to drink");

	//g->moveWordTo(0, g2);
	//g2->removeWord(0);

	std::vector<Word *> *gwords = g->getAllWords();
	for (int i = 0; i < gwords->size(); ++i) {
		if (i > 0) {
			cout << "; ";
		}
		cout << gwords->at(i)->getText();
	}
	cout << endl;
	return 0;
}
