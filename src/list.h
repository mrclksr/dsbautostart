/*-
 * Copyright (c) 2016 Marcel Kaiser. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <QMainWindow>
#include <QApplication>
#include <QStringList>
#include <QListWidget>
#include <QWidget>
#include <QObject>

#include "lib/dsbautostart.h"
#include "listwidget.h"

class List : public QWidget {
	Q_OBJECT
public:
	List(dsbautostart_t *as, QWidget *parent = 0);
	QListWidgetItem *addItem(entry_t *entry);
	bool modified();
	bool canUndo();
	bool canRedo();
	void newItem();
	void undo();
	void redo();
	void redraw();
	void unsetModified();
	void setShowAll(bool show);
	void newItem(QByteArray &name, QByteArray &command, QByteArray &comment,
		     QByteArray &notShowIn, QByteArray &onlyShowIn,
		     bool terminal);
	void changeCurrentItem(QByteArray &name, QByteArray &command,
			       QByteArray &comment, QByteArray &notShowIn,
			       QByteArray &onlyShowIn, bool terminal);
	entry_t *currentEntry(void);

public slots:
	void delItem();
signals:
	void listModified(bool);
	void itemDoubleClicked(entry_t *entry);
private slots:
	void addDesktopFiles(QStringList &list);
	void catchDoubleClicked(QListWidgetItem *item);
private:
	void compare();
private:
	bool	       _modified;
	bool	       showAll = false;
	ListWidget     *list;
	dsbautostart_t *as;
	QList<QListWidgetItem *> items;
};
