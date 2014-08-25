#pragma once

#include <QtCore>
#include <QtGui>

//软件更新页面
class UpdatePage : public QWidget
{
	Q_OBJECT

public:
	UpdatePage(QWidget *parent = 0);
	~UpdatePage(void);

private:
	QWidget *m_parent;

	QLabel *updateLabel;
	QPushButton *updateButton;
};

