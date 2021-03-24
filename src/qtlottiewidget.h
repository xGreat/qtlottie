#pragma once

#include "qtlottie_global.h"
#include <QtWidgets/qwidget.h>

class QtLottieHelper;

class QTLOTTIE_API QtLottieWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(QtLottieWidget)
    Q_PROPERTY(QString filePath READ filePath WRITE setFilePath NOTIFY filePathChanged)

public:
    explicit QtLottieWidget(QWidget *parent = nullptr);
    ~QtLottieWidget() override;

    QString filePath() const;
    void setFilePath(const QString &value);

Q_SIGNALS:
    void filePathChanged();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QScopedPointer<QtLottieHelper> m_lottieHelper;
    QString m_filePath = {};
};
