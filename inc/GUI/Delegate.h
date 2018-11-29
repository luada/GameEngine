#ifndef __DELEGATE_H__
#define __DELEGATE_H__

#include "Diagnostic.h"
#include <typeinfo>
#include <list>

// source
// http://rsdn.ru/article/cpp/delegates.xml

namespace GUI
{

	namespace delegates
	{
		class GUI_EXPORT IDelegateUnlink
		{
		public:
			virtual ~IDelegateUnlink() { }

			IDelegateUnlink() { m_baseDelegateUnlink = this; }
			bool Compare(IDelegateUnlink * unlink) const { return m_baseDelegateUnlink == unlink->m_baseDelegateUnlink; }

		private:
			IDelegateUnlink * m_baseDelegateUnlink;
		};

		inline IDelegateUnlink * GetDelegateUnlink(void * base) { return 0; }
		inline IDelegateUnlink * GetDelegateUnlink(IDelegateUnlink * base) { return base; }
	}

	#define SUFFIX       0
	#define TEMPLATE
	#define TEMPLATE_PARAMS
	#define TEMPLATE_ARGS
	#define T_TEMPLATE_PARAMS  <typename T>
	#define T_TEMPLATE_ARGS <T>
	#define PARAMS
	#define ARGS
	#define TYPENAME

	#include "DelegateImplement.h"

	#define SUFFIX       1
	#define TEMPLATE	template
	#define TEMPLATE_PARAMS  <typename TP1>
	#define TEMPLATE_ARGS    <TP1>
	#define T_TEMPLATE_PARAMS  <typename T, typename TP1>
	#define T_TEMPLATE_ARGS    <T, TP1>
	#define PARAMS       TP1 p1
	#define ARGS         p1
	#define TYPENAME     typename

	#include "DelegateImplement.h"

	#define SUFFIX       2
	#define TEMPLATE	template
	#define TEMPLATE_PARAMS  <typename TP1, typename TP2>
	#define TEMPLATE_ARGS    <TP1, TP2>
	#define T_TEMPLATE_PARAMS  <typename T, typename TP1, typename TP2>
	#define T_TEMPLATE_ARGS    <T, TP1, TP2>
	#define PARAMS       TP1 p1, TP2 p2
	#define ARGS         p1, p2
	#define TYPENAME     typename

	#include "DelegateImplement.h"

	#define SUFFIX       3
	#define TEMPLATE	template
	#define TEMPLATE_PARAMS  <typename TP1, typename TP2, typename TP3>
	#define TEMPLATE_ARGS    <TP1, TP2, TP3>
	#define T_TEMPLATE_PARAMS  <typename T, typename TP1, typename TP2, typename TP3>
	#define T_TEMPLATE_ARGS    <T, TP1, TP2, TP3>
	#define PARAMS       TP1 p1, TP2 p2, TP3 p3
	#define ARGS         p1, p2, p3
	#define TYPENAME     typename

	#include "DelegateImplement.h"

	#define SUFFIX       4
	#define TEMPLATE	template
	#define TEMPLATE_PARAMS  <typename TP1, typename TP2, typename TP3, typename TP4>
	#define TEMPLATE_ARGS    <TP1, TP2, TP3, TP4>
	#define T_TEMPLATE_PARAMS  <typename T, typename TP1, typename TP2, typename TP3, typename TP4>
	#define T_TEMPLATE_ARGS    <T, TP1, TP2, TP3, TP4>
	#define PARAMS       TP1 p1, TP2 p2, TP3 p3, TP4 p4
	#define ARGS         p1, p2, p3, p4
	#define TYPENAME     typename

	#include "DelegateImplement.h"

	#define SUFFIX       5
	#define TEMPLATE	template
	#define TEMPLATE_PARAMS  <typename TP1, typename TP2, typename TP3, typename TP4, typename TP5>
	#define TEMPLATE_ARGS    <TP1, TP2, TP3, TP4, TP5>
	#define T_TEMPLATE_PARAMS  <typename T, typename TP1, typename TP2, typename TP3, typename TP4, typename TP5>
	#define T_TEMPLATE_ARGS    <T, TP1, TP2, TP3, TP4, TP5>
	#define PARAMS       TP1 p1, TP2 p2, TP3 p3, TP4 p4, TP5 p5
	#define ARGS         p1, p2, p3, p4, p5
	#define TYPENAME     typename

	#include "DelegateImplement.h"


} // namespace GUI

#endif // __DELEGATE_H__

