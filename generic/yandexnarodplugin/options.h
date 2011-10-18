/*
    proxy.h

	Copyright (c) 2011 by Evgeny Khryukin

 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************
*/

#ifndef PROXY_H
#define PROXY_H

#include <QNetworkProxy>
#include "QVariant"

class ApplicationInfoAccessingHost;
class OptionAccessingHost;

class Options : public QObject
{
	Q_OBJECT
public:
	static Options * instance();
	static void reset();
	void setApplicationInfoAccessingHost(ApplicationInfoAccessingHost* host);
	void setOptionAccessingHost(OptionAccessingHost* host);
	void setOption(const QString& name, const QVariant& value);
	QVariant getOption(const QString& name, const QVariant& def = QVariant::Invalid);
	QNetworkProxy getProxy() const;
	bool useProxy() const;

private:
	static Options * instance_;
	Options ();
	virtual ~Options();

	ApplicationInfoAccessingHost* appInfo;
	OptionAccessingHost* options;
};

#endif // PROXY_H