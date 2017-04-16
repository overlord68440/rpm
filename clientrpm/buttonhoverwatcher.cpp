#include "buttonhoverwatcher.h"


ButtonHoverWatcher::ButtonHoverWatcher(QString s1, QString s2, QObject * parent) :
    QObject(parent)
{this->s1=s1 ; this->s2 = s2 ;}

bool ButtonHoverWatcher::eventFilter(QObject * watched, QEvent * event)
{

    QPushButton * button = qobject_cast<QPushButton*>(watched);
    if (!button)
    {
        return false;
    }
    if (button->isCheckable())
    {
        if(button->isChecked())
            return false;
        if (event->type() == QEvent::MouseMove)
        {
            // The push button is hovered by mouse
            button->setIcon(QIcon(s1));
            return true;
        }
    }

    if (event->type() == QEvent::Enter)
    {
        // The push button is hovered by mouse
        button->setIcon(QIcon(s2));
        return true;
    }

    if (event->type() == QEvent::Leave)
    {
        // The push button is not hovered by mouse
        button->setIcon(QIcon(s1));
        return true;
    }

    return false;
}


