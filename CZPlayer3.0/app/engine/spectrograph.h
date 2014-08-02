#ifndef SPECTROGRAPH_H
#define SPECTROGRAPH_H

#include <QtCore>
#include <QtGui>
#include <vector>
using namespace std;

QT_FORWARD_DECLARE_CLASS(QMouseEvent)

//频谱绘制
class Spectrograph : public QLabel
{
    Q_OBJECT

public:
    Spectrograph(QWidget *parent = 0);
    ~Spectrograph();

public:
	//lowFreq:频谱下界
	//highFreq:频谱上节
    void setParams(double lowFreq, double highFreq);//设置参数

	void reset();													//重置频谱
	
protected:
    void paintEvent(QPaintEvent *event);

signals:
    void infoMessage(const QString &message, int intervalMs);	//消息信号

public slots:
	void slot_spectrumChanged(vector<float> vecFrequency);

private:
    double              m_lowFreq;								//频谱下界
    double              m_highFreq;								//频谱上界
	vector<float> m_vecFrequency;								//通过快速傅里叶变换传过来的参数
};

#endif // SPECTROGRAPH_H
