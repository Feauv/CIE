//
// Created by Hans J. Johnson on 3/19/18.
//

#include "TransactionTime.h"


const char TransactionTime::time_fmt[] = "%c";//"%Y%m%d %H:%M:%S";

TransactionTime::TransactionTime() {
  time_t rawtime;
  time (&rawtime); //Get current UTC time
  m_time = new std::tm;
  *m_time = * (localtime (&rawtime)); //Convert static localtime pointer to a local copy.
}

TransactionTime::TransactionTime(const std::string &timeAsString)
{
  m_time = new std::tm;
  *m_time = TransactionTime::_convertStringToTime(timeAsString);
}

std::string TransactionTime::toString() const
{
  const size_t MAX_BUFFER=120;
  char timeStringBuffer [MAX_BUFFER];
  strftime (timeStringBuffer,MAX_BUFFER,TransactionTime::time_fmt,m_time);
  return std::string(timeStringBuffer);
}

void TransactionTime::setTimeFromString(std::string timeAsString)
{
  *m_time = TransactionTime::_convertStringToTime(timeAsString);
}

std::tm TransactionTime::_convertStringToTime(const std::string & timeAsString)
{
  std::tm timeObject;
  strptime(timeAsString.c_str(), TransactionTime::time_fmt, &timeObject);
  return timeObject;
}