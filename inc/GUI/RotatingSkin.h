#ifndef __ROTATING_SKIN_H__
#define __ROTATING_SKIN_H__

#include "Prerequest.h"
#include "XmlDocument.h"
#include "Types.h"
#include "ICroppedRectangle.h"
#include "SubSkin.h"

namespace GUI
{

	class GUI_EXPORT RotatingSkin : public SubSkin
	{
		RTTI_DERIVED(RotatingSkin)

	public:
		RotatingSkin();
		virtual ~RotatingSkin();

		/** Set angle of rotation */
		void SetAngle(float angle);
		/** Get angle of rotation */
		float GetAngle() const { return mAngle; }

		/** Set center of rotation
			@param _center Center point.
			@param _local If true - _center point calculated as point on SubWidget, else calculated as point on screen.
		*/
		void SetCenter(const IntPoint &_center, bool local = true);
		/** Get center of rotation */
		IntPoint GetCenter(bool local = true) const;

		virtual void DoRender();

	protected:
		void RecalculateAngles();

	private:
		float mAngle;
		IntPoint mCenterPos;
		bool mLocalCenter;

		/*
			0 3
			1 2
		*/
		float mBaseAngles[4];
		float mBaseDistances[4];
	};

} // namespace GUI

#endif // __ROTATING_SKIN_H__

