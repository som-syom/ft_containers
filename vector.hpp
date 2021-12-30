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
    typedef T                                         value_type;
    typedef Alloc                                     allocator_type;
    typedef typename allocator_type::pointer          pointer;
    typedef typename allocator_type::const_pointer    const_pointer;
    typedef typename allocator_type::reference        reference;
    typedef typename allocator_type::const_reference  const_reference;
    typedef typename allocator_type::size_type        size_type;

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

      ~vector() {
        this->clear();
        _alloc.deallocate(_start, this->capacity());
      }
      // vector(vector const& v)
      //   : _alloc(v._alloc), _start(v._start),
      //   _end(v._end), _end_capacity(v._end_capacity)
      // {
      //   //insert
      // }
      // vector& operator=(vector const&);

      /* ======================== */
      //  Iterators
      /* ======================== */ 

      /* ======================== */
      //  Capacity
      /* ======================== */ 
      size_type size() const { return (this->_end - this->_start); }

      size_type max_size() const { return (this->_alloc.max_size()); }

      void resize(size_type n, value_type& val = value_type())
      {
        if (this->max_size() < n) { // max_size 보다 큰 값이 들어올 때
          throw (std::length_error("vector::resize"));
        } else if (this->size() < n) { // 원래 사이즈보다 작게 바꾸려고 할 때
          while (this->size() > n) {
            --_end;
            _alloc.destory(_end);
          }
        } else {
          // insert 추가
          ;
        }
      }

      size_type capacity() const { return (this->_end_capacity - this->_start); }

      bool empty() const { return this->size() == 0 ? true : false; }

      void reserve(size_type n) {
        if (this->max_size() < n) {
          throw (std::length_error("vector::reserve"));
        } else if (this->capacity() < n) {
          pointer old_start = _start;
          pointer old_end = _end;
          size_type old_size = this->size();
          size_type old_capacity = this->capacity();

          _start = _alloc.allocate(n);
          _end_capacity = _start + n;
          _end = _start;
          while (old_start != old_end) {
            _alloc.construct(_end, *old_start);
            _end++;
            old_start++;
          }
          _alloc.deallocate(old_start - old_size, old_capacity);
        }
      }

      /* ======================== */
      //  Element access
      /* ======================== */ 
      reference       operator[](size_type n) { return (*(_start + n)); }

      const reference operator[](size_type n) const { return (*(_start + n)); }

      reference       at(size_type n) {
        if (n > this->size() || n < 0) {
          throw (std::out_of_range("vector::at"));
        } 
        return (*(_start + n));
      }

      const reference at(size_type n) const {
        if (n > this->size() || n < 0) {
          throw (std::out_of_range("vector::at"));
        } 
        return (*(_start + n));
      }

      reference       front() { return (*(_start)); }

      const reference front() const { return (*(_start)); }

      reference       back() { return (*(_end - 1)); }
      const reference back() const { return (*(_end - 1)); }


      /* ======================== */
      //  Modifiers
      /* ======================== */
      // assign

      void push_back(const value_type& val) {
        if (_end == _end_capacity) {
          size_type new_capacity = (this->size() == 0) ? 1 : this->size() * 2;
          this->reserve(new_capacity);
        }
        _alloc.construct(_end, val);
        _end++;
      }

      void pop_back() {
        _alloc.destroy(_end);
        _end--;
      }
      // insert
      // erase
      void swap(ft::vector& x) {
        if (x == *this) return ;

        pointer save_start = x._start;
        pointer save_end = x._end;
        pointer save_end_capacity = x._end_capacity;
        allocator_type save_alloc = x._alloc;

        x._start = this->_start;
        x._end = this->_end;
        x._end_capacity = this->_end_capacity;
        x._alloc = this->_alloc;

        this->_start = save_start;
        this->_end = save_end;
        this->_end_capacity = save_end_capacity;
        this->_alloc = save_alloc;
      }

      void clear() {
        size_type s = this->size();
        for (size_type i = 0; i < s; i++) {
          _end--;
          _alloc.destroy(_end);
        }
      }

      /* ======================== */
      //  Allocator
      /* ======================== */
      allocator_type get_allocator() const { return (_alloc); }
  };
}

#endif
