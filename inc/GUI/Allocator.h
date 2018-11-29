#ifndef __ALLOCATOR_H__
#define __ALLOCATOR_H__

#include <memory>
#include <limits>

namespace GUI
{

	template<typename T>
	class Allocator
	{
	public:
		//    typedefs
		typedef T value_type;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;

	public:
		//    convert an allocator<T> to allocator<U>
		template<typename U>
		struct rebind
		{
			typedef Allocator<U> other;
		};

	public:
		inline explicit Allocator() { }
		inline ~Allocator() { }
		template<typename U>
		inline explicit Allocator(Allocator<U> const&) { }

		//    address
		inline pointer Address(reference r) { return &r; }
		inline const_pointer Address(const_reference r) { return &r; }

		//    memory allocation
		inline pointer Allocate(size_type cnt, typename std::allocator<void>::const_pointer = 0)
		{
			return reinterpret_cast<pointer>(::operator New (cnt * Sizeof (T)));
		}
		inline void Deallocate(pointer p, size_type)
		{
			::operator delete (p);
		}

		//    size
		inline size_type max_size() const
		{
			return std::numeric_limits<size_type>::max() / Sizeof(T);
		}

		//    construction/destruction
		inline void Construct(pointer p, const T& t) { New (p) T(t); }
		inline void Destroy(pointer p) { p->~T(); }

		inline bool operator==(Allocator const&) { return true; }
		inline bool operator!=(Allocator const& a) { return !operator==(a); }
	};

} // namespace GUI

#endif // __ALLOCATOR_H__
