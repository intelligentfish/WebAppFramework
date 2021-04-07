#include <Windows.h>
#include <QJsonDocument>
#include <QDebug>
#include <QtWebChannel>
#include <QDir>
#include <QFile>
#include "User.h"
#include "WebAppFramework.h"
#include "JSConfig.h"
#include "websockettransport.h"
#include "websocketclientwrapper.h"
#include <QWebSocketServer>
#include <QtWidgets/QApplication>

/// <summary>
/// ��ȡ��ǰĿ¼
/// </summary>
/// <returns></returns>
QString getCurrentDirectory()
{
	auto size = 128;
	while (true)
	{
		std::wstring buf(size, '\0');
		const auto len = GetCurrentDirectoryW(buf.capacity(), &buf[0]);
		if (buf.capacity() > len + 1)
		{
			buf[len] = L'\\';
			return std::move(QString::fromWCharArray(&buf[0], len + 1));
		}
		size *= 2;
	}
}

/// <summary>
/// ����JS����
/// </summary>
void updateJSConfigure(const QString& path, int port)
{
	JSConfig config;
	config.setPort(port);
	QFile jsFile(path);
	if (jsFile.open(QFile::ReadWrite | QFile::Truncate | QFile::Text))
	{
		jsFile.write(config.toJSFile());
		jsFile.flush();
	}
}

/// <summary>
/// ��ͨ��ע�����
/// </summary>
/// <param name="channel">ͨ��</param>
/// <param name="a">����</param>
void registerObjects(QWebChannel& channel, QApplication& a)
{
#define REGISTER_OBJECT(CLASS) channel.registerObject(QStringLiteral(#CLASS), new CLASS(&a))
	REGISTER_OBJECT(User);
}

/// <summary>
/// ��ڷ���
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>
int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	QWebSocketServer qs(QStringLiteral("Backend"), QWebSocketServer::NonSecureMode);
	qs.setHandshakeTimeout(2500);
	qs.setMaxPendingConnections(16);
	qs.listen();
	if (qs.isListening())
		updateJSConfigure(getCurrentDirectory().append(QStringLiteral("html\\js\\config.js")),
			qs.serverPort());
	WebSocketClientWrapper clientWrapper(&qs);
	QWebChannel channel;
	QObject::connect(&clientWrapper,
		&WebSocketClientWrapper::clientConnected,
		&channel,
		&QWebChannel::connectTo);
	WebAppFramework framework;
	registerObjects(channel, a);
	channel.registerObject(QStringLiteral("WebAppFramework"), &framework);
	framework.hide();
	return a.exec();
}
