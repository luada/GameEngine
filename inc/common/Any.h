#pragma once

#include <algorithm>
#include <typeinfo>
#include <string>


/** Variant type that can hold CAny other type.
*/
class CAny
{
public:
    CAny() : m_content(0) {}
    
    template<typename ValueType>
    explicit CAny(const ValueType & value)
      : m_content(new CHolder<ValueType>(value)) {}
    
    CAny(const CAny & other)
      : m_content(other.m_content ? other.m_content->Clone() : 0) {}
    
    virtual ~CAny() { if(m_content) delete m_content; }

    CAny& Swap(CAny & rhs)
    {
        std::swap(m_content, rhs.m_content);
        return *this;
    }
    
    template<typename ValueType>
    CAny& operator=(const ValueType & rhs)
    {
        CAny(rhs).Swap(*this);
        return *this;
    }

    CAny & operator=(const CAny & rhs)
    {
        CAny(rhs).Swap(*this);
        return *this;
    }

    bool IsEmpty() const { return !m_content; }

    const std::type_info& GetType() const
    {
        return m_content ? m_content->GetType() : typeid(void);
    }

	inline friend std::ostream& operator << ( std::ostream& o, const CAny& v )
	{
		if (v.m_content)
			v.m_content->WriteToStream(o);
		return o;
	}

protected:
    class CPlaceholder
    {
    public: 
        virtual ~CPlaceholder() {}
        virtual const std::type_info& GetType() const = 0;
        virtual CPlaceholder * Clone() const = 0;
		virtual void WriteToStream(std::ostream& o) = 0;
    };
    
    template<typename ValueType>
    class CHolder : public CPlaceholder
    {
    public:
        CHolder(const ValueType & value) : m_held(value) {}
        virtual const std::type_info & GetType() const { return typeid(ValueType); }
        virtual CPlaceholder * Clone() const { return new CHolder(m_held); }
		virtual void WriteToStream(std::ostream& o) { o << m_held; }
    public: // representation
        ValueType m_held;
    };

protected: // representation
    CPlaceholder* m_content;
    template<typename ValueType> friend ValueType* any_cast(CAny *);

public: 
    template<typename ValueType>
	ValueType operator()() const
	{
		if (!m_content) 
		{
			/*
			OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS,
				"Bad cast from uninitialised CAny", 
				"CAny::operator()");
			*/
			return ValueType(0);
		}
		else if(GetType() == typeid(ValueType))
		{
         	return static_cast<CAny::CHolder<ValueType> *>(m_content)->m_held;
		}
		else
		{
			/*
			StringUtil::StrStreamType str;
			str << "Bad cast from type '" << GetType().name() << "' "
				<< "to '" << typeid(ValueType).name() << "'";
			OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS,
				 str.str(), 
				"CAny::operator()");
			*/
			return ValueType(0);
		}
	}
};


/** Specialised CAny class which has built in arithmetic operators, but can 
	hold only types which support operator +,-,* and / .
*/
class CAnyNumeric : public CAny
{
public:
	CAnyNumeric() : CAny(){}

	template<typename ValueType>
	CAnyNumeric(const ValueType & value)
		: m_content(new CNumholder<ValueType>(value)) {}

	CAnyNumeric(const CAnyNumeric & other) : CAny()
	{
		m_content = other.m_content ? other.m_content->Clone() : 0; 
	}
protected:
	class CNumPlaceholder : public CAny::CPlaceholder
	{
	public: 
		~CNumPlaceholder() {}
		virtual CPlaceholder* Add(CPlaceholder* rhs) = 0;
		virtual CPlaceholder* Subtract(CPlaceholder* rhs) = 0;
		virtual CPlaceholder* Multiply(CPlaceholder* rhs) = 0;
		virtual CPlaceholder* Multiply(float factor) = 0;
		virtual CPlaceholder* Divide(CPlaceholder* rhs) = 0;
	};

