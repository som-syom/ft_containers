#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include "./utils.hpp"

namespace ft
{

  struct input_iterator_tag {};
  struct output_iterator_tag {};
  struct forward_iterator_tag : public input_iterator_tag, output_iterator_tag {};
  struct bidirectional_iterator_tag : public forward_iterator_tag {};
  struct random_access_iterator_tag : public bidirectional_iterator_tag {};

  template<bool is_valid, typename T>
  struct valid_iterator_tag_res {
    typedef T           type;
    const static bool   value = is_valid;
  };

  template<typename T>
  struct is_input_iterator_tagged : public valid_iterator_tag_res<false, T> {};

  template<>
  struct is_input_iterator_tagged<ft::random_access_iterator_tag>
    : public valid_iterator_tag_res<true, ft::random_access_iterator_tag> {};
  template<>
  struct is_input_iterator_tagged<ft::input_iterator_tag>
    : public valid_iterator_tag_res<true, ft::input_iterator_tag> {};

  template<typename T>
  struct is_ft_iterator_tagged : public valid_iterator_tag_res<false, T> {};

  template<>
  struct is_ft_iterator_tagged<ft::random_access_iterator_tag>
    : public valid_iterator_tag_res<true, ft::random_access_iterator_tag> {};
  template<>
  struct is_ft_iterator_tagged<ft::input_iterator_tag>
    : public valid_iterator_tag_res<true, ft::input_iterator_tag> {};

  template<class iterator>
  struct iterator_traits {
    typedef typename iterator::iterator_category     iterator_category;
    typedef typename iterator::value_type            value_type;
    typedef typename iterator::difference_type       difference_type;
    typedef typename iterator::pointer               pointer;
    typedef typename iterator::reference             reference;
  };

  template<class T>
  struct iterator_traits<T*> {
    typedef T                             value_type;
    typedef ptrdiff_t                     difference_type;
    typedef T*                            pointer;
    typedef T&                            reference;
    typedef random_access_iterator_tag    iterator_category;
  };

  template<class T>
  struct iterator_traits<const T*> {
    typedef T                             value_type;
    typedef ptrdiff_t                     difference_type;
    typedef T*                            pointer;
    typedef T&                            reference;
    typedef random_access_iterator_tag    iterator_category;
  };

  template <class Category, class T, class Distance = ptrdiff_t, 
    class Pointer = T*, class Reference = T& >
  class iterator {
      public:
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
  };

  template<class InputIterator>
  typename ft::iterator_traits<InputIterator>::difference_type
      distance(InputIterator first, InputIterator last) {
    typename ft::iterator_traits<InputIterator>::difference_type ret = 0;
    while (first != last) {
      first++;
      ret++;
    }
    return (ret);
  }

  template<typename T>
  class InvalidIteratorException : public std::exception {
    private:
      std::string _msg;
    public:
      InvalidIteratorException() throw() {
        _msg = "is invalid iterator : " + std::string(typeid(T).name());
      }
      InvalidIteratorException(const InvalidIteratorException&) throw() {}
      InvalidIteratorException& operator=(const InvalidIteratorException&) throw() {}
      virtual ~InvalidIteratorException() throw() {}
      virtual const char* what() const throw() {
        return (_msg.c_str());
      }
  };

  /*
  ** bidirection iterator
  */

  template <class T>
  class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T> {
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category   iterator_category;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type          value_type;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type     difference_type;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer             pointer;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference           reference;

    private:
      pointer _elem;
  };

  /*
  ** random access iterator
  */

  template <typename T>
  class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T> {

    public:
      typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category   iterator_category;
      typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type          value_type;
      typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type     difference_type;
      typedef T*        pointer;
      typedef T&        reference;

      // constructor
      random_access_iterator() : _elem(m_nullptr) {}
      random_access_iterator(pointer elem) : _elem(elem) {}

      // copy constructor
      random_access_iterator(const random_access_iterator& ri) : _elem(ri._elem) {}

      // assignation
      random_access_iterator &operator=(const random_access_iterator& ri) {
        if (this == &ri)
          return (*this);
        this->_elem = ri._elem;
        return (*this);
      }

      // destructor
      virtual ~random_access_iterator() {}

      pointer base() const { return (this->_elem); }

      reference operator*() const { return (*_elem); }
      pointer   operator->() { return &(this->operator*()); }

