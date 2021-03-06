/* Written by Quentin RIBAC
 * July 2018
 *
 * This is free software.
 * See LICENSE file for more info.
 */

// this was written with the tutorial at
// https://doc.qt.io/qt-5/qtwidgets-itemviews-simpletreemodel-example.html

#pragma once

#include <QAbstractItemModel>
#include <QVariant>
#include <QModelIndex>
#include <QVariant>
#include <Qt>

#include "group.h"

class GroupModel : public QAbstractItemModel {
	Q_OBJECT

	// data
	Group *rootGroup;

public:
	// constructor and destructor
	GroupModel(Group *data, QObject *parent);
	~GroupModel();
	
	// for read-only
	QVariant data(const QModelIndex &index, int role) const override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
	QModelIndex parent(const QModelIndex &index) const override;
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;

	// for edition
	bool insertRows(int row, int count, const QModelIndex &parent) override;
	bool setData(const QModelIndex &index, const QVariant &value, int role) override;
	bool setData(const QModelIndex &index, QString name, QString description);
	bool removeRows(int row, int count, const QModelIndex &parent) override;

	// drag and drop support
	Qt::DropActions supportedDropActions() const
		{ return Qt::MoveAction; }
};
