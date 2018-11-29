#ifndef __EVENT_PAIR_H__
#define __EVENT_PAIR_H__

#include "Prerequest.h"

namespace GUI
{

	template <typename EventObsolete, typename Event>
	class EventPair
	{
	public:

		template <typename T>
		OBSOLETE("use : signature : Event::IDelegate * delegate")
		void operator = (T * delegate)
		{
			m_eventObsolete = delegate;
			m_event = nullptr;
		}

		void operator = (typename Event::IDelegate * delegate)
		{
			m_eventObsolete = nullptr;
			m_event = delegate;
		}

		template <typename TP1>
		void operator()(TP1 p1)
		{
			m_eventObsolete(p1);
			m_event(p1);
		}

		template <typename TP1, typename TP2>
		void operator()(TP1 p1, TP2 p2)
		{
			m_eventObsolete(p1, p2);
			m_event(p1, p2);
		}

		template <typename TP1, typename TP2, typename TP3>
		void operator()(TP1 p1, TP2 p2, TP3 p3)
		{
			m_eventObsolete(p1, p2, p3);
			m_event(p1, p2, p3);
		}

		template <typename TP1, typename TP2, typename TP3, typename TP4>
		void operator()(TP1 p1, TP2 p2, TP3 p3, TP4 p4)
		{
			m_eventObsolete(p1, p2, p3, p4);
			m_event(p1, p2, p3, p4);
		}

		template <typename TP1, typename TP2, typename TP3, typename TP4, typename TP5>
		void operator()(TP1 p1, TP2 p2, TP3 p3, TP4 p4, TP5 p5)
		{
			m_eventObsolete(p1, p2, p3, p4, p5);
			m_event(p1, p2, p3, p4, p5);
		}

		template <typename TP1, typename TP2, typename TP3, typename TP4, typename TP5, typename TP6>
		void operator()(TP1 p1, TP2 p2, TP3 p3, TP4 p4, TP5 p5, TP6 p6)
		{
			m_eventObsolete(p1, p2, p3, p4, p5, p6);
			m_event(p1, p2, p3, p4, p5, p6);
		}

		template <typename TP1, typename TP2, typename TP3, typename TP4, typename TP5, typename TP6, typename TP7>
		void operator()(TP1 p1, TP2 p2, TP3 p3, TP4 p4, TP5 p5, TP6 p6, TP7 p7)
		{
			m_eventObsolete(p1, p2, p3, p4, p5, p6, p7);
			m_event(p1, p2, p3, p4, p5, p6, p7);
		}

		template <typename TP1, typename TP2, typename TP3, typename TP4, typename TP5, typename TP6, typename TP7, typename TP8>
		void operator()(TP1 p1, TP2 p2, TP3 p3, TP4 p4, TP5 p5, TP6 p6, TP7 p7, TP8 p8)
		{
			m_eventObsolete(p1, p2, p3, p4, p5, p6, p7, p8);
			m_event(p1, p2, p3, p4, p5, p6, p7, p8);
		}

		bool empty() const
		{
			return m_eventObsolete.empty() && m_event.empty();
		}

	public:
		EventObsolete m_eventObsolete;
		Event m_event;
	};

} // namespace GUI

#endif // __EVENT_PAIR_H__
