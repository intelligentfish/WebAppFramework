#pragma once

#include <QtWidgets/QDialog>

class QFrame;
class QPushButton;
class QWebEngineView;

/// <summary>
/// 框架
/// </summary>
class WebAppFramework : public QDialog
{
	Q_OBJECT

public:
	/// <summary>
	/// 构造方法
	/// </summary>
	WebAppFramework(QWidget* parent = Q_NULLPTR);
	/// <summary>
	/// 事件过滤器
	/// </summary>
	/// <param name="watched"></param>
	/// <param name="event"></param>
	/// <returns></returns>
	virtual bool eventFilter(QObject* watched, QEvent* event) override;
	/// <summary>
	/// 大小改变事件
	/// </summary>
	/// <param name="event"></param>
	virtual void resizeEvent(QResizeEvent* event) override;
	/// <summary>
	/// 鼠标按下事件
	/// </summary>
	/// <param name="event"></param>
	virtual void mousePressEvent(QMouseEvent* event) override;
	/// <summary>
	/// 键下压事件
	/// </summary>
	/// <param name="event"></param>
	virtual void keyPressEvent(QKeyEvent* event) override;
	/// <summary>
	/// HTML文档准备好
	/// </summary>
	/// <returns></returns>
	Q_INVOKABLE void documentReady();

private:
	QFrame* _frame;
	QPushButton* _pushButtonClose;
	QWebEngineView* _webEngineView;
};
