#ifndef __INSTANCE_H__
#define __INSTANCE_H__

#define INSTANCE_HEADER(type) \
	private: \
		static type* msInstance; \
		bool mIsInitialise; \
	public: \
		type();\
		~type();\
		static type& GetInstance(); \
		static type* GetInstancePtr();


#define INSTANCE_IMPLEMENT(type) \
	const std::string INSTANCE_TYPE_NAME(#type); \
	type* type::msInstance = nullptr; \
	type* type::GetInstancePtr() { return msInstance; } \
	type& type::GetInstance() { ASSERT(0 != msInstance, "instance " << INSTANCE_TYPE_NAME << " was not created"); return (*msInstance); } \
	type::type() : mIsInitialise(false) { ASSERT(0 == msInstance, "instance " << INSTANCE_TYPE_NAME << " is exsist"); msInstance = this; } \
	type::~type() { msInstance = nullptr; }

#endif // __INSTANCE_H__
