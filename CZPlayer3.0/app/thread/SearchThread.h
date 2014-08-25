#pragma once

#include "head.h"

//搜索歌曲线程
class SearchThread  : public QThread
{
	Q_OBJECT

public:
	SearchThread(QTableWidget *searchList);
	~SearchThread(void);

public:
	void setParam(QString strKey, int nStartPage);
	void startFunc();

protected:
	virtual void run();

signals:
	void sig_SearchNum(int nNum);
	void sig_LoadFinished();
	void sig_SearchTimeout();

private slots:
	void slot_LoadFinished(QNetworkReply *replay);		//加载完成

private:
	QString m_strKey;
	QString m_strUrl;
	int m_nStartPage;

	int m_nTimes;
	int m_nMusicNum;
	QTableWidget *m_searchList;
	QNetworkAccessManager *searchManager;
};

