#pragma once

#include <QObject>
#include <QJsonObject>

class JSON
{
public:
	static QJsonObject toJson(QObject* object);
};
