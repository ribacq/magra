/* Written by Quentin RIBAC
 * July 2018
 *
 * This is free software.
 * See LICENSE file for more info.
 */

#include "gui.h"

// GUI is the constructor for the main window.
GUI::GUI(Group *group) {
	setWindowTitle("Magra");

	menuBar->addAction("File");
	menuBar->addAction("About");
	
	groupsTreeLabel->setText("Groups");
	groupsTree->setModel(new GroupModel(group, 0));
	leftVBox->addWidget(groupsTreeLabel);
	leftVBox->addWidget(groupsTree);
	
	rightTabs->addTab(new QLabel("Daniel"), "Words");
	rightTabs->addTab(new QLabel("Ernest"), "Derivations");
	rightTabs->addTab(new QLabel("Francis"), "Phrases");

	layout->addWidget(menuBar);
	layout->addLayout(mainLayout);
	mainLayout->addLayout(leftVBox);
	mainLayout->addWidget(rightTabs);
	mainLayout->setStretchFactor(leftVBox, 1);
	mainLayout->setStretchFactor(rightTabs, 2);

	setLayout(layout);
}
