#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <cstddef>
# include <typeinfo>

const static class
{
    public:
      template<class T>
      operator T*() const { return (0);}

      template<class T, class C>
      operator T C::*() const { return (0);}
    private:
      void operator&() const;
} m_nullptr = {};

namespace ft
{
  // enable if
  template<bool condition, class T = void>
  struct enable_if {};

  template<class T>
  struct enable_if<true, T> {
    typedef T type;
  };

  // is integral
  template <bool is_integral, typename T>
  struct is_integral_res {
    typedef T type;
    static const bool value = is_integral;
  };

  template<typename>
  struct is_integral_type : public is_integral_res<false, bool> {};

  template<>
  struct is_integral_type<bool> : public is_integral_res<true, bool> {};
  template<>
  struct is_integral_type<char> : public is_integral_res<true, char> {};
  template<>
  struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};
  template<>
  struct is_integral_type<short int> : public is_integral_res<true, short int> {};
  template<>
  struct is_integral_type<int> : public is_integral_res<true, int> {};
  template<>
  struct is_integral_type<long int> : public is_integral_res<true, long int> {};
  template<>
  struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};
  template<>
  struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};
  template<>
  struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};
  template<>
  struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};
  template<>
  struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
  template<>
  struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

  template<typename T>
  struct is_integral : public is_integral_type<T> {};

  // lexicographical compare

  template<class InputIterator1, class InputIterator2>
  bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                              InputIterator2 first2, InputIterator2 last2) {
    while (first1 != last1) {
      if (first2 == last2 || *first2 < *first1)
        return false;
      else if (*first1 < *first2)
        return true;
      ++first1;
      ++first2;
    }
    return (first2 != last2);
  }

  template<class InputIterator1, class InputIterator2, class Compare>
  bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                              InputIterator2 first2, InputIterator2 last2,
                              Compare comp) {
    while (first1 != last1) {
      if (first2 == last2 || comp(*first2, *first1))
        return false;
      else if (comp(*first1 < *first2))
        return true;
      ++first1;
      ++first2;
    }
    return (first2 != last2);
  }

  template<class Arg1, class Arg2, class Result>
  struct binary_function {
    typedef Arg1    first_argument_type;
    typedef Arg2    second_argument_type;
    typedef Result  result_type;
  };

  template<class T>
  struct less : binary_function<T, T, bool> {
    bool operator()(const T& x, const T& y) const {
      return (x < y);
    }
  };

  template<class T1, class T2>
  struct pair {
    public:
      typedef T1 first_type;
      typedef T2 second_type;

      first_type  first;
      second_type second;

      // default constructor
      pair() : first(), second() {}

      // copy constructor
      template<class U, class V>
      pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}

      // initialization constructor
      pair(const first_type& a, const second_type& b) : first(a), second(b) {}

      // assign
      pair& operator=(const pair& pr) {
        // if (*this == pr) return (*this);
        this->first = pr.first;
        this->second = pr.second;
        return (*this);
      }
  };

  // relational operator
  template<class T1, class T2>
  bool operator==(const ft::pair<T1, T2>& left, const ft::pair<T1, T2>& right) {
    return (left.first == right.first && left.second == right.second);
  }

  template<class T1, class T2>
  bool operator!=(const ft::pair<T1, T2>& left, const ft::pair<T1, T2>& right) {
    return !(left == right);
  }

  template<class T1, class T2>
  bool operator<(const ft::pair<T1, T2>& left, const ft::pair<T1, T2>& right) {
    return (left.first < right.first || (!(right.first < left.first) && left.second < right.second));
  }

  template<class T1, class T2>
  bool operator<=(const ft::pair<T1, T2>& left, const ft::pair<T1, T2>& right) {
    return !(right < left);
  }

  template<class T1, class T2>
  bool operator>(const ft::pair<T1, T2>& left, const ft::pair<T1, T2>& right) {
    return (right < left);
  }

  template<class T1, class T2>
  bool operator>=(const ft::pair<T1, T2>& left, const ft::pair<T1, T2>& right) {
    return !(left < right);
  }

  // constructor pair
  template<class T1, class T2>
  ft::pair<T1, T2> make_pair(T1 x, T2 y) {
    return (ft::pair<T1, T2>(x, y));
  }

  template<typename T>
  struct BST_Node {
    public:
      typedef T value_type;

      value_type  value;
      BST_Node*   parent;
      BST_Node*   left;
      BST_Node*   right;

      // default constructor
      BST_Node() : value(), parent(m_nullptr), left(m_nullptr), right(m_nullptr) {}

      // constructur
      BST_Node(BST_Node* parent = m_nullptr, BST_Node* left = m_nullptr, BST_Node* right = m_nullptr)
      : value(), parent(parent), left(left), right(right) {}

      // fill constructor
      BST_Node(const value_type& val, BST_Node* parent = m_nullptr,
              BST_Node* left = m_nullptr, BST_Node* right = m_nullptr)
      : value(val), parent(parent), left(left), right(right) {}

      // copy constructor
      BST_Node (const BST_Node& nd)
      : value(nd.value), parent(nd.parent), left(nd.left), right(nd.right) {}

      // destructor
      virtual ~BST_Node() {}

      // assign operator
      BST_Node &operator=(const BST_Node& nd) {
        if (nd == *this) return (*this);
        this->value = nd.value;
        this->parent = nd.parent;
        this->left = nd.left;
        this->right = nd.right;
        return (*this);
      }

      // compare
      bool operator==(const BST_Node& nd) {
        if (value == nd.value) return (true);
        return (false);
      };
  };

}

#endif
