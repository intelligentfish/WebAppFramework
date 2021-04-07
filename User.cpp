#include "User.h"
#include <QDebug>

User::User(QObject* parent)
	: QObject(parent)
{
}

User::~User()
{
}

bool User::signIn(const QString& name, const QString& password)
{
	qDebug() << "name: " << name << ", password: " << password;
	return false;
}


const QString& User::name() const
{
	return _name;
}