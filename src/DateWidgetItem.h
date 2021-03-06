#ifndef DateWidgetItem_H
#define DateWidgetItem_H
#include <QTableWidgetItem>
#include <QtDebug>
#include <QDate>
#include "Settings.h"

class DateWidgetItem: public QTableWidgetItem
{
public:
	  explicit DateWidgetItem(QDate date);
	~DateWidgetItem();
	void setData(int role, const QVariant &value);
	QVariant data(int role) const;
	bool operator<(const QTableWidgetItem &other) const;
private:
	QDate m_data;
};



DateWidgetItem::DateWidgetItem(QDate date):
    m_data(date)
  {
  		QTableWidgetItem::setData(Qt::DisplayRole, date);
  }

DateWidgetItem::~DateWidgetItem()
{
 
}

void DateWidgetItem::setData(int role, const QVariant &value) {
	m_data = value.toDate();
	QTableWidgetItem::setData(role, value);
	
}


QVariant DateWidgetItem::data(int role) const
  {
    if (role == Qt::EditRole)	
      return QVariant(m_data);
    else if (role == Qt::DisplayRole)
      return QString(m_data.toString(sett().getDateFormat()));
    else
      return QTableWidgetItem::data(role);
  }
  
  

   bool DateWidgetItem::operator<(const QTableWidgetItem &other) const	
  {
  	    return m_data < other.data(Qt::EditRole).toDate();
  } 
    
#endif