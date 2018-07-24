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
	// log
	QTextStream out(stdout);
	out << "MAGRA\n";

	// gui
	QApplication app(argc, argv);
	GUI *gui = new GUI();
	gui->show();

	return app.exec();
}
