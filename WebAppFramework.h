#pragma once

#include <QtWidgets/QDialog>

class QFrame;
class QPushButton;
class QWebEngineView;

/// <summary>
/// ���
/// </summary>
class WebAppFramework : public QDialog
{
	Q_OBJECT

public:
	/// <summary>
	/// ���췽��
	/// </summary>
	WebAppFramework(QWidget* parent = Q_NULLPTR);
	/// <summary>
	/// �¼�������
	/// </summary>
	/// <param name="watched"></param>
	/// <param name="event"></param>
	/// <returns></returns>
	virtual bool eventFilter(QObject* watched, QEvent* event) override;
	/// <summary>
	/// ��С�ı��¼�
	/// </summary>
	/// <param name="event"></param>
	virtual void resizeEvent(QResizeEvent* event) override;
	/// <summary>
	/// ��갴���¼�
	/// </summary>
	/// <param name="event"></param>
	virtual void mousePressEvent(QMouseEvent* event) override;
	/// <summary>
	/// ����ѹ�¼�
	/// </summary>
	/// <param name="event"></param>
	virtual void keyPressEvent(QKeyEvent* event) override;
	/// <summary>
	/// HTML�ĵ�׼����
	/// </summary>
	/// <returns></returns>
	Q_INVOKABLE void documentReady();

private:
	QFrame* _frame;
	QPushButton* _pushButtonClose;
	QWebEngineView* _webEngineView;
};
