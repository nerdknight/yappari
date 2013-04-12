/* Copyright 2013 Naikel Aparicio. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY <COPYRIGHT HOLDER> ''AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL EELI REILIN OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation
 * are those of the authors and should not be interpreted as representing
 * official policies, either expressed or implied, of Eeli Reilin.
 */

#include <QAbstractTextDocumentLayout>
#include <QTextDocument>

#include "contactdisplayitem.h"

#include "Whatsapp/util/utilities.h"

#include "client.h"

ContactDisplayItem::ContactDisplayItem(Contact *c) :
    QStandardItem()
{
    this->contact = c;

    QString name = (c->fromAddressBook) ? c->name : c->alias;

    name = name.replace("<","&lt;").replace(">","&gt;");
    QString status = c->status.replace("<","&lt;").replace(">","&gt;");

    QString html = "<table width=\"100%\"><tr><td>" + name + "</td>"
                   "<td align=\"right\">";

    if (Client::showNumbers)
        html.append("<div style=\"font-size:16px;color:gray\">(" +
                    c->phone + ")&nbsp;</div>");

    QTextDocument line;
    line.setHtml("<div style=\"font-size:18px;color:gray\">O</div>");

    html.append("</td></tr>"
                "<tr><td colspan=\"2\"><div style=\"font-size:18px;color:gray\">" +
                Utilities::formatMessage(status,line.documentLayout()->documentSize().height() - 8)
                + "</div></td></tr></table>");

    setEditable(false);

    setData(html,Qt::DisplayRole);
    setData(c->jid,Qt::UserRole + 1);

    if (!c->photo.isNull())
        setData(c->photo.scaled(64,64), Qt::UserRole);
}

Contact* ContactDisplayItem::getContact()
{
    return contact;
}