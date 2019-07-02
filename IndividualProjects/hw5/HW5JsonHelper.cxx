//
// Created by Johnson, Hans J on 4/2/18.
//
#include <fstream>
#include <iomanip>
#include <iostream>

#include "HW5JsonHelper.h"


using namespace std;

static bool check_file_exists(const std::string& name)
{
  ifstream f(name.c_str());
  return f.good();
}

static std::string makeIndent(const size_t indent)
{
  std::string indent_chars = "";
  for (size_t i = 0; i<indent; ++i) {
    indent_chars += " ";
  }
  return indent_chars;
}

Json::Value HW5JsonHelper::getJsonDataStructure() const
{
  return this->m_JsonDataStructure;
}

HW5JsonHelper::HW5JsonHelper(const std::string filename)
{
  if (!check_file_exists(filename)) {
    cerr << "File does not exits " << filename << endl;
    exit(EXIT_FAILURE);
  }
  std::ifstream config_doc(filename, std::ifstream::binary);
  Json::Reader reader;
  bool parsingSuccessful = reader.parse(config_doc, this->m_JsonDataStructure, false);
  if (!parsingSuccessful) {
    // report to the user the failure and their locations in the document.
    cerr << reader.getFormatedErrorMessages() << endl;
  }
}

void PrintJsonValue(const Json::Value& curr_sub_json, const size_t indent)
{
  const std::string curr_indent = makeIndent(indent);
  if (curr_sub_json.isObject()) {
    const Json::Value::Members names = curr_sub_json.getMemberNames();
    for (auto ii = names.begin(); ii!=names.end(); ++ii) {
      cout << curr_indent << "------------------------------" << endl;
      cout << curr_indent << "\\" << *ii << endl;
      PrintJsonValue(curr_sub_json[*ii], indent+2);
    }
  }
  else if (curr_sub_json.isArray()) {
    for (auto elem : curr_sub_json) {
      PrintJsonValue(elem, indent+2);
    }
  }
  else if (curr_sub_json.isInt()) {
    cout << curr_indent << curr_sub_json.asInt() << endl;
  }
  else if (curr_sub_json.isString()) {
    cout << curr_indent << curr_sub_json.asString() << endl;
  }
  else {
    cout << curr_indent << " Unknown type " << curr_sub_json.toStyledString();
  }
}

void HW5JsonHelper::Print() const
{
  PrintJsonValue(this->getJsonDataStructure(), 0);
}

