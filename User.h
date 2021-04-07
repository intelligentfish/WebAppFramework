#pragma once

#include <QObject>

/// <summary>
/// 用户
/// </summary>
class User : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString name READ name NOTIFY nameChanged)
public:
	/// <summary>
	/// 构造方法
	/// </summary>
	User(QObject* parent);
	/// <summary>
	/// 析构方法
	/// </summary>
	virtual ~User();
	/// <summary>
	/// 登录
	/// </summary>
	/// <param name="name"></param>
	/// <param name="password"></param>
	/// <returns></returns>
	Q_INVOKABLE bool signIn(const QString& name, const QString& password);
	/// <summary>
	/// 名字方法
	/// </summary>
	/// <returns></returns>
	const QString& name() const;
signals:
	void nameChanged();

private:
	QString _name;
};
