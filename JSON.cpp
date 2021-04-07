#include "JSON.h"
#include <QDebug>
#include <QMetaProperty>

QJsonObject JSON::toJson(QObject* object)
{
	QJsonObject json;
	auto metaObject = object->metaObject();
	auto count = metaObject->propertyCount();
	for (auto i = 0; i < count; i++)
	{
		const auto& metaProperty = metaObject->property(i);
		auto key = metaProperty.name();
		auto value = object->property(key);
		switch (value.type())
		{
		case QMetaType::Int:
		case QMetaType::UInt:
		case QMetaType::LongLong:
		case QMetaType::Double:
		case QMetaType::Long:
		case QMetaType::Short:
		case QMetaType::ULong:
		case QMetaType::Float:
		{
			json.insert(key, value.toDouble());
		}break;
		}
	}
	qDebug() << json.toVariantHash();
	return std::move(json);
}