      // ++ 전위연산자
      random_access_iterator& operator++() {
        _elem++;
        return (*this);
      }
      // 후위연산자 ++
      random_access_iterator operator++(int) {
        random_access_iterator ret(*this);
        ++(*this);
        return (ret);
      }
      // -- 전위연산자
      random_access_iterator& operator--() {
        _elem--;
        return (*this);
      }
      // 후위연산자 --
      random_access_iterator operator--(int) {
        random_access_iterator ret(*this);
        operator--();
        return (ret);
      }
      random_access_iterator operator+(difference_type n) const { return (_elem + n); }
      random_access_iterator operator-(difference_type n) const { return (_elem - n); }
      random_access_iterator& operator+=(difference_type n) {
        _elem += n;
        return (*this);
      }
      random_access_iterator& operator-=(difference_type n) {
        _elem -= n;
        return (*this);
      }
      reference operator[](difference_type n) { return (*(operator+(n))); }

      operator random_access_iterator<const T> () const {
        return (random_access_iterator<const T>(this->_elem));
      }
    private:
      pointer _elem;
  };

  // OPERATOR ==
  template <typename T>
  typename ft::random_access_iterator<T>::difference_type
  operator==(const ft::random_access_iterator<T> left, 
            const ft::random_access_iterator<T> right) {
    return (left.base() == right.base());
  }
  // iterator == const_iterator
  template <typename T_left, typename T_right>
  typename ft::random_access_iterator<T_left>::difference_type
  operator==(const ft::random_access_iterator<T_left> left, 
            const ft::random_access_iterator<T_right> right) {
    return (left.base() == right.base());
  }

  // OPERATOR !=
  template <typename T>
  typename ft::random_access_iterator<T>::difference_type
  operator!=(const ft::random_access_iterator<T> left, 
            const ft::random_access_iterator<T> right) {
    return (left.base() != right.base());
  }
  // iterator != const_iterator
  template <typename T_left, typename T_right>
  typename ft::random_access_iterator<T_left>::difference_type
  operator!=(const ft::random_access_iterator<T_left> left, 
            const ft::random_access_iterator<T_right> right) {
    return (left.base() != right.base());
  }

  // OPERATOR <
  template <typename T>
  typename ft::random_access_iterator<T>::difference_type
  operator<(const ft::random_access_iterator<T> left, 
            const ft::random_access_iterator<T> right) {
    return (left.base() < right.base());
  }
  // iterator < const_iterator
  template <typename T_left, typename T_right>
  typename ft::random_access_iterator<T_left>::difference_type
  operator<(const ft::random_access_iterator<T_left> left, 
            const ft::random_access_iterator<T_right> right) {
    return (left.base() < right.base());
  }

  // OPERATOR >
  template <typename T>
  typename ft::random_access_iterator<T>::difference_type
  operator>(const ft::random_access_iterator<T> left, 
            const ft::random_access_iterator<T> right) {
    return (left.base() > right.base());
  }
  // iterator > const_iterator
  template <typename T_left, typename T_right>
  typename ft::random_access_iterator<T_left>::difference_type
  operator>(const ft::random_access_iterator<T_left> left, 
            const ft::random_access_iterator<T_right> right) {
    return (left.base() > right.base());
  }

// OPERATOR <=
  template <typename T>
  typename ft::random_access_iterator<T>::difference_type
  operator<=(const ft::random_access_iterator<T> left, 
            const ft::random_access_iterator<T> right) {
    return (left.base() <= right.base());
  }
  // iterator <= const_iterator
  template <typename T_left, typename T_right>
  typename ft::random_access_iterator<T_left>::difference_type
  operator<=(const ft::random_access_iterator<T_left> left, 
            const ft::random_access_iterator<T_right> right) {
    return (left.base() <= right.base());
  }

  // OPERATOR >=
  template <typename T>
  typename ft::random_access_iterator<T>::difference_type
  operator>=(const ft::random_access_iterator<T> left, 
            const ft::random_access_iterator<T> right) {
    return (left.base() >= right.base());
  }
  // iterator >= const_iterator
  template <typename T_left, typename T_right>
  typename ft::random_access_iterator<T_left>::difference_type
  operator>=(const ft::random_access_iterator<T_left> left, 
            const ft::random_access_iterator<T_right> right) {
    return (left.base() >= right.base());
  }
  // OPERATOR + : iterator + n
  template <typename T>
  ft::random_access_iterator<T> operator+
    (typename ft::random_access_iterator<T>::difference_type n,
    typename ft::random_access_iterator<T>& iter) {
      return (&(*iter) + n);
  }
  // OPERATOR -
  template <typename T>
  typename ft::random_access_iterator<T>::difference_type
  operator-(const ft::random_access_iterator<T> left, 
            const ft::random_access_iterator<T> right) {
    return (left.base() - right.base());
  }
  // iterator - const_iterator
  template <typename T_left, typename T_right>
  typename ft::random_access_iterator<T_left>::difference_type
  operator-(const ft::random_access_iterator<T_left> left, 
            const ft::random_access_iterator<T_right> right) {
    return (left.base() - right.base());
  }
}

#endif