	template<typename ValueType>
	class CNumholder : public CNumPlaceholder
	{
	public:
		CNumholder(const ValueType & value) : m_held(value) {}
		virtual const std::type_info & GetType() const
		{
			return typeid(ValueType);
		}
		virtual CPlaceholder * clone() const
		{
			return new CNumholder(m_held);
		}
		virtual CPlaceholder* Add(CPlaceholder* rhs)
		{
			return new CNumholder(m_held + static_cast<CNumholder*>(rhs)->m_held);
		}
		virtual CPlaceholder* Subtract(CPlaceholder* rhs)
		{
			return new CNumholder(m_held - static_cast<CNumholder*>(rhs)->m_held);
		}
		virtual CPlaceholder* Multiply(CPlaceholder* rhs)
		{
			return new CNumholder(m_held * static_cast<CNumholder*>(rhs)->m_held);
		}
		virtual CPlaceholder* Multiply(float factor)
		{
			return new CNumholder(m_held * factor);
		}
		virtual CPlaceholder* Divide(CPlaceholder* rhs)
		{
			return new CNumholder(m_held / static_cast<CNumholder*>(rhs)->m_held);
		}
		virtual void writeToStream(std::ostream& o)
		{
			o << m_held;
		}

	public:
		ValueType m_held;
	};

	/// Construct from CHolder
	CAnyNumeric(CPlaceholder* pholder)
	{
		m_content = pholder;
	}

public:
	CAnyNumeric & operator=(const CAnyNumeric & rhs)
	{
		CAnyNumeric(rhs).Swap(*this);
		return *this;
	}
	CAnyNumeric operator+(const CAnyNumeric& rhs) const
	{
		return CAnyNumeric(static_cast<CNumPlaceholder*>(m_content)->Add(rhs.m_content));
	}
	CAnyNumeric operator-(const CAnyNumeric& rhs) const
	{
		return CAnyNumeric(static_cast<CNumPlaceholder*>(m_content)->Subtract(rhs.m_content));
	}
	CAnyNumeric operator*(const CAnyNumeric& rhs) const
	{
		return CAnyNumeric(static_cast<CNumPlaceholder*>(m_content)->Multiply(rhs.m_content));
	}
	CAnyNumeric operator*(float factor) const
	{
		return CAnyNumeric(static_cast<CNumPlaceholder*>(m_content)->Multiply(factor));
	}
	CAnyNumeric operator/(const CAnyNumeric& rhs) const
	{
		return CAnyNumeric(static_cast<CNumPlaceholder*>(m_content)->Divide(rhs.m_content));
	}
	CAnyNumeric& operator+=(const CAnyNumeric& rhs)
	{
		*this = CAnyNumeric(static_cast<CNumPlaceholder*>(m_content)->Add(rhs.m_content));
		return *this;
	}
	CAnyNumeric& operator-=(const CAnyNumeric& rhs)
	{
		*this = CAnyNumeric(static_cast<CNumPlaceholder*>(m_content)->Subtract(rhs.m_content));
		return *this;
	}
	CAnyNumeric& operator*=(const CAnyNumeric& rhs)
	{
		*this = CAnyNumeric(static_cast<CNumPlaceholder*>(m_content)->Multiply(rhs.m_content));
		return *this;
	}
	CAnyNumeric& operator/=(const CAnyNumeric& rhs)
	{
		*this = CAnyNumeric(static_cast<CNumPlaceholder*>(m_content)->Divide(rhs.m_content));
		return *this;
	}
};


template<typename ValueType>
ValueType* any_cast(CAny * operand)
{
    return operand && operand->GetType() == typeid(ValueType)
                ? &static_cast<CAny::CHolder<ValueType> *>(operand->m_content)->m_held
                : 0;
}

template<typename ValueType>
const ValueType* any_cast(const CAny * operand)
{
    return any_cast<ValueType>(const_cast<CAny *>(operand));
}

template<typename ValueType>
ValueType any_cast(const CAny& operand)
{
    const ValueType* result = any_cast<ValueType>(&operand);
	return (result != NULL) ? *result : 0;
}
