
#ifndef BOOST_MPL_SET_AUX_ITERATOR_HPP_INCLUDED
#define BOOST_MPL_SET_AUX_ITERATOR_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Source: E:/ProgramSource/EngineSDK/EngineSDK/ThirdParty/VSInclude/boost/mpl/set/aux_/iterator.hpp,v $
// $Date: 2007/11/27 07:29:54 $
// $Revision: 1.1 $

#include <boost/mpl/set/aux_/set0.hpp>
#include <boost/mpl/has_key.hpp>
#include <boost/mpl/iterator_tags.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/aux_/config/ctps.hpp>

namespace boost { namespace mpl {

// used by 's_iter_impl'
template< typename Set, typename Tail > struct s_iter;

template< typename Set, typename Tail > struct s_iter_impl
{
    typedef Tail                        tail_;
    typedef forward_iterator_tag        category;
    typedef typename Tail::item_::type  type;

#if defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
    typedef typename eval_if< 
          has_key< Set,typename Tail::next_::type >
        , identity< s_iter<Set,typename Tail::next_> >
        , next< s_iter<Set,typename Tail::next_> >
        >::type next;        
#endif
};

#if !defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template< typename Set, typename Tail > 
struct next< s_iter<Set,Tail> >
    : eval_if< 
          has_key< Set,typename Tail::next_::type >
        , identity< s_iter<Set,typename Tail::next_> >
        , next< s_iter<Set,typename Tail::next_> >
        >
{
};

template< typename Set > 
struct next< s_iter<Set,set0<> > >
{
    typedef s_iter<Set,set0<> > type;
};

template< typename Set, typename Tail > struct s_iter
    : s_iter_impl<Set,Tail>
{
};

template< typename Set > struct s_iter<Set, set0<> >
{
    typedef forward_iterator_tag category;
};

#else

template< typename Set >
struct s_end_iter
{
    typedef forward_iterator_tag    category;
    typedef s_iter<Set,set0<> >     next;
};

template< typename Set, typename Tail > struct s_iter
    : if_< 
          is_same< Tail,set0<> >
        , s_end_iter<Set>
        , s_iter_impl<Set,Tail>
        >::type
{
};

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

}}

#endif // BOOST_MPL_SET_AUX_ITERATOR_HPP_INCLUDED
