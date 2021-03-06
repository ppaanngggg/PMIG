﻿#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QObject>
#include <QHash>
#include <QToolBar>
#include <QList>
#include <QSpinBox>
#include <QDebug>

class ToolType{
public:
    enum toolType{
        Brush=0,
        Erase=1,
        Marquee=2,
        Pen=3
    };
};

class ToolBox:public QObject
{
private:
    void setupMarqueeToolBar(QWidget *parent);
    void setupBrushToolBar(QWidget *parent);
    void setupPenToolBar(QWidget *parent);

public:
    QList<QToolBar*> toolBarList;
    QToolBar *currentToolBar;

    QToolBar *marqueeToolBar;
    QToolBar *brushToolBar;
    QToolBar *penToolBar;

    QSpinBox *penSize;

    ToolBox(QWidget *parent);
    ~ToolBox();
};



class ToolTweak:public QToolBar
{
    Q_OBJECT
public:
    ToolTweak(const QString &title, QWidget *parent);

};


//+++++++++++++Brush+Tool+++++++++++++++++++++++++++++++++++++
class BrushToolBase
{
protected:
    static int brushSize;
    static int lineType;
    static bool antiAliasing;
};


class BrushToolTweak
        :public ToolTweak,
        protected BrushToolBase
{
    Q_OBJECT
public:
    BrushToolTweak(QWidget *parent);

private slots:
    void setBrushSize(int value){brushSize=value;}
    void setLineType(int value){lineType=value;}
    void setAntiAliasing(bool value){antiAliasing=value;}
};

class BrushToolFunction
        :public QObject,
        protected BrushToolBase
{
    Q_OBJECT
public:
    BrushToolFunction(QWidget *parent);

    int getBrushSize() const {return brushSize;}
    int getLineType() const {return lineType;}
    bool getAntiAliasing() const {return antiAliasing;}

};


//+++++++++++ERASE+TOOL+++++++++++++++++++++++++++++++++++++++
class EraseToolBase
{
protected:
    static int eraseSize;
    static int eraseShape;
};


class EraseToolTweak
        :public ToolTweak,
        protected EraseToolBase
{
    Q_OBJECT
public:
    EraseToolTweak(QWidget *parent);

private slots:
    void setEraseSize(int value){eraseSize=value;}
    void setEraseShape(int value){eraseShape=value;}

signals:
};

class EraseToolFunction
        :public QObject,
        protected EraseToolBase
{
    Q_OBJECT
public:
    EraseToolFunction(QWidget *parent);

    int getEraseSize()const {return eraseSize;}
    bool getEraseShape()const {return eraseShape;}

};


//+++++++++++++Marquee+Tool+++++++++++++++++++++++++++++++++++++
class MarqueeToolBase
{
protected:
    static int selectionType;
};


class MarqueeToolTweak
        :public ToolTweak,
        protected MarqueeToolBase
{
    Q_OBJECT
public:
    MarqueeToolTweak(QWidget *parent);

private slots:
    void setSelectionType(int value){selectionType=value; qDebug()<<value;}

};

class MarqueeToolFunction
        :public QObject,
        protected MarqueeToolBase
{
    Q_OBJECT
public:
    MarqueeToolFunction(QWidget *parent);

    int getSelectionType() const {return selectionType;}

};







//+++++++++++++Color+Swatch+++++++++++++++++++++++++++++++++++++
//class ColorSwatchBase
//{
//protected:
//    static const int colorBoxWidth;
//};


//class ColorSwatchTweak
//        :public ToolTweak,
//        protected ColorSwatchBase
//{
//    Q_OBJECT
//public:
//    ColorSwatchTweak(QWidget *parent);

//private slots:
//    void setSelectionType(int value){selectionType=value; qDebug()<<value;}

//};

//class ColorSwatchFunction
//        :public QObject,
//        protected ColorSwatchBase
//{
//    Q_OBJECT
//public:
//    ColorSwatchFunction(QWidget *parent);

//    int getSelectionType() const {return selectionType;}

//};






#endif // TOOLBOX_H
