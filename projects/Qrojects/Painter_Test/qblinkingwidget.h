#ifndef QBLINKINGWIDGET_H
#define QBLINKINGWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>

class QBlinkingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QBlinkingWidget(QWidget *parent = 0);

signals:

public slots:

private slots:
    void onBlink();

private:
    QTimer blinkTimer;
    bool blink;
protected:
    void paintEvent(QPaintEvent *event);

};

#endif // QBLINKINGWIDGET_H
