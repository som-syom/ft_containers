#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
# include "./utils.hpp"

namespace ft {
  template<class Key, class T, class Compare = ft::less<Key>,
          class Alloc = std::allocator<ft::pair<const Key, T> > >
  class map {
    public:
      typedef Key                               key_type;
      typedef T                                 mapped_type;
      typedef ft::pair<key_type, mapped_type>   value_type;
      typedef Compare                           key_compare;

      class value_compare : ft::binary_function<value_type, value_type, bool> {
        friend class map<key_type, mapped_type, key_compare, Alloc>;

        protected:
          Compare comp;
          value_compare (Compare c) : comp(c) {}

        public:
          bool operator()(const value_type& x, const value_type& y) const {
            return (comp(x.first, y.first));
          }
      };

      typedef Alloc                                                   allocator_type;
      typedef typename allocator_type::reference                      reference;
      typedef typename allocator_type::const_reference                const_reference;
      typedef typename allocator_type::pointer                        pointer;
      typedef typename allocator_type::const_pointer                  const_pointer;
      typedef typename ft::Binary_search_tree<value_type, key_compare>::iterator  iterator;
      typedef typename ft::Binary_search_tree<value_type, key_compare>::const_iterator  const_iterator;
      typedef typename ft::reverse_iterator<iterator>                 reverse_iterator;
      typedef typename ft::reverse_iterator<const_iterator>           const_reverse_iterator;
      typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
      typedef size_t                                                  size_type;

      // default constructor
      explicit map(const key_compare& comp = key_compare(),
                  const allocator_type& alloc = allocator_type())
        : _alloc(alloc), _comp(comp), _bst() {}

      // range constructor
      template<class InputIterator>
      map(InputIterator first, InputIterator last,
          const key_compare& comp = key_compare(),
          const allocator_type& alloc = allocator_type(),
          typename ft::enable_if<!ft::is_integral
          <InputIterator>::value, InputIterator>::type* = m_nullptr)
        : _alloc(alloc), _comp(comp), _bst()
      {
          bool is_valid;
          if (!(is_valid = ft::is_input_iterator_tagged
                  <typename ft::iterator_traits<InputIterator>::iterator_category>::value))
            throw (ft::InvalidIteratorException
                  <typename ft::is_input_iterator_tagged
                  <typename ft::iterator_traits<InputIterator>::iterator_category>::type());
          // this->insert(first,last);
      }

      // copy constructor
      map(const map& x) : _alloc(x._alloc), _comp(x._comp), _bst() {
        // this->insert(x.begin(), x.end());
      }

      // assign
      map& operator=(const map& x) {
        if (&x == this) return (*this);
        // this->clear();
        // this->insert(x.begin(), x.end());
        return (*this);
      }

      // destructor
      ~map() {
        // this-> clear();
      }

      /* ======================== */
      //  Iterator
      /* ======================== */ 

      iterator begin() {
        return (iterator(_bst.last_node->left, _bst._last_node));
      }

      const_iterator begin() const {
        return (const_iterator(_bst.last_node->left, _bst._last_node));
      }

  };
}

#endif
