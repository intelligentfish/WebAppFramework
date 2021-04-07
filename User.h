#pragma once

#include <QObject>

/// <summary>
/// �û�
/// </summary>
class User : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString name READ name NOTIFY nameChanged)
public:
	/// <summary>
	/// ���췽��
	/// </summary>
	User(QObject* parent);
	/// <summary>
	/// ��������
	/// </summary>
	virtual ~User();
	/// <summary>
	/// ��¼
	/// </summary>
	/// <param name="name"></param>
	/// <param name="password"></param>
	/// <returns></returns>
	Q_INVOKABLE bool signIn(const QString& name, const QString& password);
	/// <summary>
	/// ���ַ���
	/// </summary>
	/// <returns></returns>
	const QString& name() const;
signals:
	void nameChanged();

private:
	QString _name;
};
