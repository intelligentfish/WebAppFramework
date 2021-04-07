#include "WebAppFramework.h"
#include <QFrame>
#include <Windows.h>
#include <QPushButton>
#include <QResizeEvent>
#include <QWebEngineView>

#define MIN_WIDTH 1200
#define MIN_HEIGHT 600
#define FRAME_HEIGHT 40
#define DIALOG_STYLE_SHEET "background-color: rgb(85, 0, 255);"
#define FRAME_STYLE_SHEET "background-color: rgb(85, 0, 255);"
#define PUSHBUTTON_STYLE_SHEET "border-image: url(:/WebAppFramework/close.png);"

WebAppFramework::WebAppFramework(QWidget* parent)
	: QDialog(parent, Qt::FramelessWindowHint),
	_frame(),
	_pushButtonClose(),
	_webEngineView()
{
	QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	setSizePolicy(sizePolicy);
	setFixedSize(1202, 602);
	setAttribute(Qt::WA_StyledBackground);
	setStyleSheet(QString::fromUtf8(DIALOG_STYLE_SHEET));
	//setAttribute(Qt::WA_TranslucentBackground);

	// _frame
	_frame = new QFrame(this);
	_frame->installEventFilter(this);
	_frame->setFixedSize(MIN_WIDTH, FRAME_HEIGHT);
	_frame->setGeometry(1, 1, MIN_WIDTH, FRAME_HEIGHT);
	_frame->setSizePolicy(sizePolicy);
	_frame->setStyleSheet(QString::fromUtf8(FRAME_STYLE_SHEET));

	// _pushButtonClose
	_pushButtonClose = new QPushButton(_frame);
	_pushButtonClose->setGeometry(QRect(width() - 35, 2, 35, 35));
	_pushButtonClose->setStyleSheet(QString::fromUtf8(PUSHBUTTON_STYLE_SHEET));
	_pushButtonClose->setFlat(true);
	QObject::connect(_pushButtonClose,
		&QPushButton::pressed,
		[&]()
		{
			close();
		});

	// _webEngineView
	_webEngineView = new QWebEngineView(this);
	_webEngineView->setFixedSize(MIN_WIDTH, height() - FRAME_HEIGHT - 2);
	_webEngineView->setGeometry(1, FRAME_HEIGHT + 1, MIN_WIDTH, height() - FRAME_HEIGHT - 2);
	_webEngineView->setSizePolicy(sizePolicy);
	_webEngineView->setStyleSheet(QString::fromUtf8(FRAME_STYLE_SHEET));
	_webEngineView->setContextMenuPolicy(Qt::NoContextMenu);
	_webEngineView->setUrl(QUrl(QString::fromUtf8("file:///html/index.html")));
}

bool WebAppFramework::eventFilter(QObject* watched, QEvent* event)
{
	if (_frame == watched)
	{
		switch (event->type())
		{
		case QEvent::MouseButtonDblClick:
		{
			setWindowState(Qt::WindowState::WindowMaximized != windowState()
				? Qt::WindowState::WindowMaximized
				: Qt::WindowState::WindowNoState);
		}
		break;
		}
	}
	return false;
}

void WebAppFramework::resizeEvent(QResizeEvent* event)
{
	_frame->setGeometry(1, 1, width() - 2, FRAME_HEIGHT);
	_frame->setFixedSize(width() - 2, FRAME_HEIGHT);
	_pushButtonClose->setGeometry(QRect(width() - 35, 2, 35, 35));
	_webEngineView->setGeometry(1, FRAME_HEIGHT + 1, width(), height() - FRAME_HEIGHT - 2);
	_webEngineView->setFixedSize(width() - 2, height() - FRAME_HEIGHT - 2);
}

void WebAppFramework::mousePressEvent(QMouseEvent* event)
{
#ifdef Q_OS_WIN
	if (ReleaseCapture())
		SendMessage(HWND(winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
	event->ignore();
#else
#endif
}

void WebAppFramework::keyPressEvent(QKeyEvent* event)
{
	switch (event->key())
	{
	case Qt::Key_F5:
	{
#if defined(DEBUG) || defined(_DEBUG)
		_webEngineView->reload();
#endif
	}break;
	}
}

void WebAppFramework::documentReady()
{
	show();
}
