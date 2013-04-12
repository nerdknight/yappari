/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -v -c DBusNotificationsIf -p dbusnotificationsif.h:dbusnotificationsif.cpp org.freedesktop.Notifications.xml
 *
 * qdbusxml2cpp is Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef DBUSNOTIFICATIONSIF_H_1340640704
#define DBUSNOTIFICATIONSIF_H_1340640704

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.freedesktop.Notifications
 */
class DBusNotificationsIf: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.Notifications"; }

public:
    DBusNotificationsIf(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~DBusNotificationsIf();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> CloseNotification(uint id)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(id);
        return asyncCallWithArgumentList(QLatin1String("CloseNotification"), argumentList);
    }

    inline QDBusPendingReply<QStringList> GetCapabilities()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetCapabilities"), argumentList);
    }

    inline QDBusPendingReply<QString, QString, QString, QString> GetServerInformation()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetServerInformation"), argumentList);
    }
    inline QDBusReply<QString> GetServerInformation(QString &vendor, QString &version, QString &spec_version)
    {
        QList<QVariant> argumentList;
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QLatin1String("GetServerInformation"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 4) {
            vendor = qdbus_cast<QString>(reply.arguments().at(1));
            version = qdbus_cast<QString>(reply.arguments().at(2));
            spec_version = qdbus_cast<QString>(reply.arguments().at(3));
        }
        return reply;
    }

    inline QDBusPendingReply<uint> Notify(const QString &app_name, uint replaces_id, const QString &app_icon, const QString &summary, const QString &body, const QStringList &actions, const QVariantMap &hints, int timeout)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(app_name) << qVariantFromValue(replaces_id) << qVariantFromValue(app_icon) << qVariantFromValue(summary) << qVariantFromValue(body) << qVariantFromValue(actions) << qVariantFromValue(hints) << qVariantFromValue(timeout);
        return asyncCallWithArgumentList(QLatin1String("Notify"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void ActionInvoked(uint id, const QString &action_key);
    void NotificationClosed(uint id, uint reason);
};

namespace org {
  namespace freedesktop {
    typedef ::DBusNotificationsIf Notifications;
  }
}
#endif