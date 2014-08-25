#pragma once

#include "head.h"

class EqualizerWidget : public QWidget
{
	Q_OBJECT

public:
	EqualizerWidget(QWidget *parent = 0);
	~EqualizerWidget(void);

protected:
	void paintEvent(QPaintEvent *event);

private:
	QWidget *m_parent;
};

