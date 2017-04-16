#ifndef BUTTONHOVERWATCHER_H
#define BUTTONHOVERWATCHER_H

#include <QPushButton>
#include <QEvent>
#include <QString>

class ButtonHoverWatcher : public QObject,public QString
{
    Q_OBJECT
public:
    explicit ButtonHoverWatcher(QString s,QString s2, QObject * parent = Q_NULLPTR);
    virtual bool eventFilter(QObject * watched, QEvent * event) Q_DECL_OVERRIDE;
    QString s1 ;
    QString s2 ;

};


#endif // BUTTONHOVERWATCHER_H
