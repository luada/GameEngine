
#ifndef BOOST_MPL_LIST_AUX_POP_FRONT_HPP_INCLUDED
#define BOOST_MPL_LIST_AUX_POP_FRONT_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Source: E:/ProgramSource/EngineSDK/EngineSDK/ThirdParty/VSInclude/boost/mpl/list/aux_/pop_front.hpp,v $
// $Date: 2007/11/27 07:29:45 $
// $Revision: 1.1 $

#include <boost/mpl/pop_front_fwd.hpp>
#include <boost/mpl/next_prior.hpp>
#include <boost/mpl/list/aux_/tag.hpp>

namespace boost { namespace mpl {

template<>
struct pop_front_impl< aux::list_tag >
{
    template< typename List > struct apply
    {
        typedef typename mpl::next<List>::type type;
    };
};

}}

#endif // BOOST_MPL_LIST_AUX_POP_FRONT_HPP_INCLUDED