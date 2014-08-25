#ifndef HOTKEYSTABLEWIDGET_H
#define HOTKEYSTABLEWIDGET_H

#include "head.h"

//ÈÈ¼üÒ³Ãæ
class HotKeysTableWidget : public QTableWidget
{
    Q_OBJECT

public:
    HotKeysTableWidget(QWidget *parent);
    ~HotKeysTableWidget();

private:
    QWidget *m_parent;
};

#endif // HOTKEYSTABLEWIDGET_H
