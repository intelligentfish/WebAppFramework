#include "JSConfig.h"

using namespace std::string_literals;

JSConfig::JSConfig(QObject* parent)
	: QObject(parent)
{
}

JSConfig::~JSConfig()
{
}

JSConfig& JSConfig::setPort(int port)
{
	_port = port;
	return *this;
}

int JSConfig::getPort() const
{
	return _port;
}

QByteArray JSConfig::toJSFile() const
{
	auto js = QString::asprintf(u8R"(function getConfigure() {
    return {
        port: %d
    };
})", _port);
	return std::move(js.toUtf8());
}
