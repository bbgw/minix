//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <queue>

// queue(queue&& q);

#include <queue>
#include <cassert>

#include "../../../MoveOnly.h"

#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES

template <class C>
C
make(int n)
{
    C c;
    for (int i = 0; i < n; ++i)
        c.push_back(MoveOnly(i));
    return c;
}

#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES

int main()
{
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    std::queue<MoveOnly> q(make<std::deque<MoveOnly> >(5));
    std::queue<MoveOnly> q2 = std::move(q);
    assert(q2.size() == 5);
    assert(q.empty());
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
}
