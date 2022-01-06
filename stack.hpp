#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <string>
# include "./vector.hpp"
namespace ft {

  template<class T, class Container = ft::vector<T> >
  class stack {
    public:
      // Member type
      typedef T                 value_type;
      typedef Container         container_type;
      typedef size_t            size_type;

      // default constructor
      explicit stack(const container_type& ctnr = container_type())
        : _c(ctnr) {}
      // destroctor
      ~stack() {}

      // empty
      bool empty() const { return (this->_c.empty()); }

      // size
      size_type size() const { return (this->_c.size()); }

      // top
      value_type& top() { return (this->_c.back()); }
      const value_type& top() const { return (this->_c.back()); }

      // push
      void push(const value_type& val) { this->_c.push_back(val); }

      // pop
      void pop() { this->_c.pop_back(); }

      // friend
      template<class Tn, class ContainerN>
      friend bool operator==(const ft::stack<Tn, ContainerN>& left,
                            const ft::stack<Tn, ContainerN>& right);
      template<class Tn, class ContainerN>
      friend bool operator!=(const ft::stack<Tn, ContainerN>& left,
                            const ft::stack<Tn, ContainerN>& right);
      template<class Tn, class ContainerN>
      friend bool operator<(const ft::stack<Tn, ContainerN>& left,
                            const ft::stack<Tn, ContainerN>& right);
      template<class Tn, class ContainerN>
      friend bool operator<=(const ft::stack<Tn, ContainerN>& left,
                            const ft::stack<Tn, ContainerN>& right);
      template<class Tn, class ContainerN>
      friend bool operator>(const ft::stack<Tn, ContainerN>& left,
                            const ft::stack<Tn, ContainerN>& right);
      template<class Tn, class ContainerN>
      friend bool operator>=(const ft::stack<Tn, ContainerN>& left,
                            const ft::stack<Tn, ContainerN>& right);

      protected:
        container_type _c;
  };

  template<class Tn, class ContainerN>
  bool operator==(const ft::stack<Tn, ContainerN>& left,
                const ft::stack<Tn, ContainerN>& right) { return (left._c == right._c); }
  template<class Tn, class ContainerN>
  bool operator!=(const ft::stack<Tn, ContainerN>& left,
                const ft::stack<Tn, ContainerN>& right) { return (left._c != right._c); }
  template<class Tn, class ContainerN>
  bool operator<(const ft::stack<Tn, ContainerN>& left,
                const ft::stack<Tn, ContainerN>& right) { return (left._c < right._c); }
  template<class Tn, class ContainerN>
  bool operator<=(const ft::stack<Tn, ContainerN>& left,
                const ft::stack<Tn, ContainerN>& right) { return (left._c <= right._c); }
  template<class Tn, class ContainerN>
  bool operator>(const ft::stack<Tn, ContainerN>& left,
                const ft::stack<Tn, ContainerN>& right) { return (left._c > right._c); }
  template<class Tn, class ContainerN>
  bool operator>=(const ft::stack<Tn, ContainerN>& left,
                const ft::stack<Tn, ContainerN>& right) { return (left._c >= right._c); }

}

#endif
