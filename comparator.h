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

class DecNumbersInsensitive: public dtl::Compare<std::string>
{
public:
  virtual bool impl (const std::string& lhs, const std::string& rhs) const {
    const char* dec = "0123456789";
    int i = 0, j = 0;
    while (i != std::string::npos && j != std::string::npos
           && i < lhs.length() && j < rhs.length())
      {
        if (isdigit(lhs.at(i)) && isdigit(rhs.at(j)))
          {
            i = lhs.find_first_not_of(dec, i);
            j = rhs.find_first_not_of(dec, j);
            continue;
          }
        if (lhs.at(i) != rhs.at(j))
          {
            return false;
          }

        i++;
        j++;
      }

    return true;
  }
};

class HexNumbersInsensitive: public dtl::Compare<std::string>
{
public:
  virtual bool impl (const std::string& lhs, const std::string& rhs) const {
    const char* hex = "0123456789abcdefABCDEF";
    int i = 0, j = 0;
    while (i != std::string::npos && j != std::string::npos
           && i < lhs.length() && j < rhs.length())
      {
        if (isdigit(lhs.at(i)) && isdigit(rhs.at(j)))
          {
            i = lhs.find_first_not_of(hex, i);
            j = rhs.find_first_not_of(hex, j);
            continue;
          }
        if (lhs.at(i) != rhs.at(j))
          {
            return false;
          }

        i++;
        j++;
      }

    return true;
  }
};

#endif /* INCLUDED_COMPARATOR_H */
