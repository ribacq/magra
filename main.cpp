#include <iostream>
#include <vector>

#include "group.h"

using namespace std;

int main(int argc, char **argv) {
	cout << "MAGRA\n";

	// name and description
	cout << endl;
	Group *g = new Group("words", "Words of the Deẽreẽ conlang", NULL);

	cout << g->getName() << ": " << g->getDescription() << endl;

	g->setName("wordsDRE");
	g->setDescription("Words in Deẽreẽ");

	cout << g->getName() << ": " << g->getDescription() << endl;

	// subgroups
	cout << endl;
	Group *g2 = new Group("nouns", "Nouns in Deẽreẽ", g);

	std::vector<Group *> *gsubs = g->getSubgroups();
	for (int i = 0; i < gsubs->size(); ++i) {
		if (i > 0) {
			cout << "; ";
		}
		cout << gsubs->at(i)->getName();
	}
	cout << endl;

	return 0;
}
