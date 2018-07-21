/* Written by Quentin RIBAC
 * July 2018
 *
 * This is free software.
 * See LICENSE file for more info.
 */

#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QMenuBar>
#include <QTreeView>
#include <QTreeWidgetItem>
#include <QLabel>

#include "groupModel.h"
#include "group.h"

// GUI is the root class for all graphical interface.
class GUI : public QWidget {
	// members
	QVBoxLayout *layout = new QVBoxLayout();
	QHBoxLayout *mainLayout = new QHBoxLayout();
	QVBoxLayout *leftVBox = new QVBoxLayout();
	QTabWidget *rightTabs = new QTabWidget();
	QMenuBar *menuBar = new QMenuBar();
	QTreeView *groupsTree = new QTreeView();
	QLabel *groupsTreeLabel = new QLabel();

public:
	// constructor
	GUI(Group *group);
};
