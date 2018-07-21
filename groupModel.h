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

	Group *rootGroup;

public:
	GroupModel(Group *data, QObject *parent);
	~GroupModel();
	
	QVariant data(const QModelIndex &index, int role) const override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
	QModelIndex parent(const QModelIndex &index) const override;
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
};
