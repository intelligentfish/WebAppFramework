#pragma once

#include <QObject>

/// <summary>
/// JS配置
/// </summary>
class JSConfig : public QObject
{
	Q_OBJECT
private:
	int _port; // 端口
public:
	/// <summary>
	/// 属性
	/// </summary>
	Q_PROPERTY(int port READ getPort WRITE setPort);
public:
	/// <summary>
	/// 构造方法
	/// </summary>
	/// <param name="parent"></param>
	JSConfig(QObject* parent = nullptr);
	/// <summary>
	/// 析构方法
	/// </summary>
	virtual ~JSConfig();
	/// <summary>
	/// 设置端口
	/// </summary>
	/// <param name="port"></param>
	/// <returns></returns>
	JSConfig& setPort(int port);
	/// <summary>
	/// 获取端口
	/// </summary>
	/// <returns></returns>
	int getPort() const;
	/// <summary>
	/// 转换为JS文件
	/// </summary>
	/// <returns></returns>
	QByteArray toJSFile() const;
};
