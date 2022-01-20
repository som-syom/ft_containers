#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
# include "./utils.hpp"
# include "./binary_search_tree.hpp"
# include "./binary_search_tree_iterator.hpp"

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
                  <typename ft::iterator_traits<InputIterator>::iterator_category>::type>());
          this->insert(first,last);
      }

      // copy constructor
      map(const map& x) : _alloc(x._alloc), _comp(x._comp), _bst() {
        const_iterator test = x.begin();
        const_iterator test2 = x.end();
        int i = 0;
        while (test != test2) {
          i++;
          test++;
        }
        this->insert(x.begin(), x.end());
      }

      // assign
      map& operator=(const map& x) {
        if (&x == this) return (*this);
        this->clear();
        this->insert(x.begin(), x.end());
        return (*this);
      }

      // destructor
      ~map() {
        this-> clear();
      }

      /* ======================== */
      //  Iterator
      /* ======================== */

      iterator begin() {
        return (iterator(_bst._last_node->left, _bst._last_node));
      }
      const_iterator begin() const {
        return (const_iterator(_bst._last_node->left, _bst._last_node));
      }

      iterator end() {
        return (iterator(_bst._last_node, _bst._last_node));
      }
      const_iterator end() const {
        return (const_iterator(_bst._last_node, _bst._last_node));
      }

      reverse_iterator rbegin() {
        return (reverse_iterator(this->end()));
      }
      const_reverse_iterator rbegin() const {
        return (const_reverse_iterator(this->end()));
      }

      reverse_iterator rend() {
        return (reverse_iterator(this->begin()));
      }

      const_reverse_iterator rend() const {
        return (const_reverse_iterator(this->begin()));
      }

      /* ======================== */
      //  Capacity
      /* ======================== */

      // empty
      bool empty() const {
        return (_bst._last_node->parent == _bst._last_node);
      }
      // size
      size_type size() const {
        return (_bst._size);
      }
      // max_size
      size_type max_size() const {
        return (_bst.max_size());
      }

      /* ======================== */
      //  Element access
      /* ======================== */

      // operator[]
      mapped_type& operator[](const key_type& k) {
        iterator tmp = this->find(k);

        if (tmp == this->end())
          this->insert(ft::make_pair(k, mapped_type()));
        tmp = this->find(k);
        return ((*tmp).second);
      }

      /* ======================== */
      //  Modifiers
      /* ======================== */

      // insert
      pair<iterator, bool> insert(const value_type& val) {
        return (_bst.insertPair(val));
      }

      iterator insert(iterator position, const value_type& val) {
        (void)position;
        return (_bst.insertPair(val).first);
      }

      template<class InputIterator>
      void insert(InputIterator first, InputIterator last,
              typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = m_nullptr) {
        bool is_valid;
        if (!(is_valid = ft::is_input_iterator_tagged
            <typename ft::iterator_traits<InputIterator>::iterator_category>::value))
          throw (ft::InvalidIteratorException
            <typename ft::is_input_iterator_tagged
            <typename ft::iterator_traits<InputIterator>::iterator_category>::type>());
        
        difference_type n = ft::distance(first, last);
        while (n--) {
          this->insert(*(first));
          first++;
        }
      }

      // erase
      void erase(iterator position) {
        this->erase((*position).first);
      }

      size_type erase(const key_type& k) {
        if (this->find(k) == this->end())
          return (0);
        _bst.removeByKey(ft::make_pair(k, mapped_type()));
        return (1);
      }

      void erase(iterator first, iterator last) {
        while (first != last)
          this->erase((*(first++)).first);
      }


      // swap
      void swap(map& x) {
        _bst.swap(x._bst);
      }
      // clear
      void clear() {
        this->erase(this->begin(), this->end());
      }

      /* ======================== */
      //  Observers
      /* ======================== */

      // key_comp
      key_compare key_comp() const {
        return (key_compare());
      }
      // value_comp
      value_compare value_comp() const {
        return (value_compare(key_compare()));
      }

      /* ======================== */
      //  Operations
      /* ======================== */

      // find
      iterator find(const key_type& k) {
        return (iterator(_bst.searchByKey(ft::make_pair(k, mapped_type())), _bst._last_node));
      }

      const_iterator find(const key_type& k) const {
        return (const_iterator(_bst.searchByKey(ft::make_pair(k, mapped_type())), _bst._last_node));
      }
      // count
      size_type count(const key_type& k) const {
        const_iterator beg = this->begin();
        const_iterator end = this->end();

        while (beg != end) {
          if ((*(beg++)).first == k)
            return (1);
        }
        return (0);
      }

      // lower_bound
      iterator lower_bound(const key_type& k) {
        iterator beg = this->begin();
        iterator end = this->end();

        while (beg != end) {
          if (_comp((*beg).first, k) == false)
            break;
          beg++;
        }
        return (beg);
      }
      const_iterator lower_bound(const key_type& k) const {
        return (const_iterator(this->lower_bound(k)));
      }
      // upper_bound
      iterator upper_bound(const key_type& k) {
        iterator beg = this->begin();
        iterator end = this->end();

        while (beg != end) {
          if (_comp(k, (*beg).first))
            break ;
          beg++;
        }
        return (beg);
      }
      const_iterator upper_bound(const key_type& k) const {
        return (const_iterator(this->upper_bound(k)));
      }
      // equal_range
      pair<const_iterator, const_iterator> equal_range(const key_type& k) const {
        return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
      }

      pair<iterator, iterator> equal_range(const key_type& k) {
        return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
      }


      /* ======================== */
      //  Allocator
      /* ======================== */

      // get_allocator
      allocator_type get_allocator() const {
        return(this->_alloc);
      }

    private:
      allocator_type                          _alloc;
      Compare                                 _comp;
      Binary_search_tree<value_type, Compare> _bst;



  };
}

#endif
