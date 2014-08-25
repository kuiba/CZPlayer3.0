#include "EqualizerWidget.h"


EqualizerWidget::EqualizerWidget(QWidget *parent) : m_parent(parent)
{
	//设置窗口基本属性
	this->resize(400, 150);//设置窗体大小
	this->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);//去掉窗体边框
	this->setAttribute(Qt::WA_TranslucentBackground);//设置背景透明
	this->setWindowIcon(QIcon(":/app/images/CZPlayer.png"));//设置logo
	this->setWindowTitle(tr("均衡器"));
}

EqualizerWidget::~EqualizerWidget(void)
{
}

//重写paintEvent,添加背景图片
void EqualizerWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QPixmap backgroundImage;
	backgroundImage.load(":/app/images/equalizerBg.png");

	//先通过pix的方法获得图片的过滤掉透明的部分得到的图片，作为loginPanel的不规则边框
	this->setMask(backgroundImage.mask());
	painter.drawPixmap(0, 0, 400, 150, backgroundImage);
	event->accept();
}
