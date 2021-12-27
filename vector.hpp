#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include "./utils.hpp"

namespace ft
{
  template< typename T, typename Alloc = std::allocator<T> >
  class vector
  {
    typedef T                                   value_type;
    typedef Alloc                               allocator_type;
    typedef typename allocator_type::pointer    pointer;
    typedef typename allocator_type::size_type  size_type;

    private:
      allocator_type    _alloc;
      pointer           _start;
      pointer           _end;
      pointer           _end_capacity;

    public:
      vector(const allocator_type& alloc = allocator_type())
        : _alloc(alloc), _start(m_nullptr), 
        _end(m_nullptr), _end_capacity(m_nullptr)
      {}

      vector(size_type size, const value_type& val = value_type(),
      const allocator_type& alloc = allocator_type())
        : _alloc(alloc), _start(m_nullptr),
        _end(m_nullptr), _end_capacity(m_nullptr)
      {
        _start = _alloc.allocate(size);
        _end_capacity = _start + size;
        _end = _start;
        while (size--)
        {
          _alloc.construct(_end, val);
          _end++;
        }
      }

      // virtual ~vector();
      // vector(vector const&);
      // vector& operator=(vector const&);

      // iterators

      // capacity
      size_type size() const { return (this->_end - this->_start); }
      size_type max_size() const { return (this->_alloc.max_size()); }
      void resize(size_type n, value_type& val = value_type());
      size_type capacity() const { return (this->_end_capacity - this->_start); }
      // bool empty() const;
      // void reserve(size_type n);


  };
}

#endif
