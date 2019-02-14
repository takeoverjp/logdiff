#ifndef INCLUDED_COMPARATOR_H
#define INCLUDED_COMPARATOR_H

class DecNumberInsensitive: public dtl::Compare<std::string>
{
public:
  virtual bool impl (const std::string& lhs, const std::string& rhs) const {
    if (lhs.length() != rhs.length())
      return false;

    for (int i = 0; i < lhs.length(); i++)
      {
        if (isdigit(lhs.at(i)) && isdigit(rhs.at(i)))
          continue;
        if (lhs.at(i) != rhs.at(i))
          {
            return false;
          }
      }

    return true;
  }
};

class HexNumberInsensitive: public dtl::Compare<std::string>
{
public:
  virtual bool impl (const std::string& lhs, const std::string& rhs) const {
    if (lhs.length() != rhs.length())
      return false;

    for (int i = 0; i < lhs.length(); i++)
      {
        if (isxdigit(lhs.at(i)) && isxdigit(rhs.at(i)))
          continue;
        if (lhs.at(i) != rhs.at(i))
          {
            return false;
          }
      }

    return true;
  }
};

#endif /* INCLUDED_COMPARATOR_H */
