/* Written by Quentin RIBAC
 * July 2018
 *
 * This is free software.
 * See LICENSE file for more info.
 */

#pragma once

#include <iostream>

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QTabWidget>
#include <QMenuBar>
#include <QTreeView>
#include <QTreeWidgetItem>
#include <QModelIndex>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>

#include "groupModel.h"
#include "group.h"

// GUI is the root class for all graphical interface.
class GUI : public QWidget {
	Q_OBJECT

	// data
	GroupModel *groupModel = NULL;

	// layout
	QVBoxLayout *layout = new QVBoxLayout();
	QHBoxLayout *mainLayout = new QHBoxLayout();

	// menu bar
	QMenuBar *menuBar = new QMenuBar();

	// left side
	QVBoxLayout *leftSide = new QVBoxLayout();
	QTreeView *groupsTree = new QTreeView();
	QLabel *groupsTreeLabel = new QLabel("Groups");
	QFormLayout *groupEditForm = new QFormLayout();
	QLineEdit *groupEditName = new QLineEdit();
	QLineEdit *groupEditDescription = new QLineEdit();
	QPushButton *saveGroupButton = new QPushButton("Save");
	QHBoxLayout *groupButtonBar = new QHBoxLayout();
	QPushButton *addGroupButton = new QPushButton("Add group");
	QPushButton *deleteGroupButton = new QPushButton("Delete");
	void setLeftSideLayout();
	void setLeftSideActions();

	// right side
	QTabWidget *rightSide = new QTabWidget();

public:
	// constructor
	GUI();

protected slots:
	void addGroup();
	void updateGroupEditForm(const QModelIndex &current, const QModelIndex &previous);
	void saveGroupEditForm();
	void deleteGroup();
};
