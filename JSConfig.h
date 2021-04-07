#pragma once

#include <QObject>

/// <summary>
/// JS����
/// </summary>
class JSConfig : public QObject
{
	Q_OBJECT
private:
	int _port; // �˿�
public:
	/// <summary>
	/// ����
	/// </summary>
	Q_PROPERTY(int port READ getPort WRITE setPort);
public:
	/// <summary>
	/// ���췽��
	/// </summary>
	/// <param name="parent"></param>
	JSConfig(QObject* parent = nullptr);
	/// <summary>
	/// ��������
	/// </summary>
	virtual ~JSConfig();
	/// <summary>
	/// ���ö˿�
	/// </summary>
	/// <param name="port"></param>
	/// <returns></returns>
	JSConfig& setPort(int port);
	/// <summary>
	/// ��ȡ�˿�
	/// </summary>
	/// <returns></returns>
	int getPort() const;
	/// <summary>
	/// ת��ΪJS�ļ�
	/// </summary>
	/// <returns></returns>
	QByteArray toJSFile() const;
};
