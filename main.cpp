/* Written by Quentin RIBAC
 * July 2018
 *
 * This is free software.
 * See LICENSE file for more info.
 */

#include <vector>

#include <QApplication>
#include <QTextStream>

#include "group.h"
#include "gui.h"

using namespace std;

int main(int argc, char **argv) {
	QTextStream out(stdout);
	out << "MAGRA\n";

	// name and description
	out << endl << "NAME AND DESCRIPTION" << endl;
	Group *g = new Group("words", "Words of the Deẽreẽ conlang", NULL);

	out << g->getName() << ": " << g->getDescription() << endl;

	g->setName("wordsDRE");
	g->setDescription("Words in Deẽreẽ");

	out << g->getName() << ": " << g->getDescription() << endl;

	// subgroups
	out << endl << "SUBGROUPS" << endl;
	Group *g2 = new Group("nouns", "Nouns in Deẽreẽ", g);
	Group *g3 = new Group("verbs", "Verbs in Deẽreẽ", g2);
	Group *nounsH = new Group("Human nouns", "Human noun class", g3);
	Group *nounsM = new Group("Magic nouns", "Magic noun class", g2);
	Group *nounsC = new Group("Common nouns", "Common noun class", g2);
	new Group("postpositions", "Postpositions", g);
	g3->moveTo(g);

	std::vector<Group *> *gsubs = g->getSubgroups();
	for (unsigned int i = 0; i < gsubs->size(); ++i) {
		if (i > 0) {
			out << "; ";
		}
		out << gsubs->at(i)->getName() << " (" << gsubs->at(i)->row() << ")";
	}
	out << endl;

	// words
	out << endl << "WORDS" << endl;
	g2->addWord("eltol", "bird", "flying animal with feathers");
	g->addWord("ẽi", "person", "a human being");
	g3->addWord("fete", "drink", "to drink");

	//g->moveWordTo(0, g2);
	//g2->removeWord(0);

	std::vector<Word *> *gwords = g->getAllWords();
	for (unsigned int i = 0; i < gwords->size(); ++i) {
		if (i > 0) {
			out << "; ";
		}
		out << gwords->at(i)->getText();
	}
	out << endl;

	// gui
	QApplication app(argc, argv);
	GUI *gui = new GUI(g);
	gui->show();
	nounsH->moveTo(g2);

	return app.exec();
}
