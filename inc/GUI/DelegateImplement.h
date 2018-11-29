namespace delegates
{

	#define COMBINE(a, b)						COMBINE1(a, b)
	#define COMBINE1(a, b)						a##b

	#define I_DELEGATE							COMBINE(IDelegate, SUFFIX)

	#define C_STATIC_DELEGATE					COMBINE(CStaticDelegate, SUFFIX)
	#define C_METHOD_DELEGATE					COMBINE(CMethodDelegate, SUFFIX)

	#define C_DELEGATE							COMBINE(CDelegate, SUFFIX)
	#define C_MULTI_DELEGATE					COMBINE(CMultiDelegate, SUFFIX)


	TEMPLATE   TEMPLATE_PARAMS
	class I_DELEGATE
	{
	public:
		virtual ~I_DELEGATE() { }
		virtual bool IsType(const std::type_info& type) = 0;
		virtual void Invoke(PARAMS) = 0;
		virtual bool Compare(I_DELEGATE TEMPLATE_ARGS  * delegate) const = 0;
		virtual bool Compare(IDelegateUnlink * unlink) const { return false; }
	};


	TEMPLATE   TEMPLATE_PARAMS
	class C_STATIC_DELEGATE : public  I_DELEGATE TEMPLATE_ARGS
	{
	public:
		typedef void (*Func)(PARAMS);

		C_STATIC_DELEGATE (Func func) : mFunc(func) { }

		virtual bool IsType(const std::type_info& type) { return typeid( C_STATIC_DELEGATE TEMPLATE_ARGS ) == type; }

		virtual void Invoke(PARAMS)
		{
			mFunc( ARGS );
		}

		virtual bool Compare(I_DELEGATE TEMPLATE_ARGS  * delegate) const
		{
			if (nullptr == delegate || !delegate->IsType(typeid(C_STATIC_DELEGATE TEMPLATE_ARGS))) return false;
			C_STATIC_DELEGATE TEMPLATE_ARGS * cast = static_cast<C_STATIC_DELEGATE TEMPLATE_ARGS *>(delegate);
			return cast->mFunc == mFunc;
		}
		virtual bool Compare(IDelegateUnlink * unlink) const { return false; }

	private:
		Func mFunc;
	};


	template T_TEMPLATE_PARAMS
	class C_METHOD_DELEGATE : public  I_DELEGATE TEMPLATE_ARGS
	{
	public:
		typedef void (T::*Method)(PARAMS);

		C_METHOD_DELEGATE(IDelegateUnlink * unlink, T * object, Method method) : mUnlink(unlink), mObject(object), mMethod(method) { }

		virtual bool IsType(const std::type_info& type) { return typeid( C_METHOD_DELEGATE T_TEMPLATE_ARGS ) == type; }

		virtual void Invoke(PARAMS)
		{
			(mObject->*mMethod)( ARGS );
		}

		virtual bool Compare(I_DELEGATE TEMPLATE_ARGS  * delegate) const
		{
			if (nullptr == delegate || !delegate->IsType(typeid(C_METHOD_DELEGATE T_TEMPLATE_ARGS))) return false;
			C_METHOD_DELEGATE T_TEMPLATE_ARGS  * cast = static_cast<  C_METHOD_DELEGATE T_TEMPLATE_ARGS  * >(delegate);
			return cast->mObject == mObject && cast->mMethod == mMethod;
		}

		virtual bool Compare(IDelegateUnlink * unlink) const
		{
			return mUnlink == unlink;
		}

	private:
		IDelegateUnlink *mUnlink;
		T * mObject;
		Method mMethod;
	};

} // namespace delegates

TEMPLATE   TEMPLATE_PARAMS
inline  delegates::I_DELEGATE TEMPLATE_ARGS  * NewDelegate(void (*_func)( PARAMS ))
{
	return new delegates::C_STATIC_DELEGATE TEMPLATE_ARGS  (_func);
}


template T_TEMPLATE_PARAMS
inline  delegates::I_DELEGATE TEMPLATE_ARGS  * NewDelegate(T * object, void (T::*_method)( PARAMS ))
{
	return new delegates::C_METHOD_DELEGATE  T_TEMPLATE_ARGS  (delegates::GetDelegateUnlink(object), object, _method);
}

namespace delegates
{
	TEMPLATE   TEMPLATE_PARAMS
	class C_DELEGATE
	{
	public:
		typedef  I_DELEGATE TEMPLATE_ARGS  IDelegate;

		C_DELEGATE () : mDelegate(nullptr) { }
		C_DELEGATE (const C_DELEGATE  TEMPLATE_ARGS& event)
		{
			mDelegate = event.mDelegate;
			const_cast< C_DELEGATE  TEMPLATE_ARGS& >(event).mDelegate = nullptr;
		}
		~C_DELEGATE () { Clear(); }

