#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>

namespace ft
{
  template< typename T, typename Alloc = std::allocator<T> >
  class Vector
  {
    typedef T                                 value_type;
    typedef Alloc                             allocator_type;
    typedef typename allocator_type::pointer  pointer;

    private:
      allocator_type    _alloc;
      pointer           _start;
      pointer           _end;
      pointer           _end_capacity;

    public:
      Vector(const allocator_type& alloc = allocator_type())
      : _alloc(alloc), _start(u_nullptr), _end(u_nullptr), _end_capacity(u_nullptr) {}
      virtual ~Vector();
      Vector(Vector const&);
      Vector& operator=(Vector const&);

      // iterators

      // capacity
      int size() const;
      int max_size() const;
      void resize(int n, T val);
      int capacity() const;
      bool empty() const;
      void reserve(int n);


  };
}

#endif
