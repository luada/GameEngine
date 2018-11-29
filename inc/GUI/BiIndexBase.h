#ifndef __BIINDEX_BASE_H__
#define __BIINDEX_BASE_H__

#include "Prerequest.h"

namespace GUI
{

	class BiIndexBase
	{
	public:
		virtual ~BiIndexBase() { }
	protected:

		size_t GetIndexCount() { return mIndexFace.size(); }

		size_t InsertItemAt(size_t index)
		{
			#if DEBUG_MODE == 1
				ASSERT_RANGE_INSERT(index, mIndexFace.size(), "BiIndexBase::insertItemAt");
				CheckIndexes();
			#endif

			if (index == GUI::ITEM_NONE) index = mIndexFace.size();

			size_t curIndex;

			if (index == mIndexFace.size())
			{
				curIndex = mIndexFace.size();

				mIndexFace.push_back(index);
				mIndexBack.push_back(index);
			}
			else
			{
				curIndex = mIndexFace[index];

				size_t count = mIndexFace.size();
				for (size_t pos=0; pos<count; ++pos)
				{
					if (mIndexFace[pos] >= curIndex) mIndexFace[pos]++;
				}
				mIndexFace.insert(mIndexFace.begin() + index, curIndex);

				count ++;
				mIndexBack.push_back(0);
				for (size_t pos=0; pos<count; ++pos)
				{
					mIndexBack[mIndexFace[pos]] = pos;
				}
			}

			#if DEBUG_MODE == 1
				CheckIndexes();
			#endif

			return curIndex;
		}

		size_t RemoveItemAt(size_t index)
		{
			#if DEBUG_MODE == 1
				ASSERT_RANGE(index, mIndexFace.size(), "BiIndexBase::removeItemAt");
				CheckIndexes();
			#endif

			size_t curIndex = mIndexFace[index];

			mIndexFace.erase(mIndexFace.begin() + index);
			mIndexBack.pop_back();

			size_t count = mIndexFace.size();
			for (size_t pos=0; pos<count; ++pos)
			{
				if (mIndexFace[pos] > curIndex) mIndexFace[pos]--;
				mIndexBack[mIndexFace[pos]] = pos;
			}

			#if DEBUG_MODE == 1
				CheckIndexes();
			#endif

			return curIndex;
		}

		void RemoveAllItems()
		{
			mIndexFace.clear();
			mIndexBack.clear();
		}

		size_t ConvertToBack(size_t index) const
		{
			#if DEBUG_MODE == 1
				ASSERT_RANGE_AND_NONE(index, mIndexFace.size(), "BiIndexBase::convertToBack");
			#endif
			return index == ITEM_NONE ? ITEM_NONE : mIndexFace[index];
		}

		size_t ConvertToFace(size_t index) const
		{
			#if DEBUG_MODE == 1
				ASSERT_RANGE_AND_NONE(index, mIndexFace.size(), "BiIndexBase::convertToFace");
			#endif
			return index == ITEM_NONE ? ITEM_NONE : mIndexBack[index];
		}

		void SwapItemsFaceAt(size_t index1, size_t index2)
		{
			#if DEBUG_MODE == 1
				ASSERT_RANGE(index1, mIndexFace.size(), "BiIndexBase::swapItemsFaceAt");
				ASSERT_RANGE(index2, mIndexFace.size(), "BiIndexBase::swapItemsFaceAt");
			#endif

			std::swap(mIndexFace[index1], mIndexFace[index2]);
			std::swap(mIndexBack[mIndexFace[index1]], mIndexBack[mIndexFace[index2]]);
		}

		void SwapItemsBackAt(size_t index1, size_t index2)
		{
			#if DEBUG_MODE == 1
				ASSERT_RANGE(index1, mIndexFace.size(), "BiIndexBase::swapItemsBackAt");
				ASSERT_RANGE(index2, mIndexFace.size(), "BiIndexBase::swapItemsBackAt");
			#endif

			std::swap(mIndexBack[index1], mIndexBack[index2]);
			std::swap(mIndexFace[mIndexBack[index1]], mIndexFace[mIndexBack[index2]]);
		}

		#if DEBUG_MODE == 1

		void CheckIndexes()
		{
			assert(mIndexFace.size() == mIndexBack.size());

			std::vector<bool> vec;
			size_t count = mIndexFace.size();

			vec.reserve(count);
			for (size_t pos=0; pos<count; ++pos) vec.push_back(false);

			for (size_t pos=0; pos<count; ++pos)
			{
				size_t index = mIndexBack[pos];
				if (index >= count) throw new std::exception();

				index = mIndexFace[pos];
				if (index >= count) throw new std::exception();

				if (vec[index]) throw new std::exception();
				vec[index] = true;
			}

			for (size_t pos=0; pos<count; ++pos)
			{
				if (!vec[pos]) throw new std::exception();
			}

			for (size_t pos=0; pos<count; ++pos)
			{
				size_t index = mIndexFace[pos];
				if (mIndexBack[index] != pos) throw new std::exception();
			}
		}

		#endif

	private:
		typedef std::vector<size_t> VectorSizeT;

		VectorSizeT mIndexFace;

		VectorSizeT mIndexBack;
	};

} // namespace GUI

#endif // __BIINDEX_BASE_H__

