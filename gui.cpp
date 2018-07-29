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
	leftSide->addWidget(groupsTreeLabel);
	leftSide->addWidget(addGroupButton);
	groupEditForm->addRow("Name", groupEditName);
	groupEditForm->addRow("Description", groupEditDescription);
	groupButtonBar->addWidget(deleteGroupButton);
	groupButtonBar->addWidget(saveGroupButton);
	leftSide->addLayout(groupEditForm);
	leftSide->addLayout(groupButtonBar);
	leftSide->addWidget(groupsTree);
}

// setLeftSideActions defines the user interactions on the left side of the window
void GUI::setLeftSideActions() {
	// groups tree
	groupsTree->setModel(groupModel);
	groupsTree->setSelectionModel(new QItemSelectionModel(groupModel));
	connect(groupsTree->selectionModel(), SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(updateGroupEditForm(const QModelIndex &, const QModelIndex &)));
	groupsTree->setDragEnabled(true);
	groupsTree->setDragDropMode(QAbstractItemView::InternalMove);
	
	// buttons
	connect(addGroupButton, SIGNAL(released()), this, SLOT(addGroup()));
	connect(saveGroupButton, SIGNAL(released()), this, SLOT(saveGroupEditForm()));
	connect(deleteGroupButton, SIGNAL(released()), this, SLOT(deleteGroup()));
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

// updateGroupEditForm is a SLOT that updates the fields of the group edit form
void GUI::updateGroupEditForm(const QModelIndex &current, const QModelIndex &previous) {
	// do something with previous?
	
	// update form with current
	if (current.isValid()) {
		Group *group = static_cast<Group *>(current.internalPointer());
		groupEditName->setText(group->getName());
		groupEditDescription->setText(group->getDescription());
	}
}

// saveGroupEditForm is a SLOT that saves data from the form to the currently selected group
void GUI::saveGroupEditForm() {
	if (!groupsTree->selectionModel()->hasSelection()) {
		return;
	}

	QModelIndex index = groupsTree->selectionModel()->selectedIndexes().at(0);
	groupModel->setData(index, groupEditName->text(), groupEditDescription->text());
}

// deleteGroup is a SLOT deleting selected group upon confirmation
void GUI::deleteGroup() {
	if (!groupsTree->selectionModel()->hasSelection()) {
		return;
	}

	QModelIndex index = groupsTree->selectionModel()->selectedIndexes().at(0);
	Group *group = static_cast<Group *>(index.internalPointer());

	QString confirmTitle = QString("Confirm group deletion");
	QString confirmText = QString("Are you sure you want to delete group ‘");
	confirmText += group->getName();
	confirmText += "’?";
	QMessageBox::StandardButton reply = QMessageBox::question(NULL, confirmTitle, confirmText, QMessageBox::Cancel | QMessageBox::Yes);

	if (reply == QMessageBox::Yes) {
		groupModel->removeRow(index.row(), index.parent());
	}
}
