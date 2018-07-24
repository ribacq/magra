/* Written by Quentin RIBAC
 * July 2018
 *
 * This is free software.
 * See LICENSE file for more info.
 */

#include "gui.h"

// GUI is the constructor for the main window.
GUI::GUI() {
	// data
	groupModel = new GroupModel(NULL, 0);

	// window settings
	setWindowTitle("Magra");

	// menu bar
	menuBar->addAction("File");
	menuBar->addAction("About");
	
	// left side
	setLeftSideLayout();
	setLeftSideActions();
	
	// right side
	rightSide->addTab(new QLabel("Daniel"), "Words");
	rightSide->addTab(new QLabel("Ernest"), "Derivations");
	rightSide->addTab(new QLabel("Francis"), "Phrases");

	// layout
	layout->addWidget(menuBar);
	layout->addLayout(mainLayout);
	mainLayout->addLayout(leftSide);
	mainLayout->addWidget(rightSide);
	mainLayout->setStretchFactor(leftSide, 1);
	mainLayout->setStretchFactor(rightSide, 2);
	setLayout(layout);
}

// setLeftSideLayout defines positions of the left-side elements of the window
void GUI::setLeftSideLayout() {
	groupsTreeLabel->setText("Groups");
	groupsTree->setModel(groupModel);
	groupsTree->setSelectionModel(new QItemSelectionModel(groupModel));
	groupsButtonBar->addWidget(addGroupButton);
	leftSide->addWidget(groupsTreeLabel);
	leftSide->addLayout(groupsButtonBar);
	leftSide->addWidget(groupsTree);
}

// setLeftSideActions defines the user interactions on the left side of the window
void GUI::setLeftSideActions() {
	connect(addGroupButton, SIGNAL(released()), this, SLOT(addGroup()));
}

// addGroup is a SLOT for adding a new group
void GUI::addGroup() {
	if (groupsTree->selectionModel()->hasSelection()) {
		QModelIndex index = groupsTree->selectionModel()->selectedIndexes().at(0);
		groupModel->insertRows(groupModel->rowCount(index), 1, index);
		if (!groupsTree->isExpanded(index)) {
			groupsTree->expand(index);
		}
		groupsTree->selectionModel()->clearSelection();
	} else {
		groupModel->insertRows(groupModel->rowCount(QModelIndex()), 1, QModelIndex());
	}
}
