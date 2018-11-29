#ifndef __CONTROLLER_FADE_ALPHA_H__
#define __CONTROLLER_FADE_ALPHA_H__

#include "Prerequest.h"
#include "WidgetDefines.h"
#include "ControllerItem.h"

namespace GUI
{

	/** This controller used for smooth changing alpha of widget in time */
	class GUI_EXPORT ControllerFadeAlpha :
		public ControllerItem
	{
		RTTI_DERIVED(ControllerFadeAlpha)

	public:
		ControllerFadeAlpha();
		virtual ~ControllerFadeAlpha() { }

		/**
			@param _alpha that will be as result of changing
		*/
		void SetAlpha(float value) { mAlpha = value; }

		/**
			@param _coef of alpha changing Speed (1. mean that alpha will change from 0 to 1 at 1 second)
		*/
		void SetCoef(float value) { mCoef = value; }

		/**
			@param _enabled if true then widget will be inactive after start of alpha changing
		*/
		void SetEnabled(bool value) { mEnabled = value; }


		virtual void SetProperty(const std::string& key, const std::string& value);

	private:
		bool AddTime(Widget* widget, float time);
		void PrepareItem(Widget* widget);

		bool GetEnabled() { return mEnabled; }
		float GetAlpha() { return mAlpha; }
		float GetCoef() { return mCoef; }

	private:
		float mAlpha;
		float mCoef;
		bool mEnabled;

	};

}

#endif // __CONTROLLER_FADE_ALPHA_H__
