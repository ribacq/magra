/* Written by Quentin RIBAC
 * July 2018
 *
 * This is free software.
 * See LICENSE file for more info.
 */

#include <iostream>

#include "groupModel.h"

// GroupModel: constructor
GroupModel::GroupModel(Group *data, QObject *parent) : QAbstractItemModel(parent) {
	QList<QVariant> rootData;
	rootData << "Name" << "Description";
	rootGroup = new Group("Name", "Description", NULL, -1);
	if (data != NULL) {
		data->moveTo(rootGroup, -1);
	} else {
		new Group("words", "Words", rootGroup, -1);
	}
}

// ~GroupModel: destructor
GroupModel::~GroupModel() {
	delete rootGroup;
}

// index returns an index that the view understands
QModelIndex GroupModel::index(int row, int column, const QModelIndex &parent) const {
	if (!hasIndex(row, column, parent)) {
		return QModelIndex();
	}

	Group *parentGroup;
	if (!parent.isValid()) {
		parentGroup = rootGroup;
	} else {
		parentGroup = static_cast<Group *>(parent.internalPointer());
	}

	Group *childGroup = parentGroup->child(row);
	if (childGroup) {
		return createIndex(row, column, childGroup);
	} else {
		return QModelIndex();
	}
}

// parent returns the index to the parent for a given index
QModelIndex GroupModel::parent(const QModelIndex &index) const {
	if (!index.isValid()) {
		return QModelIndex();
	}

	Group *childGroup = static_cast<Group *>(index.internalPointer());
	Group *parentGroup = childGroup->getParent();

	if (parentGroup == rootGroup) {
		return QModelIndex();
	}

	return createIndex(parentGroup->row(), 0, parentGroup);
}

// rowCount returns the number of children of an item at a given index
int GroupModel::rowCount(const QModelIndex &parent) const {
	if (parent.column() > 0) {
		return 0;
	}

	Group *parentGroup;
	if (!parent.isValid()) {
		parentGroup = rootGroup;
	} else {
		parentGroup = static_cast<Group *>(parent.internalPointer());
	}

	return parentGroup->getSubgroups()->size();
}

// columnCount returns the number of columns of a given index
int GroupModel::columnCount(const QModelIndex &parent) const {
	if (parent.isValid()) {
		return static_cast<Group *>(parent.internalPointer())->columnCount();
	} else {
		return rootGroup->columnCount();
	}
}

// data gives data from the model to the view
QVariant GroupModel::data(const QModelIndex &index, int role) const {
	if (!index.isValid()) {
		return QVariant();
	}

	if (role != Qt::DisplayRole) {
		return QVariant();
	}

	Group *group = static_cast<Group *>(index.internalPointer());

	return QVariant(group->data(index.column()));
}

// flags indicate that this is read-only
Qt::ItemFlags GroupModel::flags(const QModelIndex &index) const {
	if (!index.isValid()) {
		return 0;
	}

	return QAbstractItemModel::flags(index);
}

// headerData uses the rootGroup
QVariant GroupModel::headerData(int section, Qt::Orientation orientation, int role) const {
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
		return QVariant(rootGroup->data(section));
	}

	return QVariant();
}

// insertRows creates and adds news groups to the tree
bool GroupModel::insertRows(int row, int count, const QModelIndex &parent) {
	beginInsertRows(parent, row, row+count-1);
	Group *parentGroup;
	if (parent.isValid()) {
		parentGroup = static_cast<Group *>(parent.internalPointer());
	} else {
		parentGroup = rootGroup;
	}
	for (int i = 0; i < count; ++i) {
		new Group("new group", "A new group", parentGroup, row+i);
	}
	endInsertRows();

	//rootGroup->printTree(0);

	return true;
}
