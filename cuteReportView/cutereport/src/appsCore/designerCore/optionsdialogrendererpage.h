/***************************************************************************
 *   This file is part of the CuteReport project                           *
 *   Copyright (C) 2012-2015 by Alexander Mikhalov                         *
 *   alexander.mikhalov@gmail.com                                          *
 *                                                                         *
 **                   GNU General Public License Usage                    **
 *                                                                         *
 *   This library is free software: you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation, either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 ***************************************************************************/

#ifndef OPTIONSDIALOGRENDERERPAGE_H
#define OPTIONSDIALOGRENDERERPAGE_H

#include "optionsdialog.h"

#include <QPointer>

namespace Ui {
class OptionsDialogRendererPage;
}

namespace CuteDesigner {
class Core;
}

namespace CuteReport {
class RendererHelperInterface;
class RendererInterface;
}

class QTreeWidgetItem;

class OptionsDialogRendererPage :  public OptionsDialogPageInterface
{
    Q_OBJECT

public:
    explicit OptionsDialogRendererPage(CuteDesigner::Core *core);
    ~OptionsDialogRendererPage();

    virtual void activate();
    virtual void deactivate();

    QListWidgetItem * createButton(QListWidget * listWidget);

private slots:
    void listIndexChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous);
    void setNewObject();
    void deleteCurrent();
    void setDefault();
    void clearDefault();
    void updateObjectList();

private:
    Ui::OptionsDialogRendererPage *ui;
    CuteDesigner::Core * m_core;
    QPointer<QWidget> m_currentHelper;
};

#endif // OPTIONSDIALOGRENDERERPAGE_H
