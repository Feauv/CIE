//
// Created by Johnson, Hans J on 4/2/18.
//

#ifndef HOMEWORK5_HW5JSONHELPER_H
#define HOMEWORK5_HW5JSONHELPER_H

//https://github.com/open-source-parsers/jsoncpp/wiki
#include "json/json.h"

/**
 * @brief Print Json values
 * @param curr_sub_json The current value to print
 * @param indent the current indent level
 */
extern void PrintJsonValue(const Json::Value & curr_sub_json, const size_t indent = 0);

class HW5JsonHelper {
public:
  /**
   * @brief Constructor that requires a filename
   * @param filename The file to read during construction of this helper class
   */
  HW5JsonHelper(const std::string filename);
  void Print() const;

  Json::Value getJsonDataStructure() const;
private:
  Json::Value m_JsonDataStructure;
};

#endif //HOMEWORK5_HW5JSONHELPER_H
