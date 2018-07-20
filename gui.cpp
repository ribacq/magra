#include <QLabel>

#include "gui.h"

// GUI is the constructor for the main window.
GUI::GUI() {
	setWindowTitle("Magra");

	menuBar->addAction("File");
	menuBar->addAction("About");
	
	currentGroupLabel->setText("[group name]");
	leftVBox->addWidget(currentGroupLabel);
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
