#ifndef __RESOURCE_HOLDER_H__
#define __RESOURCE_HOLDER_H__

#include "Prerequest.h"
#include "Enumerator.h"

namespace GUI
{

	template <typename Type>
	class /*GUI_EXPORT */ResourceHolder
	{
	public:
		typedef std::map<std::string, Type*> MapResource;
		typedef Enumerator<MapResource> EnumeratorPtr;

		virtual ~ResourceHolder() { }
	public:
		/** Check is resource exist */
		bool IsExist(const std::string& name) const
		{
			return mResources.find(name) != mResources.end();
		}

		/** Find resource by name*/
		Type* findByName(const std::string& name) const
		{
			typename MapResource::const_iterator item = mResources.find(name);
			return (item == mResources.end()) ? nullptr : item->second;
		}

		/** Get resource by name*/
		Type* GetByName(const std::string& name, bool _throw = true) const
		{
			Type* result = findByName(name);
			ASSERT(result || !_throw, "Resource '" << name << "' not found");
			return result;
		}

		bool Remove(const std::string& name)
		{
			typename MapResource::const_iterator item = mResources.find(name);
			if (item != mResources.end())
			{
				delete item->second;
				mResources.erase(item->first);
				return true;
			}
			return false;
		}

		void Clear()
		{
			for (typename MapResource::iterator item=mResources.begin(); item!=mResources.end(); ++item)
			{
				delete item->second;
			}
			mResources.clear();
		}

		EnumeratorPtr GetEnumerator()
		{
			return EnumeratorPtr(mResources);
		}

		size_t GetCount() const { return mResources.size(); }

	protected:
		MapResource mResources;
	};

} // namespace GUI

#endif // __RESOURCE_HOLDER_H__
