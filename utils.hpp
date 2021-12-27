#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <cstddef>
# include <typeinfo>

static class
{
		public:
			template<class T>
			operator T*() const { return (0);}

			template<class T, class C>
			operator T C::*() const { return (0);}
		private:
			void operator&() const;
} m_nullptr = {};

#endif