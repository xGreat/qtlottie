/*
 * MIT License
 *
 * Copyright (C) 2022 by wangwenx190 (Yuhang Zhao)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include "qtlottiedrawengine.h"

struct Lottie_Animation;

class QTLOTTIE_API QtLottieRLottieEngine : public QtLottieDrawEngine
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(QtLottieRLottieEngine)

public:
    explicit QtLottieRLottieEngine(QObject *parent = nullptr);
    ~QtLottieRLottieEngine() override;

    void paint(QPainter *painter, const QSizeF &s) override;
    void render(const QSizeF &s) override;
    void release() override;

    QString name() const override;

    QUrl source() const override;
    bool setSource(const QUrl &value) override;

    qreal frameRate() const override;

    qreal duration() const override;

    QSizeF size() const override;

    int loops() const override;
    void setLoops(const int value) override;

    bool available() const override;

    bool playing() const override;

public Q_SLOTS:
    void pause() override;
    void resume() override;

private:
    QUrl m_source = {};
    Lottie_Animation *m_animation = nullptr;
    QScopedArrayPointer<char> m_frameBuffer;
    quint64 m_currentFrame = 0;
    quint64 m_totalFrame = 0;
    quint64 m_width = 0;
    quint64 m_height = 0;
    bool m_hasFirstUpdate = false;
    double m_frameRate = 0;
    double m_duration = 0;
    int m_loops = 0;
    int m_loopTimes = 0;
    bool m_shouldStop = false;
};
