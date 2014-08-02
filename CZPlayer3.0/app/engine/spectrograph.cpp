#include "spectrograph.h"

Spectrograph::Spectrograph(QWidget *parent) : QLabel(parent) 
	,m_lowFreq(0.0) , m_highFreq(0.0)
{
	//设置频谱label的大小
	this->resize(190, 78);
	m_vecFrequency.clear();
}

Spectrograph::~Spectrograph()
{
}

//设置频谱参数
void Spectrograph::setParams(double lowFreq, double highFreq)
{
    Q_ASSERT(highFreq > lowFreq);
    m_lowFreq = lowFreq;		//频谱下界
    m_highFreq = highFreq;		//频谱上界
}

//绘制频谱
void Spectrograph::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);

	//QPixmap backgroundImage;
	//backgroundImage.load(":/app/images/screen.png");
	////先通过pix的方法获得图片的过滤掉透明的部分得到的图片，作为loginPanel的不规则边框
	//this->setMask(backgroundImage.mask());
	//painter.drawPixmap(0, 0, 190, 78, backgroundImage);

	const int numBars = m_vecFrequency.size();

	QColor barColor(5, 184, 204);		//频谱bar颜色

    barColor = barColor.lighter();
    barColor.setAlphaF(0.75);		//设置alpha通道

    //绘制频谱
    if (numBars)
	{
        //计算宽度的条和空白
		const int widgetWidth = this->width();										//频谱widget宽度
        const int barPlusGapWidth = widgetWidth / numBars;							//每一个频谱加空白间隙的宽度
        const int barWidth = 0.8 * barPlusGapWidth;									//每一个频谱bar的宽度
        const int gapWidth = barPlusGapWidth - barWidth;							//每一个空白间隙宽度
        const int paddingWidth = widgetWidth - numBars * (barWidth + gapWidth);		//边缘宽度
        const int leftPaddingWidth = (paddingWidth + gapWidth) / 2;					//左边缘宽度
        const int barHeight = this->height() - 2 * gapWidth;						//每一个频谱bar的高度

		//绘制每一个频谱bar
        for (int i = 0; i < numBars; ++i)
		{
            const double value = m_vecFrequency[i];		//vlaue的值在0到1之间
            Q_ASSERT(value >= 0.0 && value <= 1.0);

            QRect bar = rect();
			//设置频谱bar的位置和大小
            bar.setLeft(rect().left() + leftPaddingWidth + (i * (gapWidth + barWidth)));
            bar.setWidth(barWidth);
            bar.setTop(rect().top() + gapWidth + (1.0 - value) * barHeight);
            bar.setBottom(rect().bottom() - gapWidth);

            QColor color = barColor;
			
			//设置颜色渐变
			//QLinearGradient linearGradient(bar.topLeft(), bar.bottomRight());
			//linearGradient.setColorAt(0.1, QColor(247, 104, 9));
			//linearGradient.setColorAt(1.0, QColor(238, 17, 128)); 
			//painter.fillRect(bar, QBrush(linearGradient));

            painter.fillRect(bar, color);
        }
    }
	event->accept();
}

//频谱改变
void Spectrograph::slot_spectrumChanged( vector<float> vecFrequency )
{
	m_vecFrequency = vecFrequency;
	update();						//刷新频谱
}

//重置频谱
void Spectrograph::reset()
{
	m_vecFrequency.clear();
	update();
}

