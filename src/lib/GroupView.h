/***************************************************************************
 *   Copyright (C) 2005 by Tarek Saidi                                     *
 *   tarek.saidi@arcor.de                                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef _GROUP_VIEW_H_
#define _GROUP_VIEW_H_

#include <QTreeWidget>
#include "../PwManager.h"

class GroupViewItem;
typedef vector<GroupViewItem*>::iterator GroupItemItr;

class KeepassGroupView:public QTreeWidget{
public:
 KeepassGroupView(QWidget* parent=0);
 void updateItems();
 PwDatabase *db;
 vector<GroupViewItem*>Items;
protected:
 virtual void dragEnterEvent ( QDragEnterEvent * event );
 virtual void dragMoveEvent ( QDragMoveEvent * event );
 virtual void dragLeaveEvent ( QDragLeaveEvent * event );
 virtual void dropEvent ( QDropEvent * event );
 virtual void mousePressEvent(QMouseEvent *event);
 virtual void mouseMoveEvent(QMouseEvent *event);

private:
 QPoint DragStartPos;
 QPixmap DragPixmap;
 GroupViewItem* LastHoverItem;
 GroupViewItem* getLastSameLevelItem(int level);
};


class GroupViewItem:public QTreeWidgetItem{
public:
GroupViewItem(QTreeWidget *parent);
GroupViewItem(QTreeWidget *parent, QTreeWidgetItem * preceding);
GroupViewItem(QTreeWidgetItem *parent);
GroupViewItem(QTreeWidgetItem *parent, QTreeWidgetItem * preceding);
CGroup* pGroup;
};


#endif