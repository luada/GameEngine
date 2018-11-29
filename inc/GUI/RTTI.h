#ifndef __RTTI_H__
#define __RTTI_H__

#include "Prerequest.h"
#include "Diagnostic.h"
#include <typeinfo>
#include <string>

namespace GUI
{

	//VC++ 7.1
	#if COMPILER == COMPILER_MSVC && COMP_VER == 1310
		#define DECLARE_TYPE_NAME(Type) \
		private: \
			struct TypeNameHolder { const std::string& GetClassTypeName() { static std::string type = #Type; return type; } }; \
		public: \
			static const std::string& GetClassTypeName() { TypeNameHolder type; return type.GetClassTypeName(); } \
			/** Get type name as string */ \
			virtual const std::string& GetTypeName() const { return Type::GetClassTypeName(); }
	#else
		#define DECLARE_TYPE_NAME(Type) \
		public: \
			static const std::string& GetClassTypeName() { static std::string type = #Type; return type; } \
			/** Get type name as string */ \
			virtual const std::string& GetTypeName() const { return Type::GetClassTypeName(); } \
			virtual const char* GetModuleName() const { static const char* moduleName = "GUI::"#Type; return moduleName; }
	#endif

	#define RTTI_BASE(BaseType) \
		public: \
			typedef BaseType RTTIBase; \
			DECLARE_TYPE_NAME(BaseType) \
			/** Compare with selected type */ \
			virtual bool IsType(const std::type_info& type) const { return typeid(BaseType) == type; } \
			/** Compare with selected type */ \
			template<typename Type> bool IsType() const { return IsType(typeid( Type )); } \
			/** Try to cast pointer to selected type. \
				@param _throw If true throw exception when casting in wrong type, else return nullptr \
			*/ \
			template<typename Type> Type* CastType(bool _throw = true) \
			{ \
				if (this->IsType<Type>()) return static_cast<Type*>(this); \
				ASSERT(!_throw, "Error cast type '" << this->GetTypeName() << "' to type '" << Type::GetClassTypeName() << "' .") \
				return nullptr; \
			} \
			/** Try to cast pointer to selected type. \
				@param _throw If true throw exception when casting in wrong type, else return nullptr \
			*/ \
			template<typename Type> const Type* CastType(bool _throw = true) const \
			{ \
				if (this->IsType<Type>()) return static_cast<Type*>(this); \
				ASSERT(!_throw, "Error cast type '" << this->GetTypeName() << "' to type '" << Type::GetClassTypeName() << "' .") \
				return nullptr; \
			}

	#define RTTI_DERIVED(DerivedType) \
		public: \
			DECLARE_TYPE_NAME(DerivedType) \
			typedef RTTIBase Base; \
			typedef DerivedType RTTIBase; \
			/** Compare with selected type */ \
			virtual bool IsType(const std::type_info& type) const { return typeid(DerivedType) == type || Base::IsType(type); } \
			/** Compare with selected type */ \
			template<typename Type> bool IsType() const { return IsType(typeid( DerivedType )); }

	//OBSOLETE
	#define RTTI_CHILD_HEADER(DerivedType, BaseType) \
		public: \
			DECLARE_TYPE_NAME(DerivedType) \
			typedef BaseType Base; \
			typedef DerivedType RTTIBase; \
			/** Compare with selected type */ \
			virtual bool IsType(const std::type_info& type) const { return typeid(DerivedType) == type || BaseType::IsType(type); }


	//OBSOLETE
	#define RTTI_BASE_HEADER(BaseType) RTTI_BASE(BaseType)

} // namespace GUI

#endif // __RTTI_H__