		bool empty() const { return mDelegate == nullptr; }

		void Clear()
		{
			if (mDelegate)
			{
				delete mDelegate;
				mDelegate = nullptr;
			}
		}

		C_DELEGATE  TEMPLATE_ARGS & operator=(IDelegate* delegate)
		{
			delete mDelegate;
			mDelegate = delegate;
			return *this;
		}

		C_DELEGATE  TEMPLATE_ARGS & operator=(const C_DELEGATE  TEMPLATE_ARGS& event)
		{
			delete mDelegate;
			mDelegate = event.mDelegate;
			const_cast< C_DELEGATE  TEMPLATE_ARGS& >(event).mDelegate = nullptr;

			return *this;
		}

		void operator()(PARAMS)
		{
			if (mDelegate == nullptr) return;
			mDelegate->Invoke( ARGS );
		}

	private:
		IDelegate * mDelegate;
	};


	TEMPLATE   TEMPLATE_PARAMS
	class C_MULTI_DELEGATE
	{
	public:
		typedef  I_DELEGATE TEMPLATE_ARGS  IDelegate;
		typedef TYPENAME std::list<IDelegate* /*, Allocator<IDelegate*>*/ > ListDelegate;
		typedef TYPENAME ListDelegate::iterator ListDelegateIterator;
		typedef TYPENAME ListDelegate::const_iterator ConstListDelegateIterator;

		C_MULTI_DELEGATE () { }
		~C_MULTI_DELEGATE () { Clear(); }

		bool empty() const
		{
		  for (ConstListDelegateIterator iter = mListDelegates.begin(); iter!=mListDelegates.end(); ++iter)
			{
				if (*iter) return false;
			}
			return true;
		}

		void Clear()
		{
			for (ListDelegateIterator iter=mListDelegates.begin(); iter!=mListDelegates.end(); ++iter)
			{
				if (*iter)
				{
					delete (*iter);
					(*iter) = nullptr;
				}
			}
		}

		void Clear(IDelegateUnlink * unlink)
		{
			for (ListDelegateIterator iter=mListDelegates.begin(); iter!=mListDelegates.end(); ++iter)
			{
				if ((*iter) && (*iter)->Compare(unlink))
				{
					delete (*iter);
					(*iter) = nullptr;
				}
			}
		}

		C_MULTI_DELEGATE  TEMPLATE_ARGS & operator+=(IDelegate* delegate)
		{
			for (ListDelegateIterator iter=mListDelegates.begin(); iter!=mListDelegates.end(); ++iter)
			{
				if ((*iter) && (*iter)->Compare(delegate))
				{
					ASSERT(false, "dublicate curDelegate");
				}
			}
			mListDelegates.push_back(delegate);
			return *this;
		}

		C_MULTI_DELEGATE  TEMPLATE_ARGS & operator-=(IDelegate* delegate)
		{
			for (ListDelegateIterator iter=mListDelegates.begin(); iter!=mListDelegates.end(); ++iter)
			{
				if ((*iter) && (*iter)->Compare(delegate))
				{
					if ((*iter) != delegate) delete (*iter);
					(*iter) = nullptr;
					break;
				}
			}
			delete delegate;
			return *this;
		}

		void operator()(PARAMS)
		{
			ListDelegateIterator iter = mListDelegates.begin();
			while (iter != mListDelegates.end())
			{
				if (nullptr == (*iter))
				{
					iter = mListDelegates.erase(iter);
				}
				else
				{
					(*iter)->Invoke( ARGS );
					++iter;
				}
			}
		}

	private:
		// constructor and operator =, without implementation, just for private
		C_MULTI_DELEGATE (const C_MULTI_DELEGATE  TEMPLATE_ARGS & event);
		C_MULTI_DELEGATE  TEMPLATE_ARGS & operator=(const C_MULTI_DELEGATE  TEMPLATE_ARGS & event);


	private:
		ListDelegate mListDelegates;

	};


	#undef COMBINE
	#undef COMBINE1

	#undef I_DELEGATE

	#undef C_STATIC_DELEGATE
	#undef C_METHOD_DELEGATE

	#undef C_DELEGATE
	#undef C_MULTI_DELEGATE

	#undef SUFFIX
	#undef TEMPLATE
	#undef TEMPLATE_PARAMS
	#undef TEMPLATE_ARGS
	#undef T_TEMPLATE_PARAMS
	#undef T_TEMPLATE_ARGS
	#undef PARAMS
	#undef ARGS
	#undef TYPENAME

} // namespace delegates
