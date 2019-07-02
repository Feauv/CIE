//
// Created by Hans J. Johnson on 3/19/18.
//

#ifndef HW4_TRANSACTIONTIME_H
#define HW4_TRANSACTIONTIME_H

#include <ctime>
#include <string>

class TransactionTime {
public:

  /**
   * Default constuctor for time setting time to Now.
   */
  TransactionTime();

    /**
   * Constructor of time from string;
   */
  TransactionTime(const std::string &timeAsString);

  /**
   * Convert a std::tm object to a string
   * @return Time as a string
   */
  std::string toString() const;

  /**
   * Set the std::tm object from a string
   * @param timeAsString
   */
  void setTimeFromString(std::string timeAsString);

private:
  static void _Now();
  static std::tm _convertStringToTime(const std::string & timeAsString);
  static const char time_fmt[];
  std::tm * m_time;

};


#endif //HW4_TRANSACTIONTIME_H
